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

Minitel m1(6,7);
Minitel m2(8,9);

int cursorXIni = 3;
int cursorYIni = 10;

int cursorX = cursorXIni;
int cursorY = cursorYIni;
int cursorXDir = 1;
int cursorYDir = -1;


void setup() {

  m1.textMode();
  m2.textMode();

  drawPart1();

  drawPart2();

}

int score = 0;

void loop() {

  int cursorXPre = cursorX;
  int cursorYPre = cursorY;

  cursorX+=cursorXDir;
  cursorY+=cursorYDir;


/*
  if (cursorX == 2 || cursorX == 79) {
    cursorXDir *= -1;
  }
*/

  if (cursorX == 81) {
    cursorX = cursorXIni;
    cursorY = cursorYIni;
    cursorYDir = 1;
    score++;
    if (score == 10) {
     score = 0; 
    }
    cursorYDir = score % 2 == 1 ? -1 : 1;
    drawScore(m1, score, 33, 3, true);
    Serial.println(score);
  }
  
  if (cursorY == 2 || cursorY == 23) {
    cursorYDir *= -1;
  }

  if (!isOverLapping(cursorXPre, cursorYPre)) {
    if (cursorXPre < 40) {
      m1.moveCursorTo(cursorXPre, cursorYPre);
      m1.textColor(BLACK);
      m1.textByte(127, cursorXPre, cursorYPre);
      m1.textColor(WHITE);
    }
    else  if (cursorXPre > 41) {
      m2.moveCursorTo(cursorXPre-40, cursorYPre);
      m2.textColor(BLACK);
      m2.textByte(127, cursorXPre-40, cursorYPre);
      m2.textColor(WHITE);
    }
  }

  if (!isOverLapping(cursorX, cursorY)) {
    if (cursorX < 40) {
      m1.moveCursorTo(cursorX, cursorY);
      m1.textByte(127, cursorX, cursorY);
    }
    else  if (cursorX > 41) {
      m2.moveCursorTo(cursorX-40, cursorY);
      m2.textByte(127, cursorX-40, cursorY);
    }
  }
}


boolean isOverLapping(int x, int y) {

  if (x >=33 && y >= 3 && x<=35 && y<=7) {
    delay(100);
    return true; 
  }
  if (x >=47 && y >= 3 && x<=49 && y<=7) {
    delay(100);
    return true; 
  }
  return false;

}

void drawMiddleLine(Minitel m, int x) {
  // Middle line
  for (int i=1; i<24; i++) {
    if (i%4 != 0) {
      m.textByte(127, x, i);
    } 
  }
}

void drawRaquet(Minitel m, int x, int y) {
  // Raquet
  m.textByte(127, x, y);
  m.textByte(127, x, y+1);
  m.textByte(127, x, y+2);
  m.textByte(127, x, y+3);  
}


void drawTopBottomLines(Minitel m) {
  // Top line
  m.textByte(127, 1, 1);
  m.repeat(39);

  // Bottom line
  m.textByte(127, 1, 24);
  m.repeat(39); 
}

void drawPart1() {
  m1.clearScreen();
  m1.noCursor();
  drawTopBottomLines(m1);
  drawMiddleLine(m1, 40);

  // Moving
  drawRaquet(m1, 1, 8);
  //textByte(127, 15, 12);

  // Score 
  drawScore(m1, 0, 33, 3, false);


  m1.cursor();
}

void drawPart2() {
  m2.clearScreen();
  m2.noCursor();
  drawTopBottomLines(m2);
  drawMiddleLine(m2, 1);

  // Moving
  drawRaquet(m2, 40, 7);

  // Score 
  drawScore(m2, 0, 7, 3, false);

  m2.noCursor();
}

void drawScore(Minitel m, int score, int x, int y, boolean erase) {
  if (erase) eraseScore(m, x, y);
  switch (score) {
  case 0 :
    drawScore0(m, x, y);
    break;
  case 1 :
    drawScore1(m, x, y);
    break;
  case 2 :
    drawScore2(m, x, y);
    break;
  case 3 :
    drawScore3(m, x, y);
    break;
  case 4 :
    drawScore4(m, x, y);
    break;
  case 5 :
    drawScore5(m, x, y);
    break;
  case 6 :
    drawScore6(m, x, y);
    break;
  case 7 :
    drawScore7(m, x, y);
    break;
  case 8 :
    drawScore8(m, x, y);
    break;
  case 9 :
    drawScore9(m, x, y);
    break;    
  }
}

