#include "Arduino.h"
#include "Switch.h"

Switch::Switch(int pin) {
  pinMode(pin, OUTPUT);
  _pin = pin;
}

bool Switch::getButtonState() {
  bool state = digitalRead(_pin);
  return state;
}

bool Switch::getSwitchState() {
  bool state = digitalRead(_pin);
  return state;
}


int Switch::getPresses() {
  
}
