#include "Arduboy2.h"
//special thinks to crait for making ...
//http://www.crait.net/tochars/index.php 
Arduboy2 ab;
//27 total a-f
// a = north america
int a1 = 0;
int a2 = 0;
int a3 = 0;
int a4 = 0;
int a1o = 0;
int a2o = 0;
int a3o = 0;
int a4o = 0;
// b  = central america
int b1 = 0;
int b2 = 0;
int b1o = 0;
int b2o = 0;
// c = south america
int c1 = 0;
int c2 = 0;
int c3 = 0;
int c1o = 0;
int c2o = 0;
int c3o = 0;
// d = europe
int d1 = 0;
int d2 = 0;
int d3 = 0;
int d4 = 0;
int d1o = 0;
int d2o = 0;
int d3o = 0;
int d4o = 0;
// e = asia 6
int e1 = 0;
int e2 = 0;
int e3 = 0;
int e4 = 0;
int e5 = 0;
int e6 = 0;
int e1o = 0;
int e2o = 0;
int e3o = 0;
int e4o = 0;
int e5o = 0;
int e60 = 0;
// f = austrailia 3
int f1 = 0;
int f2 = 0;
int f3 = 0;
int f1o = 0;
int f2o = 0;
int f3o = 0;
// g = africa 4
int g1 = 0;
int g2 = 0;
int g3 = 0;
int g4 = 0;
int g1o = 0;
int g2o = 0;
int g3o = 0;
int g4o = 0;

int xloc = 4;
int yloc = 6;
int turn = 0; // with players turn it is , 0 is player one 1 is player 2 ect

const unsigned char player2[] PROGMEM  = {
0xfc, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfc, 0x00, 0x1, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x1, 0x00, 
};
const unsigned char player[] PROGMEM  = {
0x3, 0x1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1, 0x3, 0x3, 0x2, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2, 0x3, 
};
const unsigned char mapyo[] PROGMEM  = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xc0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xe0, 0xf0, 0xf0, 0xf0, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0x78, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xc0, 0xe0, 0xe0, 0xe0, 0x60, 0xe0, 0xe0, 0xc0, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4, 0x6, 0x6, 0xe, 0x6, 0x6, 0x7, 0x7, 0x7, 0x7, 0x7, 0xbf, 0xff, 0xbf, 0xdf, 0xf5, 0xff, 0xff, 0xff, 0xff, 0xfd, 0x57, 0xff, 0xff, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0x55, 0xff, 0x7f, 0x7f, 0x7f, 0x7f, 0x7, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1, 0x3, 0x3, 0x3, 0x1, 0x1, 0x1, 0x00, 0x00, 0x00, 0x00, 0x80, 0xe0, 0xf0, 0xf0, 0xf0, 0xf8, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfc, 0xbc, 0xe4, 0xfc, 0xfc, 0xfe, 0xfe, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xad, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf9, 0x5f, 0xff, 0xff, 0xff, 0xff, 0x1f, 0x7, 0x7, 0x3, 0x3, 0xc3, 0x43, 0x2, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1c, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x7f, 0x55, 0xff, 0xff, 0x3f, 0xf, 0xf, 0x7, 0x7, 0x1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x83, 0x83, 0x83, 0x81, 0x81, 0xe1, 0xe1, 0xc3, 0x83, 0x87, 0x87, 0xf, 0xf, 0x7, 0x7, 0x3, 0x3, 0xc3, 0xf3, 0xfe, 0xf7, 0xff, 0xf7, 0xff, 0xf7, 0xff, 0xfb, 0xff, 0xfb, 0xff, 0xff, 0xfb, 0xff, 0xff, 0x36, 0xff, 0xff, 0xfd, 0xff, 0xfd, 0xff, 0xfd, 0xff, 0xfd, 0xff, 0xfd, 0xff, 0xff, 0xfe, 0xff, 0xff, 0xdb, 0xc7, 0x87, 0x3, 0x00, 0x00, 0x10, 0x1e, 0x3f, 0xf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x33, 0x3b, 0x3b, 0x73, 0x71, 0x80, 0xc0, 0x00, 0x00, 0x3, 0x00, 0x00, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0xf0, 0xf8, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xff, 0xdf, 0xf7, 0xfc, 0xf9, 0xf3, 0xc3, 0x83, 0x87, 0xf, 0xf, 0x1f, 0x1f, 0xf, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x7, 0xf, 0x7f, 0x7f, 0xf, 0x7, 0x3, 0x3, 0x7, 0xf, 0xf, 0x1f, 0xff, 0xff, 0xff, 0xff, 0x3, 0x3, 0x1, 0x1, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1, 0x3, 0x3, 0x6, 0x2, 0xf8, 0xfc, 0x7f, 0xff, 0xbf, 0xde, 0xfe, 0xec, 0xf8, 0xf8, 0xf8, 0xf0, 0xe0, 0xc0, 0xc0, 0xc0, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1, 0x7, 0x3, 0x7, 0x7, 0x7, 0x7, 0x7, 0x7, 0xf, 0x3b, 0xfd, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf, 0xe, 0xc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3, 0x3, 0x3, 0x1, 0x20, 0x70, 0x60, 0x00, 0x3, 0x3, 0x1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6, 0x7, 0xf, 0x1f, 0xff, 0xbf, 0xff, 0x7f, 0xff, 0x7f, 0xff, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7, 0x3, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x18, 0xff, 0xfb, 0xff, 0xfb, 0xff, 0xfb, 0xff, 0xb, 0x7, 0x3, 0x00, 0x00, 0xe0, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xe0, 0xe0, 0xf0, 0xf0, 0xf0, 0xa0, 0xf0, 0xe0, 0xe1, 0xe1, 0xe1, 0x81, 0x1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0x7f, 0x1f, 0x1f, 0xf, 0x8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1, 0x7, 0x1f, 0xf, 0x7, 0x3, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3, 0x3, 0xf, 0xf, 0xf, 0xf, 0xf, 0xf, 0xa, 0x1f, 0x3f, 0x3f, 0x1f, 0xf, 0x7, 0x2, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1, 0x7, 0x1f, 0x1c, 0x18, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};
void setup() {
  // put your setup code here, to run once:
 ab.begin();
  ab.setFrameRate(2);
  ab.initRandomSeed();
  ab.clear(); 
}

