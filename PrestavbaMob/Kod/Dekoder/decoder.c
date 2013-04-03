/*
 *  decoder.c
 *
 *  Created: 2/13/2013 9:58:26 AM
 *  Author: Ondrap
 */ 


#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/eeprom.h>
#include <util/atomic.h>

#include "TWI_slave.h"
#include "decoder.h"

// define default address for slave device
#define DEFAULT_ADDRESS 0x30
// define commands codes
#define SET_ADDRESS 1 
#define SET_ENCODERS 2
#define SEND_ENCODERS 10

// decode array for quadrature signal
static uint8_t encoderStateTable[4][2] = {
	{1,2},
	{3,0},
	{0,3},
	{2,1},		
};

uint8_t EEMEM TWI_SlaveAddressEEPROM = DEFAULT_ADDRESS; //set on default address
volatile struct encoders encodersState;

//last quadrature state
uint8_t lastLeftState;
uint8_t lastRightState;

// Update I2C address in internal eeprom memory
void setTWIAddress(uint8_t Address){
	if(Address > 127)
		Address = Address >> 1;	
	
	eeprom_write_byte(&TWI_SlaveAddressEEPROM, Address);
}

uint8_t readTWIAddress(){
	return eeprom_read_byte(&TWI_SlaveAddressEEPROM);
}

void setEncodersValue(uint16_t Value){
	ATOMIC_BLOCK(ATOMIC_RESTORESTATE){
		encodersState.left.value = Value;
		encodersState.right.value = Value;
	}		
}

void setInputInterruptForDecoder(){
	// set interrupt pin as input with pull up 
	PORTC |= (1 << PC1) | (1 << PC0);
	DDRC &= ~((1 << PC1) | (1 << PC0));
	
	PORTD |= (1 << PD1) | (1 << PD0);
	DDRD &= ~((1 << PD1) | (1 << PD0));
	
	// Insert nop for synchronization
	asm volatile ("NOP"::);
	
	// read initial state of decoder
	lastLeftState = PINC & 3;
	lastRightState = PIND & 3;
	
	// enable interrupt 
	PCICR = (1 << PCIE2) | (1 << PCIE1); // use change interrupt PCIE1,2
	PCMSK1 = (1 << PCINT9) | (1 << PCINT8); // enable interrupt on PCINT8,9
	PCMSK2 = (1 << PCINT17) | (1 << PCINT16); // enable interrupt on PCINT16,17
}

ISR(PCINT1_vect){
	uint8_t leftState = PINC & 3;
	
	if(encoderStateTable[lastLeftState][1] == leftState){ // Left wheel had switch second part of array because had opposite direction
		encodersState.left.value = encodersState.left.value + 1;
		//TEST
		PORTD ^=  (1 << PD5);
	}else{
		if(encoderStateTable[lastLeftState][0] == leftState){
			encodersState.left.value = encodersState.left.value - 1;
			//TEST
			PORTD ^=  (1 << PD6);
		}
		//else{
			//PORTD ^= (1 << PD7); // TODO: error 
		//}
	}			
			
	lastLeftState = leftState;
}

ISR(PCINT2_vect){
	uint8_t rightState = PIND & 3;
	
	if(encoderStateTable[lastRightState][0] == rightState){
		encodersState.right.value = encodersState.right.value + 1;
		//TEST
		PORTB ^=  (1 << PB0);
	}		
	else{
		if(encoderStateTable[lastRightState][1] == rightState){
			encodersState.right.value = encodersState.right.value - 1;
			//TEST
			PORTB ^=  (1 << PB1);
		}
		//else{
			//PORTB ^= (1 << PB2); 
			// TODO: error
		//}			
	}			
	
	lastRightState = rightState;
}

int main(void)
{
	unsigned char messageBuf[TWI_BUFFER_SIZE];
	//setEncodersValue(32767);
	setEncodersValue(127);
	
	// set output ports for diodes
	DDRD |= (1 << PD5) | (1 << PD6) | (1 << PD7);
	PORTD |= (1 << PD5) | (1 << PD6);
	DDRB |= (1 << PB0) | (1 << PB1) | (1 << PB2);
	PORTB |= (1 << PB0) | (1 << PB1);
	
	setInputInterruptForDecoder();
	
	uint8_t TWI_SlaveAddress;
	//TWI_SlaveAddress = readTWIAddress();
	TWI_SlaveAddress = DEFAULT_ADDRESS;
	
	// Initialize TWI module for slave operation. Include address and/or enable General Call.
	TWI_Slave_Initialise( (TWI_SlaveAddress<<TWI_ADR_BITS) | (TRUE<<TWI_GEN_BIT));
	
	// Enable interrupt
	sei();
	
	// Start the TWI transceiver to enable reception of the first command from the TWI Master.
	TWI_Start_Transceiver();
	
	// Never ending loop witch read from I2C and response on command.
	while(TRUE){
		if(!TWI_Transceiver_Busy()){
			if(TWI_statusReg.lastTransOK){
				if(TWI_statusReg.RxDataInBuf){
					// get command code
					PORTB ^= (1 << PB2);
					TWI_Get_Data_From_Transceiver(messageBuf, 1);
					PORTB ^= (1 << PB2);
				
					switch(messageBuf[0]){
						case SEND_ENCODERS:{
							PORTD ^= (1 << PD7);
							struct encoders tempEncodersState;
							ATOMIC_BLOCK(ATOMIC_FORCEON){
								tempEncodersState = encodersState;
							}
						
							messageBuf[0] = tempEncodersState.left.bytes[0];
							messageBuf[1] = tempEncodersState.left.bytes[1];
							messageBuf[2] = tempEncodersState.right.bytes[0];
							messageBuf[3] = tempEncodersState.right.bytes[1];
						
							TWI_Start_Transceiver_With_Data(messageBuf, 4);
							PORTD ^= (1 << PD7);
							break;
						}
						default:
							break;
					}				
				}
			}else{
				TWI_Start_Transceiver();
			}			
		}else{
			asm volatile ("NOP"::);  // Do something else while waiting
		}			
	}
}