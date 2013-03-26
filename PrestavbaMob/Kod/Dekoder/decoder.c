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
#define DEFAULT_ADRESS 0x30

// decode array for quadrature signal
static uint8_t encoderState[4][2] = {
	{1,2},
	{3,0},
	{0,3},
	{2,1},		
	};

uint8_t EEMEM TWI_SlaveAddressEEPROM = DEFAULT_ADRESS; //set on default address
volatile struct encoders encodersValue;

//last quadrature state
uint8_t lastLeftState;
uint8_t lastRightState;

// Update I2C address in internal eeprom memory
void setTWIAddress(uint8_t Address){
	eeprom_write_byte(&TWI_SlaveAddressEEPROM, Address);
}

uint8_t readTWIAddress(){
	return eeprom_read_byte(&TWI_SlaveAddressEEPROM);
}

void setEncodersValue(volatile struct encoders *EncodersValue, uint16_t Value){
	ATOMIC_BLOCK(ATOMIC_RESTORESTATE){
		EncodersValue->left.value = Value;
		EncodersValue->right.value = Value;
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
	
	if(encoderState[lastLeftState][1] == leftState){ // Left wheel had switch second part of array because had opposite direction
		++encodersValue.left.value;
		//TEST
		PORTD ^=  (1 << PD5);
	}		
	else
		if(encoderState[lastLeftState][0] == leftState){
			--encodersValue.left.value;
			//TEST
			PORTD ^=  (1 << PD6);
		}			
		else
			; // TODO: error 
			
	lastLeftState = leftState;
}

ISR(PCINT2_vect){
	uint8_t rightState = PIND & 3;
	
	if(encoderState[lastRightState][0] == rightState){
		++encodersValue.right.value;
		//TEST
		PORTD ^=  (1 << PD5);
	}		
	else
		if(encoderState[lastRightState][1] == rightState){
			--encodersValue.right.value;
			//TEST
			PORTD ^=  (1 << PD6);
		}			
		else
			; // TODO: error
	
	lastRightState = rightState;
}

int main(void)
{
	unsigned char messageBuf[TWI_BUFFER_SIZE];
	setEncodersValue(&encodersValue,32767);
	// TEST counter
	DDRD |= (1 << PD5) | (1 << PD6);
	PORTD |= (1 << PD5) | (1 << PD6);
	// END TEST counter
	
	setInputInterruptForDecoder();
	
	uint8_t TWI_SlaveAddress;
	//TWI_SlaveAddress = readTWIAddress();
	TWI_SlaveAddress = 0x30;
	
	// Initialize TWI module for slave operation. Include address and/or enable General Call.
	TWI_Slave_Initialise( (TWI_SlaveAddress<<TWI_ADR_BITS) | (TRUE<<TWI_GEN_BIT));
	
	// Enable interrupt
	sei();
	
	// Start the TWI transceiver to enable reception of the first command from the TWI Master.
	TWI_Start_Transceiver();
	
	// Never ending loop witch read from I2C and response on command.
	for(;;){
		if ( ! TWI_Transceiver_Busy() )
		{
			if ( TWI_statusReg.RxDataInBuf )
			{
				TWI_Get_Data_From_Transceiver(messageBuf, 1);
				// 0..9 for setting command
				// 10..19 for sending data
				switch(messageBuf[0]){
					case 0:
						setEncodersValue(&encodersValue,0);
						break;
					case 1:
						setEncodersValue(&encodersValue,32767);
						break;
					case 2: // change I2c address
						if(messageBuf[1] == messageBuf[2]){
							setTWIAddress(messageBuf[1]);
							messageBuf[0] = 0;
						}else{
							messageBuf[0] = 1; // received address not match
						}
						TWI_Start_Transceiver_With_Data(messageBuf,1);
						break;
					case 10: // send encoder data
					{
						struct encoders encodersValueCopy;
						ATOMIC_BLOCK(ATOMIC_FORCEON){
							encodersValueCopy.left.value = encodersValue.left.value;
							encodersValueCopy.right.value = encodersValue.right.value;
						}
						messageBuf[0] = encodersValueCopy.left.bytes[0];
						messageBuf[1] = encodersValueCopy.left.bytes[1];
						messageBuf[2] = encodersValueCopy.right.bytes[0];
						messageBuf[3] = encodersValueCopy.right.bytes[1];
						TWI_Start_Transceiver_With_Data(messageBuf,4);
						break;
					}
					default:
						break;						
				}
			}
		}
		asm volatile ("NOP"::);  // Do something else while waiting
	}
}