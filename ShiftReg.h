/*
  ShiftReg.h - Class for managing n daisy chained Shift Registers.
  Created by Christopher W. Schankula, Feburary 18, 2017.
  Released under Creative Commons Attribution-ShareAlike CC BY-SA license.
*/
#ifndef ShiftReg_h
#define ShiftReg_h

#include "Arduino.h"

class ShiftReg
{
  public:
    ShiftReg();
    init(int n, int clockPin, int dataPin, int latchPin);
    void clearBytes();
    byte getByte();
    void setByte(byte bytes[]);
    void pushByte();
    void setPByte(byte bytes[]);
  private:
    int _numSR;
    int _clockPin;
    int _dataPin;
    int _latchPin;
    byte _bytes[];
};

#endif
