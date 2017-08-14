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

#ifndef __DSP16S04H_h
#define __DSP16S04H_h

#include "Arduino.h"
#include "Wire.h"

#ifndef		uns8	
	#define uns8	uint8_t
#endif
#ifndef		uns16
	#define uns16	uint16_t
#endif

#define DSP16S04H_I2C_ADDR		0x32

#define CMD_TEST		0x00
#define CMD_PRINT_STR	0x01
#define CMD_PUT_RAW		0x02
#define CMD_SET_DOT		0x03
#define CMD_CLEAR_DOT	0x03
#define CMD_BRIGHTNESS	0x06
#define CMD_CLEAR_DISP	0x05

class DSP16S04HClass {
private:
	uns8 data[4] = {0};
	uns16 raw_data[4] = {0};
	inline void	clear_data();
	inline void write_command(uns8 cmd, uns8 arg1, uns8 arg2, uns8 arg3, uns8 arg4, uns8 arg5);
	inline void write_command(uns8 cmd, uns8 arg1, uns8 arg2, uns8 arg3);
	inline void write_command(uns8 cmd, uns8 arg1, uns8 arg2);
	inline void write_command(uns8 cmd, uns8 arg1);
	inline void write_command(uns8 cmd, uns8 arg1, uns8 arg2, uns8 arg3, uns8 arg4); 
public:
	void 	init();
	void	test();
	void	print(String str);
	void	print(const char *str);
	void	putRaw(uns16 raw_data);
	void	setDot(uns8 position);
	void	clearDot(uns8 position);
	void	setBrightness(uns8 bright);
	void	clearDisplay();
};

extern DSP16S04HClass dsp16s04h;


#endif