void eraseScore(Minitel m, int x, int y) {
  m.textColor(BLACK);
  m.textByte(127, x, y);
  m.repeat(2);
  m.textByte(127, x, y+1);
  m.textByte(127, x+2, y+1);
  m.textByte(127, x, y+2);
  m.repeat(2);
  m.textByte(127, x, y+3);
  m.textByte(127, x+2, y+3);
  m.textByte(127, x, y+4);
  m.repeat(2);     
  m.textColor(WHITE);
}

void drawScore0(Minitel m, int x, int y) {
  // 0
  m.textByte(127, x, y);
  m.repeat(2);
  m.textByte(127, x, y+1);
  m.textByte(127, x+2, y+1);
  m.textByte(127, x, y+2);
  m.textByte(127, x+2, y+2);
  m.textByte(127, x, y+3);
  m.textByte(127, x+2, y+3);
  m.textByte(127, x, y+4);
  m.repeat(2);   
}

void drawScore1(Minitel m, int x, int y) {
  // 1
  m.textByte(127, x+2, y);
  m.textByte(127, x+2, y+1);
  m.textByte(127, x+2, y+2);
  m.textByte(127, x+2, y+3);
  m.textByte(127, x+2, y+4);
}

void drawScore2(Minitel m, int x, int y) {
  // 2
  m.textByte(127, x, y);
  m.repeat(2);
  m.textByte(127, x+2, y+1);
  m.textByte(127, x, y+2);
  m.repeat(2);
  m.textByte(127, x, y+3);
  m.textByte(127, x, y+4);
  m.repeat(2);   
}

void drawScore3(Minitel m, int x, int y) {
  // 3
  m.textByte(127, x, y);
  m.repeat(2);
  m.textByte(127, x+2, y+1);
  m.textByte(127, x+1, y+2);
  m.repeat(1);
  m.textByte(127, x+2, y+3);
  m.textByte(127, x, y+4);
  m.repeat(2);   
}


void drawScore4(Minitel m, int x, int y) {
  // 4
  m.textByte(127, x, y);
  m.textByte(127, x+2, y);
  m.textByte(127, x, y+1);
  m.textByte(127, x+2, y+1);
  m.textByte(127, x, y+2);
  m.repeat(2);
  m.textByte(127, x+2, y+3);
  m.textByte(127, x+2, y+4);
}


void drawScore5(Minitel m, int x, int y) {
  // 5
  m.textByte(127, x, y);
  m.repeat(2);
  m.textByte(127, x, y+1);
  m.textByte(127, x, y+2);
  m.repeat(2);
  m.textByte(127, x+2, y+3);
  m.textByte(127, x, y+4);
  m.repeat(2);   
}


void drawScore6(Minitel m, int x, int y) {
  // 6
  m.textByte(127, x, y);
  m.repeat(2);
  m.textByte(127, x, y+1);
  m.textByte(127, x, y+2);
  m.repeat(2);
  m.textByte(127, x, y+3);
  m.textByte(127, x+2, y+3);
  m.textByte(127, x, y+4);
  m.repeat(2);   
}


void drawScore7(Minitel m, int x, int y) {
  // 7
  m.textByte(127, x, y);
  m.repeat(2);
  m.textByte(127, x+2, y+1);
  m.textByte(127, x+2, y+2);
  m.textByte(127, x+2, y+3);
  m.textByte(127, x+2, y+4);
}

void drawScore8(Minitel m, int x, int y) {
  // 8
  m.textByte(127, x, y);
  m.repeat(2);
  m.textByte(127, x, y+1);
  m.textByte(127, x+2, y+1);
  m.textByte(127, x, y+2);
  m.repeat(2);
  m.textByte(127, x, y+3);
  m.textByte(127, x+2, y+3);
  m.textByte(127, x, y+4);
  m.repeat(2);   
}

void drawScore9(Minitel m, int x, int y) {
  // 9
  m.textByte(127, x, y);
  m.repeat(2);
  m.textByte(127, x, y+1);
  m.textByte(127, x+2, y+1);
  m.textByte(127, x, y+2);
  m.repeat(2);
  m.textByte(127, x+2, y+3);
  m.textByte(127, x, y+4);
  m.repeat(2);   
}



