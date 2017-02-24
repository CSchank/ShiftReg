#include "Arduino.h"
#include "ShiftReg.h"

//Shift Register Constructor
ShiftReg::ShiftReg(){
  
}

//needed at startup of program; sets number of shift registers and pins.
ShiftReg::init(int n,int clockPin,int dataPin,int latchPin){
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  _numSR = n;
  _clockPin = clockPin;
  _dataPin = dataPin;
  _latchPin = latchPin;
}

//Turn off all shift register switches.
void ShiftReg::clearBytes() {
  for (int i = 0; i < _numSR; i++){
    _bytes[i] = B00000000;
  }
  pushByte();
}

//return the current state of the shift register(s)
byte ShiftReg::getByte(){
  return _bytes;
}

//set the current memory of the shift register, without pushing it to the register(s) itself.
//probably not recommened, could be confusing. But may be useful in certain cases.
void ShiftReg::setByte(byte bytes[]){
  for (int i = 0; i < _numSR; i++){
    _bytes[i] = bytes[i];
  }
}

//push the current bytes to the shift register(s)
void ShiftReg::pushByte(){
  digitalWrite(_latchPin, LOW);
  for (int i = 0; i < _numSR; i++) {
    digitalWrite(_latchPin, LOW);
    shiftOut(_dataPin, _clockPin, LSBFIRST, _bytes[_numSR-1-i]);
  }
  digitalWrite(_latchPin, 1);
}

//set the current byte to a new value and push it to the shift register
void ShiftReg::setPByte(byte bytes[]){
  setByte(bytes);
  pushByte();
}

