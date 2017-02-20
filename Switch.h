/*
  Switch.h - Class for managing button presses.
  Created by Christopher W. Schankula, Feburary 18, 2017.
  Released into the public domain.
*/
#ifndef ShiftReg_h
#define ShiftReg_h

#include "Arduino.h"

class Switch {
  public:
    Switch(int pin);
    bool getButtonState();
    bool getSwitchState();
    int getPresses();
  private:
    int _pin;
    int _num;
    int _lastDebounce;
    bool _lastState;
};

#endif
