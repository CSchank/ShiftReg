#include "Arduino.h"
#include "ShiftReg.h"

ShiftReg::ShiftReg(){

}

ShiftReg::init(int n,int clockPin,int dataPin,int latchPin){
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  _numSR = n;
  _clockPin = clockPin;
  _dataPin = dataPin;
  _latchPin = latchPin;
}

void ShiftReg::clearBytes() {
  for (int i = 0; i < _numSR; i++){
    _bytes[i] = B00000000;
  }
  pushByte();
}

byte ShiftReg::getByte(){
  return _bytes;
}

void ShiftReg::setByte(byte bytes[]){
  for (int i = 0; i < _numSR; i++){
    _bytes[i] = bytes[i];
  }
}

void ShiftReg::pushByte(){
  digitalWrite(_latchPin, LOW);
  for (int i = 0; i < _numSR; i++) {
    digitalWrite(_latchPin, LOW);
    shiftOut(_dataPin, _clockPin, LSBFIRST, _bytes[_numSR-1-i]);
  }
  digitalWrite(_latchPin, 1);
}
    
void ShiftReg::setPByte(byte bytes[]){
  setByte(bytes);
  pushByte();
}

