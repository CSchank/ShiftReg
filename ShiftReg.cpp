#include "Arduino.h"
#include "ShiftReg.h"

ShiftReg::ShiftReg(int clockPin, int dataPin, int latchPin, int n){
  Serial.begin(9600);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  _clockPin = clockPin;
  _dataPin = dataPin;
  _latchPin = latchPin;
  _numSR = n;
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
    shiftOut(_dataPin, _clockPin, MSBFIRST, _bytes[i]);
  }
  digitalWrite(_latchPin, 1);
}
    
void ShiftReg::setPByte(byte bytes[]){
  setByte(bytes);
  pushByte();
}

