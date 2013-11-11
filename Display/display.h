#ifndef DISPLAY_H
#define DISPLAY_H

#include <cstdint>
#include <string>

#define RS_PIN 	0
#define RW_PIN 	1
#define E_PIN	2
#define LIGHT_PIN 3

#define SET_PIN(pin) (1 << pin)
#define CLEAR_PIN(pin) (~pin)

#define COMMAND_MODE 0
#define DATA_MODE SET_PIN(RS_PIN)
// D4 - D7 = P4 - P7

//----- Define commands 
#define CLEAR_DISPLAY 		0x01 // execution time 
#define RETURN_HOME 		0x02 // execution time 1.52ms
#define ENTRY_MODE_SET 		0x04 // execution time 37us
#define DISPLAY_CONTROL		0x08 // execution time 37us
#define CURSOR_DISPLAY_SHIFT 	0x10 // execution time 37us
#define FUNCTION_SET 		0x20 // execution time 37us
#define SET_CGRAM_ADD 		0x40 // execution time 37us
#define SET_DDRAM_ADD		0x80 // execution time 37us

enum DisplayMode{
	commandMode = COMMAND_MODE,
	dataMode = DATA_MODE
};

class Display{
	int i2cDevice;
	int displayAdress;
	bool backlight;

	bool writeI2C(uint8_t data);
	// mode represent register select and rw state
	// data is 4bit part of command which are send to display
	bool writeDisplay4bit(uint8_t data, DisplayMode mode);
	bool writeDisplay(uint8_t data, DisplayMode mode);
	bool writeChar(char character);
public:
	bool init();
	bool clearDisplay();
	bool returnHome();
	// increment = false -> decrement 
	bool entryModeSet(bool increment, bool shift);
	bool displayControl(bool displayOn, bool cursorOn, bool blinkOn);
	// display = false -> cursor shift, right = false -> left shift
	bool cursorDisplayShift(bool display, bool right);
	bool functionSet(bool interface8bit, bool twoLines, bool largerFont);
	unsigned int writeText(std::string text);
	//bool setCGRAMAdress();
	//bool setDDRAMADress();
	Display(std::string I2CName);
};

#endif
