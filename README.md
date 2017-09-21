# DSP-16S04H

A great Arduino library to communicate with the [DSP-16S04H 16 segment 4 digit 2.3" display](http://www.embeddedadventures.com/4_digit_16_segment_led_display_dsp-16s04h-red.html) from Embedded Adventures

## Using the library ##

The Arduino sample sketches show the minimum functions necessary to drive the DSP-16S04H display.

The first function to call, which clears the data buffers and starts the I2C bus.

	dsp16s04h.init();

### First test ###

A test function is included in the display's firmware. This can be executed using the function, which will toggle the test_mode flag in the display's firmware.

	void test();

### Driving segments on the display ###

Print up to 4 characters on the display

	void print(char *str)
	void print(String str)

Drive the segments individually. Adds the 16-bit raw data to the data_buffer in the library (digits shifted from left to right) and sends it to the firmware to display. Check the datasheet for the mapping of bits to segments.

	void putRaw(uns16 data)


Turn on/off the dot at position *position*

	void setDot(uns8 position);
	void clearDot(uns8 position);

To adjust the display brightness
	
	void setBrightness(uns8 level)

Clear the display and turn off all segments

	void clearDisplay();

## Tested with the following boards ##
- <a href="http://www.embeddedadventures.com/arduno_uno_PLT-AUNO.html">Arduino Uno</a>/<a href="http://www.embeddedadventures.com/arduno_uno_plt-auno3-cm.html">compatible</a>
	- I2C (A4/A5)
- ESP8266 Module (<a href="http://www.embeddedadventures.com/esp8266_wifi_module_wrl-esp7.html">ESP7</a> and <a href="http://www.embeddedadventures.com/esp8266_wifi_module_wrl-esp12e.html">ESP12</a>)
	- I2C (IO4/IO5)
- <a href="http://www.embeddedadventures.com/esp32_development_platform_PLT-ESP32-01.html">ESP32 Module</a>
	- I2C (IO21/IO22)

## To Do List ##
- SAMD21-based board compatibility
- include UART Serial interface


### NOTE - Firmware update
A bug has been found in the older displays in which an "8" was not being displayed correctly. The hex file included in this repository is an updated version of the firmware with that bug fixed. Please click [here](http://www.embeddedadventures.com/Tutorials/tutorials_detail/203) to download the Screamer bootloader, which is used for updating the firmware on your display if it exhibits the behavior. Follow the steps below to update the firmware. Besides the Screamer bootloader, you will also need a USB-TTL Serial cable to connect between your computer and the DSP16S04H.

1. Open the Screamer bootloader and change the "Comm:" to the COM port your USB-TTL Serial cable is connected to. This can be found by checking "Device Manager"
2. Make sure speed is set to "115200" and Oscillator is set to "48"
3. Click on "Open" and find the firmware hex file in this repository. 
4. Download the firmware to the DSP16S04H.

