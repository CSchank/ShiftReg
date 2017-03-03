# ShiftReg
Arduino class for managing n daisy chained shift registers.

## Installation
Place [ShiftReg.h](ShiftReg.h) and [ShiftReg.cpp](ShiftReg.cpp) in the folder of your Arduino sketch. In the sketch, place an include at the top:
```arduino
#include "ShiftReg.h"
```
Then, instantiate the object and call init() from your setup() function. init() takes 4 arguments:

1. n - number of shift registers chained together.
2. Arduino pin attached to clock pin.
3. Arduino pin attached to data pin.
4. Arduino pin attached to latch pin.

```arduino
ShiftReg shReg;

void setup() {
  shReg.init(1,12,11,8);
}
```
Now, you can call the various functions (see [ShiftReg.cpp](Shift.cpp)) to set the state of the shift register. See [ShiftReg.ino](ShiftReg.ino) for a working example.

##License
This class is released under the [Creative Commons Attribution-ShareAlike CC BY-SA License](https://creativecommons.org/licenses/by-sa/4.0/deed.en).