void loop() {
  // put your main code here, to run repeatedly:
if (!(ab.nextFrame()))
    return;
    ab.clear();

    if(ab.pressed(LEFT_BUTTON)) {
      // NORTH AMERICA
      // NORTH AMERICA
      if ((xloc == 4) && (yloc == 6))  { //if at a1 and press left
        xloc = 107; //move to  e2
        yloc = 7;
      }
      if ((xloc == 13) && (yloc == 15))  { //if at a2 and press left
        xloc = 4; //move to  a1
        yloc = 6;
      }
       if ((xloc == 22) && (yloc == 11))  { //if at a3 and press left
        xloc = 13; //move to  a2
        yloc = 15;
      }
       if ((xloc == 30) && (yloc == 6))  { //if at a4 and press left
        xloc = 22; //move to  a3
        yloc = 11;
      }
    } // close left button if is pressed
    if(ab.pressed(RIGHT_BUTTON)) { // ab.everyXFrames(30)
      if ((xloc == 4) && (yloc == 6))  { //if at a1 and press right
        xloc = 13; //move to  a2
        yloc = 15;
      } // end if at a1 and right button pushed move to a2
    
      if ((xloc == 13) && (yloc == 15))  { //if at a2 and press right
        xloc = 22; //move to  a3
        yloc = 11;
        
      } //end if at a3 and right button pushed move to a4
       if ((xloc == 22) && (yloc == 11))  { //if at a3 and press right
        xloc = 30; //move to  a4
        yloc = 6;
        
      }
      // ASIA
        if ((xloc == 107) && (yloc == 7))  { //if at e2 and press right
        xloc = 4; //move to  a1
        yloc = 6;
        
      }
    } //end right button if pressed
    if(ab.pressed(UP_BUTTON) && (yloc >= 0)) {
      // CENTRAL AMERICA
       if ((xloc == 13) && (yloc == 26))  { //if at b1 and press UP
        xloc = 13; //move to  a2
        yloc = 15; 
      }
        if ((xloc == 17) && (yloc == 31))  { //if at b2 and press UP
        xloc = 13; //move to  B1
        yloc = 26; 
      }
      // SOUTH AMERICA
      if ((xloc == 28) && (yloc == 49))  { //if at C3 and press UP
        xloc = 30; //move to C2
        yloc = 38; 
      }
      if ((xloc == 30) && (yloc == 38))  { //if at C2 and press UP
        xloc = 24; //move to C1
        yloc = 32; 
      }
      if ((xloc == 24) && (yloc == 32))  { //if at c1 and press UP
        xloc = 17; //move to b2
        yloc = 31; 
      }
    } //end up  button pressed
    if(ab.pressed(DOWN_BUTTON) && (yloc <= 64)) {
       if ((xloc == 13) && (yloc == 15))  { //if at a2 and press down
        xloc = 13; //move to  b1
        yloc = 26; 
      }
       if ((xloc == 13) && (yloc == 26))  { //if at B1 and press down
        xloc = 17; //move to  b2
        yloc = 31; 
      }
      if ((xloc == 17) && (yloc == 31))  { //if at B2 and press down
        xloc = 24; //move to  C1
        yloc = 32; 
      }
      //SOUTH AMERICA
      if ((xloc == 24) && (yloc == 32))  { //if at C1 and press down
        xloc = 30; //move to  C2
        yloc = 38; 
      }
      if ((xloc == 30) && (yloc == 38))  { //if at C2 and press down
        xloc = 28; //move to  C3
        yloc = 49; 
      }
      
    }// end if doen button is presses
    
    ab.drawBitmap((0), (0), mapyo, 128, 54, WHITE);
      ab.setCursor((xloc), (yloc));
      ab.print("X");
    
      ab.setCursor((70), (50));
      ab.print(xloc);
      ab.setCursor((90), (50));
      ab.print(yloc);
    ab.display();
}