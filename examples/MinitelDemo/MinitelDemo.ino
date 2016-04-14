/**
 * Minitel library for Arduino (v0.1) / May 2013
 * http://github.com/01010101/Minitel
 *
 * By Jerome Saint-Clair aka 01010101
 * http://saint-clair.net
 * 
 * For the Graffiti Research Lab France
 * http://graffitiresearchlab.fr
 * 
 * Based on works by the Tetalab (Fabrice, Renaud, PG & Phil)
 * http://tetalab.org
 */


#include <SoftwareSerial.h>
#include <Minitel.h>

Minitel m(6,7);

void setup() {
  
}

void loop() {
 
  long pause = 2000;

  demoColor();
  delay(pause);

  demoGraphics(false);
  delay(pause);

  demoGraphics(true);
  delay(pause);

  demoBip();
  delay(pause);

  demoCursor();
  delay(pause);

  demoText();
  delay(pause);

  demoCharacters();
  delay(pause);
  
}

/**
 *
 * DEMOS
 *
 */

// Graphic characters

void demoGraphics(boolean underline) {

  m.clearScreen();
  m.textMode();
  m.textColor(WHITE);
  m.bgColor(RED);
  m.text(" GRAPHICS DEMO ", 4, 1);
  m.bgColor(BLACK);

  
  m.graphicMode();
  
  if (underline) {
    m.pixelate();
  }
  m.noCursor();

  // No color 
  m.useDefaultColors();

  int xPos = 5;
  int yPos = 5;
  m.moveCursorTo(xPos, yPos);
  int x = 32;
  for (int i=x; i<x+16; i++) {
    m.serialprint7(i);
    m.serialprint7(9);
  }

  m.moveCursorTo(xPos, yPos+2);
  for (int i=x+16; i<x+32; i++) {
    m.serialprint7(i);
    m.serialprint7(9);
  }

  m.moveCursorTo(xPos, yPos+4);
  for (int i=x+32; i<x+48; i++) {
    m.serialprint7(i);
    m.serialprint7(9);
  }

  m.moveCursorTo(xPos, yPos+6);
  for (int i=x+48; i<x+64; i++) {
    m.serialprint7(i);
    m.serialprint7(9);
  } 

  // Colored
  m.bgColor(RED);
  m.textColor(WHITE);

  m.moveCursorTo(xPos, yPos+10);
  x = 32;
  for (int i=x; i<x+16; i++) {
    m.serialprint7(i);
    m.serialprint7(9);
  }

  m.moveCursorTo(xPos, yPos+12);
  for (int i=x+16; i<x+32; i++) {
    m.serialprint7(i);
    m.serialprint7(9);
  }

  m.moveCursorTo(xPos, yPos+14);
  for (int i=x+32; i<x+48; i++) {
    m.serialprint7(i);
    m.serialprint7(9);
  }

  m.moveCursorTo(xPos, yPos+16);
  for (int i=x+48; i<x+64; i++) {
    m.serialprint7(i);
    m.serialprint7(9);
  }
  
  m.useDefaultColors();
  m.noPixelate();
  
}


void demoCursor() {
  m.clearScreen();
  m.textMode();
  m.textColor(WHITE);
  m.bgColor(RED);
  m.text(" CURSOR DEMO ", 4, 1);
  m.bgColor(BLACK);

  m.cursor();

  int pause = 1000;
  m.moveCursorTo(TOP_LEFT);
  delay(pause);
  m.moveCursor(RIGHT, 39);
  delay(pause);
  m.moveCursor(DOWN, 23);
  delay(pause);
  m.moveCursor(LEFT, 39);
  delay(pause);
  m.moveCursor(UP, 23);
  delay(pause);
  m.moveCursor(RIGHT, 19);
  delay(pause);
  m.moveCursor(DOWN, 12);
  delay(pause);
  m.moveCursorTo(HOME);
  delay(pause);
  m.moveCursorTo(TOP_RIGHT);
  delay(pause);
  m.moveCursorTo(BOTTOM_LEFT);
  delay(pause);
  m.moveCursorTo(BOTTOM_RIGHT);
  delay(pause);
  m.moveCursorTo(TOP_LEFT);
  delay(pause);
  m.moveCursorTo(CENTER);
  m.noCursor();
}


