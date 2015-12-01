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

Minitel m;
void setup() {
}

void loop() {

  m.clearScreen();
  m.pixelate();  
  
  m.textMode();  
  
  
  int x = 9;
  
  
  // U
  for (int i=5; i<9; i++) {
    m.textByte(123, x, i);
    m.textByte(123, x+2, i);
  }
  m.textChar('\\', x, 9);
  m.textChar('_', x+1, 9);
  m.textByte(123, x+2, 9);

  // ll
  for (int i=1; i<10; i++) {
    m.textByte(123, x+4, i);
    m.textByte(123, x+6, i);
  }


  // A
  m.textChar('/', x+8, 5);
  m.textChar('_', x+9, 4);
  m.textByte(123, x+10, 5);
  for (int i=6; i<9; i++) {
    m.textByte(123, x+8, i);
    m.textByte(123, x+10, i);
  }
  m.textChar('\\', x+8, 9);
  m.textChar('_', x+9, 9);
  m.textChar('\\', x+10, 9);

  m.text("MESSAGERIE AMICALE", 22, 2);
  m.text("ET CONVIVIALE", 22, 3);
  
  
  m.textChar('/', x+4, 10); 
  m.textChar('/', x+3, 11); 
  m.textChar('/', x+2, 12); 
  m.textChar('\\', x+5, 10); 
  m.textChar('\\', x+6, 11); 
  m.textChar('\\', x+7, 12); 

  m.graphicMode();
  m.textColor(RED);
  m.textByte(112, 1, 12);
  m.repeat(9);
  m.textByte(112, 17, 12);
  m.repeat(3);
  m.textByte(112, 34, 12);
  m.repeat(6);

  m.textMode();


// Line -6
  m.textColor(RED);
  m.textChar('_', 28, 7);
  m.textChar('_');


// Line -5
  
  m.textByte(123, 28, 8);
  m.textColor(WHITE);

  m.textChar('\\', 30, 8);


// Line -4
  m.textChar('/', 27, 9);
  m.textColor(RED);
  m.textChar('\\', 31, 9);
  m.textColor(WHITE);


// Line -3 (10)
  m.textChar('/', 23, 10);
  m.textColor(RED);
  m.textByte(126);
  m.repeat(2);

  m.textChar('_', 27, 10);

  m.textChar('\\', 32, 10);
  m.textColor(WHITE);

// Line -2 (11)
  m.textChar('/', 22, 11);

  
  m.graphicMode();

  
// Line 1
  m.textByte(127, 1, 13);
  m.repeat(8);
  m.textByte(39, 10, 13);
  m.textByte(9);
  m.textByte(9);
  m.textByte(96);
  m.textByte(9);
  m.textByte(9);
  m.textByte(9);
  m.textByte(43);
  m.textByte(127);
  m.textByte(127);
  m.textByte(39);
  
  m.textByte(106, 29, 13);
  m.textByte(48);
  m.textByte(32);
  m.textByte(112);
  m.textByte(126);
  
  m.textByte(127, 34, 13);
  m.repeat(6);
  

// Line 2
  m.textByte(127, 1, 14);
  m.repeat(7);
  m.textByte(39, 9, 14);
  m.textByte(9);
  m.textByte(9);
  m.textByte(120);
  m.textByte(127);
  m.textByte(116);
 // m.textByte(48);
  
  
  m.textByte(112, 26, 14);
  m.textByte(52);
  m.textByte(106, 29, 14);
  m.textByte(127);
  m.repeat(10);
  /*
  m.textByte(32);
  m.textByte(112);
  m.textByte(126);
  m.textByte(127);
  m.repeat(8);
  */
  
  // Line 3
  m.textByte(47, 1, 15);
  m.textByte(39);
  m.textByte(35);
  m.textByte(35);
  m.textByte(9);
  m.textByte(35);
  m.textByte(9);  
  m.textMode();
  m.textColor(RED);
  m.textChar('/');
  m.textByte(32);
  m.repeat(5);  
  m.textChar('\\');

  m.graphicMode();
  m.textColor(WHITE);
  m.textByte(96, 23, 15);
  m.textByte(124);
  m.textByte(127);
  m.textByte(127);
  m.textByte(37);
  
  m.graphicMode();
  m.textColor(WHITE);  
  m.textByte(106, 29, 15);
  m.textByte(127);
  m.repeat(10);

  
  // Line 4
  m.textMode();
  m.textColor(WHITE);
  m.textChar('_', 23, 16);
  m.textChar('_', 24, 16);

  m.textColor(RED);    // bras
  m.textChar('_', 25, 16);
  m.textChar('_', 26, 16);
  m.graphicMode();
  m.textColor(WHITE);  
  m.textByte(106, 29, 16);
  m.textByte(127);
  m.repeat(10);


  
  // Line 5
  m.textColor(RED);
  m.textByte(127, 1, 17);
  m.textByte(127);
  m.textByte(116);
  m.textByte(112);
  m.textByte(112);
  m.textByte(32);
  m.textByte(32);
  m.textByte(112);
  m.textByte(112);
  m.textByte(124);
  m.repeat(3);
  m.textByte(112);
  m.repeat(2);
  m.textByte(32);
  m.repeat(2);
  m.textColor(WHITE);
  m.textByte(122, 29, 17);
  m.textByte(127);
  m.repeat(10);
  
  // Line 6
  m.textColor(RED);
  m.textByte(127, 1, 18);
  m.repeat(15);
  m.textByte(125);
  m.textByte(112);
  m.repeat(2);
  m.textByte(124);
  m.repeat(6);  
  m.textByte(127);
  m.repeat(12);  
  
  m.textMode();
  m.invertVideo();
  m.textColor(RED);
  m.bgColor(WHITE);
  m.text(" Si vous connaissez et acceptez les     ", 1, 19);
  m.text(" conditions d'accès, tapez votre prénom ", 1, 20);
  m.text(" ou inventez un pseudo (5 à 31 signes)   ", 1, 21);
  m.text(" Merci de rester correct.               ", 1, 22);
  
  m.standardVideo();
  m.textColor(WHITE);
  m.bgColor(BLACK);
  m.text("...............................", 2, 23);
  m.text("Si vous ne les connaissez pas", 2, 24);
  m.textChar('+', 34, 23);
  m.specialChar(SPE_CHAR_ARROW_RIGHT, 34, 24);
  m.invertVideo();
  m.text("Envoi", 36, 23);
  m.text("Guide", 36, 24);
  m.standardVideo();
  
  m.textColor(WHITE);
  
  m.moveCursorTo(2, 23);
  m.cursor();
  
  delay(20000);

}

