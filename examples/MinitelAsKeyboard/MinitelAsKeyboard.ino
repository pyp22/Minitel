/**
   Minitel library for Arduino (v0.1) / May 2013
   http://github.com/01010101/Minitel

   By Jerome Saint-Clair aka 01010101
   http://saint-clair.net

   For the Graffiti Research Lab France
   http://graffitiresearchlab.fr

   Based on works by the Tetalab (Fabrice, Renaud, PG & Phil)
   http://tetalab.org
*/

/**
   Use Fnct T + E to disable echo

*/

#include <Minitel.h>

Minitel minitel;

void setup() {
  minitel.clearScreen();
  minitel.textMode();
  minitel.cursor();
}

void loop() {
  minitel.listen(); // Listen for info coming from the Minitel
  minitel.readKey(); // Try to read a key press

  if (minitel.isCharacterKey()) {
    char key = minitel.getCharacterKey();
    minitel.textChar(key);
  }
  else if (minitel.isMenuKey()) {
    int key = minitel.getMenuKey();
    if (key == RETOUR) { // Return
      minitel.moveCursorTo(HOME);
      minitel.moveCursor(DOWN, 1);
    }
    else if (key == CORRECTION) {
      minitel.moveCursor(LEFT, 1);
      minitel.textChar(' ');
      minitel.moveCursor(LEFT, 1);          
    }
    else if (key == ANNULATION) {
      minitel.clearScreen();
    }
  }
}