void demoCharacters() {
  m.clearScreen();
  m.textMode();
  m.textColor(WHITE);
  m.bgColor(RED);
  m.text(" CHARACTERS DEMO ", 4, 1);
  m.bgColor(BLACK);


  int xPos = 3;
  int yPos = 5;
  m.cursor();

  m.text("abcdefghijklmnopqrstuvwxyz", xPos, yPos);
  m.text("ABCDEFGHIJKLMNOPQRSTUVWXYZ", xPos, yPos+1);

  // 0-9 + punctuation marks, ...
  m.text("!\"#$%&'()*+,-./0123456789",xPos, yPos+2);
  m.text(":;<=>?@[\\]",xPos, yPos+3);

  m.moveCursorTo(xPos, yPos+2);
  m.serialprint7(96);
  m.serialprint7(95);
  m.serialprint7(94);
  m.serialprint7(123);
  m.serialprint7(124);
  m.serialprint7(125);
  m.serialprint7(126);

  // Colored characters
  m.moveCursorTo(xPos, yPos+4);
  m.textColor(RED);
  
  for (int i=97; i<97+26; i++) {
    m.serialprint7(i);
  }
  m.textColor(WHITE);

  // Double width 1/2
  m.charSize(SIZE_DOUBLE_WIDTH);
  m.text("abcdefghijklmnopqrstuvwxyz", xPos, yPos+5);
  m.text("ABCDEFGHIJKLMNOPQRSTUVWXYZ", xPos, yPos+6);
  m.charSize(SIZE_NORMAL);

  // Special characters
  m.moveCursorTo(xPos, yPos+7);
  byte chars[] = {
SPE_CHAR_POUND,
SPE_CHAR_DOLLAR,
SPE_CHAR_HASHTAG,
SPE_CHAR_PARAGRAPH,
SPE_CHAR_ARROW_LEFT,
SPE_CHAR_ARROW_UP,
SPE_CHAR_ARROW_RIGHT,
SPE_CHAR_ARROW_DOWN,
SPE_CHAR_DEGREE,
SPE_CHAR_MINUS_PLUS,
SPE_CHAR_DIVIDE,
SPE_CHAR_1_4,
SPE_CHAR_1_2,
SPE_CHAR_3_4,
SPE_CHAR_GRAVE,
SPE_CHAR_ACUTE,
SPE_CHAR_CIRCUMFLEX,
SPE_CHAR_UMLAUT,
SPE_CHAR_CEDIL,
SPE_CHAR_UPPER_OE,
SPE_CHAR_LOWER_OE,
SPE_CHAR_BETA
//SPE_CHAR_ARROW_UP2,
//SPE_CHAR_PIPE_BOTTOM,
//SPE_CHAR_PIPE_MIDDLE,
//SPE_CHAR_PIPE_LEFT,
//SPE_CHAR_PIPE_CENTER,
//SPE_CHAR_PIPE_RIGHT,
//SPE_CHAR_PIPE_TOP
};
  for (int i=0; i<sizeof(chars); i++) {
    m.specialChar(chars[i]);
  }

  // Blink
  m.blink();
  m.text("ABCDEFGHIJKLMNOPQRSTUVWXYZ", xPos, yPos+8);
  m.noBlink();

  // Invert video
  m.invertVideo();
  m.text("ABCDEFGHIJKLMNOPQRSTUVWXYZ", xPos, yPos+9);
  m.standardVideo();


  // Transparent
  // No effet on Minitel 1
  m.transparentVideo();
  m.text("ABCDEFGHIJKLMNOPQRSTUVWXYZ", xPos, yPos+10);
  m.standardVideo();
}


void demoBip() {
  m.clearScreen();
  m.textMode();
  m.textColor(WHITE);
  m.bgColor(RED);
  m.text(" BIP DEMO ", 4, 1);
  m.bgColor(BLACK);
  
  for (int i=0; i<2; i++) {
    m.bip(50);
    delay(700);
    m.bip(5);
    delay(500);
    m.bip(10);
    delay(2000);
  }
}

void demoText() {
  m.clearScreen();
  m.textMode();
  m.textColor(WHITE);
  m.bgColor(RED);
  m.text(" TEXT DEMO ", 4, 1);
  m.bgColor(BLACK);

  m.cursor();
  m.text("****************************************", 1, 8);
  m.blink();
  m.text("CAUTION", 17, 13);
  m.noBlink();
  m.text("This is a test", 13, 15);
  m.text("****************************************", 1, 20);
  m.noCursor(); 
}

void demoColor() {

  m.clearScreen();
  m.textMode();
  m.textColor(WHITE);
  m.bgColor(RED);
  m.text(" COLORS DEMO ", 4, 1);

  m.graphicMode();
  m.bgColor(RED);
  m.rect((byte) m.getGraphicChar("011001"), 4, 4, 33, 20);

  for(int i=0; i<18; i++) {
    m.moveCursorTo(5, 5+i);

    m.textColor(WHITE);
    m.graphic("111111");
    m.repeat(3);

    m.textColor(YELLOW);
    m.graphic("111111");
    m.repeat(3);

    m.textColor(CYAN);
    m.graphic("111111");
    m.repeat(3);

    m.textColor(GREEN);
    m.graphic("111111");
    m.repeat(3);

    m.textColor(BLUE);
    m.graphic("111111");
    m.repeat(3);

    m.textColor(RED);
    m.graphic("111111");
    m.repeat(3);

    m.textColor(MAGENTA);
    m.graphic("111111");
    m.repeat(3);

    m.textColor(BLACK);
    m.graphic("111111");
    m.repeat(3);
  }
}

