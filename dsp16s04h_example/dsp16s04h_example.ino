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

char input = 0;

void setup() {
  Serial.begin(115200);
  Serial.println("DSP16S04H test");
  Wire.begin();
  dsp16s04h.init();
  delay(500);
  dsp16s04h.clearDisplay();
}

void loop() {
  if (Serial.available()) {
    input = Serial.read();
    if (input == '1') {
      Serial.println("Test toggle");
      dsp16s04h.test();
    }
    else if (input == '2') {
      Serial.println("clear");
      dsp16s04h.clearDisplay();
    }
    else if (input == '3') {
      Serial.println("clear");
      dsp16s04h.print("1234");
    }
    else if (input == '4') {
      Serial.println("raw");
      dsp16s04h.putRaw(0xFFFF);
    }
    else if (input == '5') {
      Serial.println("dot");
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
    }
    else if (input == '6') {
      Serial.println("brightness");
      dsp16s04h.putRaw(0xffff);
      dsp16s04h.putRaw(0xffff);
      dsp16s04h.putRaw(0xffff);
      dsp16s04h.putRaw(0xffff);
      for (uns8 i = 0; i < 0xFF; i++) {
        dsp16s04h.setBrightness(i);
        delay(250);
      }
    }
  }
}
