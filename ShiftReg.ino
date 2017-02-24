# include "ShiftReg.h"

ShiftReg shReg; //instantiate ShiftReg instance

void setup(){
  //initialize shReg with 2 daisy chained shift registers, having clock pin 12, data pin 11 and latch pin 8.
  shReg.init(2,12,11,8);
}

void loop(){
  //array of bytes
  byte b[2] = {B11100000,B00000000};
  //set the current byte, and push it to the shift register
  shReg.setPByte(b);
}

