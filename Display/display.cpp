#include "display.h"

#include <cstdio>
#include <cstdlib>

#include <sys/ioctl.h>
#include <sys/time.h>
#include <fcntl.h>
#include <linux/i2c-dev.h>

Display::Display(std::string I2CName){
	if((i2cDevice = open(I2CName.c_str(),O_RDWR)) < 0){
		printf("Failed to open i2c bus\n");
		exit(1);
	}
	
	displayAdress = 0x3f;
	backlight = false;
	ioctl(i2cDevice,I2C_SLAVE,displayAdress);	
}

bool Display::writeI2C(uint8_t data){
	if(write(i2cDevice,&data,1) != 1){
		printf("Cannot write to i2c bus\n");
		return false;
	}

	return true;
}

bool Display::writeDisplay4bit(uint8_t data, DisplayMode mode){
	uint8_t sendByte = (data << 4) | (mode & 0x0f);
	//printf("SendByte %x \n",sendByte);
	if(backlight){
		sendByte |= SET_PIN(LIGHT_PIN);
	}

	if(!writeI2C(sendByte | SET_PIN(E_PIN))) {
		return false;
	}

	if(!writeI2C(sendByte)){
		return false;
	}

	return true;
}

bool Display::writeDisplay(uint8_t data, DisplayMode mode){
	if(!writeDisplay4bit(data >> 4,mode)){
		return false;
	}	

	if(!writeDisplay4bit(data & 0x0f,mode)){
		return false;
	}

	return true;
}

bool Display::writeChar(char character){
	bool result = writeDisplay(character,dataMode);
	return result;
}

bool Display::init(){
	if(!writeDisplay4bit(0x03, commandMode))
		return false;
	usleep(4300);
	if(!writeDisplay4bit(0x03, commandMode))
		return false;
	usleep(200);
	if(!writeDisplay4bit(0x03, commandMode))
		return false;
	usleep(200);	
	if(!writeDisplay4bit(0x02, commandMode))
		return false;
	usleep(200);
	// now display is set to 4bit interface and backlight is turn on

	functionSet(false,true,false);
	displayControl(false,false,false);
	clearDisplay();
	entryModeSet(true,false);	
	// inicialization end now we can turn on display

	backlight = true;		
	displayControl(true,false,false);
	
	return true;	
}

bool Display::clearDisplay(){
	bool result = writeDisplay(CLEAR_DISPLAY, commandMode);
	usleep(200);
	return result;
}

bool Display::returnHome(){
	bool result = writeDisplay(RETURN_HOME, commandMode);
	usleep(2000);
	return result;
}

bool Display::entryModeSet(bool increment, bool shift){
	uint8_t data = ENTRY_MODE_SET;
	if(increment){
		data |= SET_PIN(1);
	}

	if(shift){
		data |= SET_PIN(0);
	}
	
	return writeDisplay(data,commandMode);
}

bool Display::displayControl(bool displayOn, bool cursorOn, bool blinkOn){
	uint8_t data = DISPLAY_CONTROL;
	if(displayOn){
		data |= SET_PIN(2);
	}

	if(cursorOn){
		data |= SET_PIN(1);
	}

	if(cursorOn){
		data |= SET_PIN(0);
	}

	return writeDisplay(data,commandMode);
}

bool Display::cursorDisplayShift(bool display, bool right){
	uint8_t data = CURSOR_DISPLAY_SHIFT;
	if(display){
		data |= SET_PIN(3);
	}

	if(right){
		data |= SET_PIN(2);
	}

	return writeDisplay(data,commandMode);
}

bool Display::functionSet(bool interface8bit, bool twoLines, bool largerFont){
	uint8_t data = FUNCTION_SET;
	if(interface8bit){
		data |= SET_PIN(4);
	}	

	if(twoLines){
		data |= SET_PIN(3);
	}

	if(largerFont){
		data |= SET_PIN(2);
	}

	return writeDisplay(data,commandMode);
}

unsigned int Display::writeText(std::string text){
	unsigned int index = 0;	
	for(index=0; index < text.size(); ++index){
		if(!writeChar(text[index]))
			break;
	}	

	return index;
}

int main(){
	Display display("/dev/i2c-1");	
	
	display.init();
	std::string text = "     Jmenuji se     ";
	display.writeText(text);
	std::string text2 = "         Mob       ";
	display.writeText(text2);

	return 0;
}
