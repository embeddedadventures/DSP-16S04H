/*

Copyright (c) 2017, Embedded Adventures
All rights reserved.

Contact us at source [at] embeddedadventures.com
www.embeddedadventures.com

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

- Redistributions of source code must retain the above copyright notice,
  this list of conditions and the following disclaimer.

- Redistributions in binary form must reproduce the above copyright
  notice, this list of conditions and the following disclaimer in the
  documentation and/or other materials provided with the distribution.

- Neither the name of Embedded Adventures nor the names of its contributors
  may be used to endorse or promote products derived from this software
  without specific prior written permission.
 
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF 
THE POSSIBILITY OF SUCH DAMAGE.

*/

// DSP-16S04H 16-segment 4-digit LED display Arduino library
// Written originally by Embedded Adventures

#include "DSP16S04H.h"
#include "Wire.h"

void DSP16S04HClass::clear_data() {
	data[0] = 0;
	data[1] = 0;
	data[2] = 0;
	data[3] = 0;
}

void DSP16S04HClass::write_command(uns8 cmd, uns8 arg1, uns8 arg2, uns8 arg3, uns8 arg4, uns8 arg5) {
	Wire.beginTransmission(DSP16S04H_I2C_ADDR);
	Wire.write(cmd);
	Wire.write(arg1);
	Wire.write(arg2);
	Wire.write(arg3);
	Wire.write(arg4);
	Wire.write(arg5);
	Wire.endTransmission();
	clear_data();
}

void DSP16S04HClass::write_command(uns8 cmd, uns8 arg1, uns8 arg2, uns8 arg3, uns8 arg4) {
	Wire.beginTransmission(DSP16S04H_I2C_ADDR);
	Wire.write(cmd);
	Wire.write(arg1);
	Wire.write(arg2);
	Wire.write(arg3);
	Wire.write(arg4);
	Wire.endTransmission();

}

void DSP16S04HClass::write_command(uns8 cmd, uns8 arg1, uns8 arg2, uns8 arg3) {
	Wire.beginTransmission(DSP16S04H_I2C_ADDR);
	Wire.write(cmd);
	Wire.write(arg1);
	Wire.write(arg2);
	Wire.write(arg3);
	Wire.endTransmission();
	
}

void DSP16S04HClass::write_command(uns8 cmd, uns8 arg1, uns8 arg2) {
	Wire.beginTransmission(DSP16S04H_I2C_ADDR);
	Wire.write(cmd);
	Wire.write(arg1);
	Wire.write(arg2);
	Wire.endTransmission();
	
}

void DSP16S04HClass::write_command(uns8 cmd, uns8 arg1) {
	Wire.beginTransmission(DSP16S04H_I2C_ADDR);
	Wire.write(cmd);
	Wire.write(arg1);
	Wire.endTransmission();
}

void DSP16S04HClass::init() {
	clear_data();
	Wire.begin();
	write_command(CMD_BRIGHTNESS, 0xFF);
}

void DSP16S04HClass::clearDisplay() {
	Wire.beginTransmission(DSP16S04H_I2C_ADDR);
	Wire.write(CMD_CLEAR_DISP);
	Wire.endTransmission();
}

void DSP16S04HClass::print(String str) {
	print(str.c_str());
}

void DSP16S04HClass::print(const char *str) {
	uns8 x = 0;
	while ((x < 4) && (*str)) {
		data[x] = str[x];
		x++;
	}
	write_command(CMD_PRINT_STR, data[0], data[1], data[2], data[3]);
}

//Shifts raw data into raw_data buffer at index 0 (from left-most to right-most)
void DSP16S04HClass::putRaw(uns16 rawData) {
	raw_data[0] = raw_data[1];
	raw_data[1] = raw_data[2];
	raw_data[2] = raw_data[3];
	raw_data[3] = rawData;
	Wire.beginTransmission(DSP16S04H_I2C_ADDR);
	Wire.write(CMD_PUT_RAW);
	Wire.write(raw_data[3] >> 8);
	Wire.write(raw_data[3] & 0xFF);
	Wire.write(raw_data[2] >> 8);
	Wire.write(raw_data[2] & 0xFF);
	Wire.write(raw_data[1] >> 8);
	Wire.write(raw_data[1] & 0xFF);
	Wire.write(raw_data[0] >> 8);
	Wire.write(raw_data[0] & 0xFF);
	Wire.endTransmission();
}

void DSP16S04HClass::setDot(uns8 position) {
	write_command(CMD_SET_DOT, position, 0x01);
}

void DSP16S04HClass::clearDot(uns8 position) {
	write_command(CMD_CLEAR_DOT, position, 0x00);
}

void DSP16S04HClass::setBrightness(uns8 bright) {
	write_command(CMD_BRIGHTNESS, bright);
}

void DSP16S04HClass::test() {
	static uns8 test = 0;
	Wire.beginTransmission(DSP16S04H_I2C_ADDR);
	Wire.write(CMD_TEST);
	Wire.write(test);
	test = test ^ 0x01;
	Wire.endTransmission();
}

DSP16S04HClass dsp16s04h;