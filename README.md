# ShiftReg
Arduino class for managing n daisy chained shift registers.

## Installation
Place ShiftReg.h and ShiftReg.cpp in the folder of your Arduino sketch. In the sketch, place an include at the top:
```
#include "ShiftReg.h"
```
Then, instantiate the object and call init() from your setup() function. init() takes 4 arguments:
1. n - number of shift registers chained together.
2. Arduino pin attached to clock pin.
3. Arduino pin attached to data pin.
4. Arduino pin attached to latch pin.
```
ShiftReg shReg;

void setup() {
  shReg.init(1,12,11,8);
}
```
Now, you can call the various functions to set the state of the shift register. See ShiftReg.ino for a full example.

##License
This class is released under the [Creative Commons Attribution-ShareAlike CC BY-SA License](https://creativecommons.org/licenses/by-sa/4.0/deed.en).
