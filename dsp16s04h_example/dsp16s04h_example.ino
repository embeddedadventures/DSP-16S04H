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

// DSP-16S04H 16-segment 4-digit LED display Arduino test sketch
// Written originally by Embedded Adventures

#include <Wire.h>
#include <DSP16S04H.h>

//#define USING_SAMD21

#ifdef USING_SAMD21
	#define SERIAL	SerialUSB
#else
	#define SERIAL 	Serial
#endif

void setup() {
  SERIAL.begin(115200);
  while (!SERIAL) {	}
  SERIAL.println("Welcome to the Embedded Adventures test sketch for the DSP-16S04H display");
  SERIAL.println("(www.embeddedadventures.com)");
  dsp16s04h.init();
  delay(500);
  dsp16s04h.clearDisplay();
}

void loop() {
  SERIAL.println("Printing 1234");
  dsp16s04h.print("1234");
  delay(1000);
  dsp16s04h.clearDisplay();
  delay(1000);
  
  SERIAL.println("dot");
  dsp16s04h.setDot(0);
  delay(250);
  dsp16s04h.setDot(1);
  delay(250);
  dsp16s04h.setDot(2);
  delay(250);
  dsp16s04h.setDot(3);
  delay(250);
  dsp16s04h.clearDot(0);
  delay(250);
  dsp16s04h.clearDot(1);
  delay(250);
  dsp16s04h.clearDot(2);
  delay(250);
  dsp16s04h.clearDot(3);
  
  dsp16s04h.clearDisplay();
  delay(500);
  
  SERIAL.println("raw and brightness");
  dsp16s04h.putRaw(0xFFF0);
  delay(250);
  dsp16s04h.putRaw(0xFF0F);
  delay(250);
  dsp16s04h.putRaw(0xF0FF);
  delay(250);
  dsp16s04h.putRaw(0xFFFF);
  delay(250);
  for (uns8 i = 1; i < 0xFF; i++) {
	dsp16s04h.setBrightness(i);
	delay(50);
  }
  dsp16s04h.clearDisplay();
  delay(500);
}
