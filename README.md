# DSP-16S04H

4-digit 16 segment red LED display 

A great Arduino library to communicate with the [DSP-16S04H 16 segment 4 digit 2.3" display](http://www.embeddedadventures.com/4_digit_16_segment_led_display_dsp-16s04h-red.html) from Embedded Adventures


###NOTE - Firmware update
A bug has been found in the older displays in which an "8" was not being displayed correctly. The hex file included in this repository is an updated version of the firmware with that bug fixed. Please click [here](http://www.embeddedadventures.com/Tutorials/tutorials_detail/203) to download the Screamer bootloader, which is used for updating the firmware on your display if it exhibits the behavior. Follow the steps below to update the firmware. Besides the Screamer bootloader, you will also need a USB-TTL Serial cable to connect between your computer and the DSP16S04H.

1. Open the Screamer bootloader and change the "Comm:" to the COM port your USB-TTL Serial cable is connected to. This can be found by checking "Device Manager"
2. Make sure speed is set to "115200" and Oscillator is set to "48"
3. Click on "Open" and find the firmware hex file in this repository. 
4. Download the firmware to the DSP16S04H.

