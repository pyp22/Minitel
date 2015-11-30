#Minitel library for Arduino

This library provides a way to create screens for the [Minitel](https://en.wikipedia.org/wiki/Minitel) without having to dig into the complexity of the system.

##Schematic
A DIN 45º plug is required to plug the Arduino to the Minitel

![Alt text](/images/DIN.png?raw=true "Schematic")

##External libraries
This library is using SoftwareSerial, please install it prior to compiling any Minitel sketch.

##Constructor:

Default constructor, using Arduino PINs 6 and 7 for TX/RX
```
#include <SoftwareSerial.h>
#include <Minitel.h>
Minitel minitel;

void setup() {
}
...
```

Custom constructor using other Arduino PINs for TX/RX
```
#include <SoftwareSerial.h>
#include <Minitel.h>
Minitel minitel(10, 11);

void setup() {
}
...
```



Constants :

//text(String s, int orientation)
HORIZONTAL
VERTICAL

// moveCursor()
LEFT
RIGHT
DOWN
UP
HOME
LINE_END
TOP_LEFT
TOP_RIGHT
BOTTOM_LEFT
BOTTOM_RIGHT
CENTER

// charSize()
SIZE_NORMAL
SIZE_DOUBLE_HEIGHT
SIZE_DOUBLE_WIDTH
SIZE_DOUBLE

// Colors
// bgColor()
// textColor
BLACK
RED
GREEN
YELLOW
MAGENTA
BLUE
CYAN
WHITE

// specialChar()
SPE_CHAR_BOOK
SPE_CHAR_PARAGRAPH
SPE_CHAR_ARROW_LEFT
SPE_CHAR_ARROW_UP
SPE_CHAR_ARROW_RIGHT
SPE_CHAR_ARROW_DOWN
SPE_CHAR_CIRCLE
SPE_CHAR_MINUS_PLUS
SPE_CHAR_1_4
SPE_CHAR_1_2
SPE_CHAR_3_4
SPE_CHAR_UPPER_OE
SPE_CHAR_LOWER_OE
SPE_CHAR_BETA
