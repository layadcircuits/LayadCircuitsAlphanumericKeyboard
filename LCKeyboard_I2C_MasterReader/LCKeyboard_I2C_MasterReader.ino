/***************************************************************************
 Example code to read keys from the Layad Circuits Alphanumeric Keyboard Module.
 Upload this code to an Arduino (I2C master).
 Connect the SDA, SCL, and GND pins of the Arduino to the corresponding pins of the LC Alphanumeric Keyboard Module (I2C slave).
 Open the serial monitor and set the baud rate to 9600.
 
 This software is free provided that this notice is not removed and proper attribution 
 is accorded to Layad Circuits and its Author(s).
 Layad Circuits invests resources in producing free software. By purchasing Layad Circuits'
 products or utilizing its services, you support the continuing development of free software
 for all.
  
 Author(s): D. Deponio for Layad Circuits Electronics Engineering
 Revision: 1.0 - 2019/09/19 - initial creation
 Layad Circuits Electronics Engineering Supplies and Services
 B314 Lopez Bldg., Session Rd. cor. Assumption Rd., Baguio City, Philippines
 www.layadcircuits.com
 general: info@layadcircuits.com
 sales: sales@layadcircuits.com
 +63-916-442-8565
 ***************************************************************************/

#define LCKEYBOARD_I2C_ADDRESS 0x36 // default I2C device adddress
// #define LCKEYBOARD_I2C_ADDRESS 0x37 //I2C device adddress with microjumper installed at "A0"

#include <Wire.h>

enum LCKey{
  LCKey_up = 0x11,
  LCKey_left,//0x12
  LCKey_down,//0x13
  LCKey_right,//0x14
  LCKey_F1 = 0x82,
  LCKey_F2, //0x83
  LCKey_F3, //0x84
  LCKey_F4, //0x85
  LCKey_F5, //0x86
  LCKey_F6, //0x87
  LCKey_F7, //0x88
  LCKey_F8, //0x89
  LCKey_F9 //0x8A
};

void setup() {
  // Wire.setClock(100000);
  // Wire.setClock(400000);
  Wire.begin();        // join i2c bus
  Serial.begin(9600);  // start serial for output
}

void loop() {
  Wire.requestFrom(LCKEYBOARD_I2C_ADDRESS, 1); // request a byte from the LC Alphanemuric Keyboard Module

  if (Wire.available()) { 
    uint8_t c = Wire.read(); // read the key
    if(c){
      // nonprintable characters
      if(c == '\e') //escape
        Serial.println(F("ESC"));
      else if(c == 0x7F) // delete
        Serial.println(F("DEL"));
      else if(c == '\b') // backspace
        Serial.println(F("BACKSPACE"));
      else if(c == '\t') // tab
        Serial.println(F("TAB"));
      else if(c == LCKey_up) // up arrow
        Serial.println(F("UP"));
      else if(c == LCKey_left) // left arrow
        Serial.println(F("LEFT"));
      else if(c == LCKey_down) // down arrow
        Serial.println(F("DOWN"));
      else if(c == LCKey_right) // right arrow
        Serial.println(F("RIGHT"));

      // function keys
      else if(c == LCKey_F1) // F1
        Serial.println(F("F1"));
      else if(c == LCKey_F2) // F2
        Serial.println(F("F2"));
      else if(c == LCKey_F3) // F3
        Serial.println(F("F3"));
      else if(c == LCKey_F4) // F4
        Serial.println(F("F4"));
      else if(c == LCKey_F5) // F5
        Serial.println(F("F5"));
      else if(c == LCKey_F6) // F6
        Serial.println(F("F6"));
      else if(c == LCKey_F7) // F7
        Serial.println(F("F7"));  
      else if(c == LCKey_F8) // F8
        Serial.println(F("F8"));
      else if(c == LCKey_F9) // F9
        Serial.println(F("F9"));

      // printable characters
      else
        Serial.print((char)c); // print the character
    }               
  }
}
