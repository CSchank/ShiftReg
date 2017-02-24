# include "ShiftReg.h"

ShiftReg sh = ShiftReg(12,11,8,2);

void setup(){
  
}

void loop(){
  byte b[2] = {B00000111,B00111111};
  sh.setPByte(b);
}

