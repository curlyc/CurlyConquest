#include "Arduboy2.h"
//special thanks to crait for making ...
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
int e6o = 0;
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

int voodoo = 0;
int tergiv = 0;
int gamestate = 0;
int xloc = 4; //cursor location x
int yloc = 6; //cursor location y
int txloc = 4; // target location x
int tyloc = 6; // target location y
int turn = 0; // with players turn it is , 0 is player one 1 is player 2 ect
int own = a1o; //what player owns terirory cursor is over
int troo = a1; //how manyu troops are there
int tgiv1 = 99; //how many troops player 1 has to place
int tgiv2 = 34;
int tgiv3 = 34;
int tgiv4 = 34;
int tgiv5 = 34;
int tgiv6 = 34;
int tgivx = tgiv1;
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
  ab.setFrameRate(60);
  ab.initRandomSeed(); //once tested move this to after one of the button pushes
  ab.clear(); 
}

void loop() {
  // put your main code here, to run repeatedly:
if (!(ab.nextFrame()))
    return;
    ab.clear();
    if (gamestate == 0) { //title screen 
      ab.setCursor((0), (55)); 
      ab.print("VERSION 0.1 Map Done");
      if (ab.pressed(A_BUTTON)) {
        ab.clear();
        gamestate += 1;
      }
    }
    if (gamestate == 1) {//player select
      if (ab.pressed(A_BUTTON)) {
        ab.clear();
        gamestate += 1;
      }
    }
     
      //player select
    
    // gameplay
    if (gamestate == 2) {
       if (ab.pressed(A_BUTTON)) {
        ab.clear();
        gamestate += 1;
      }

      if (turn == 1) {
        tgivx = tgiv1;
        tgiv1 = tgivx;
      }
      if (turn == 2) {
        tgivx = tgiv2;
      }
      if (turn == 3) {
        tgivx = tgiv3;
      }
      if (turn == 4) {
        tgivx = tgiv4;
      }
      if (turn == 5) {
        tgivx = tgiv5;
      }
      if (turn == 6) {
        tgivx = tgiv6;
      }
     
      // distribute teritories if not yet done
      if (turn >=7) {
        turn = 1;
      }
      if (tergiv == 0) {
        voodoo = random(1,25);
        ab.setCursor((90), (50));
      ab.print(voodoo);
      }
      if ((voodoo == 1) && (a1o == 0)) {
        a1o = turn;
        turn +=1;
      }
      if ((voodoo == 2) && (a2o == 0)) {
        a2o = turn;
        turn +=1;
      }
      if ((voodoo == 3) && (a3o == 0)) {
        a3o = turn;
        turn +=1;
      }
      if ((voodoo == 4) && (a4o == 0)) {
        a4o = turn;
        turn +=1;
      }
      if ((voodoo == 5) && (b1o == 0)) {
        b1o = turn;
        turn +=1;
      }
      if ((voodoo == 6) && (b2o == 0)) {
        b2o = turn;
        turn +=1;
      }
      if ((voodoo == 7) && (c1o == 0)) {
        c1o = turn;
        turn += 1;
      }
      if ((voodoo == 8) && (c2o == 0)) {
        c2o = turn;
        turn +=1;
      } 
      if ((voodoo == 9) && (c3o == 0)) {
        c3o = turn;
        turn +=1;
      }
      if ((voodoo == 10) && (d1o == 0)) {
        d1o = turn;
        turn +=1;
      }
      if ((voodoo == 11) && (d2o == 0)) {
        d2o = turn;
        turn +=1;
      }
      if ((voodoo == 12) && (d3o == 0)) {
        d3o = turn;
        turn += 1;
      }
      if ((voodoo == 13) && (d4o == 0)) {
        //thats just bad juju
        d4o = turn;
        turn +=1;
      }
      if ((voodoo == 14) && (e1o == 0)) {
        e1o = turn;
        turn += 1;
      }
      if ((voodoo == 15) && (e2o == 0)) {
        e2o = turn;
        turn += 1;
      }
      if ((voodoo == 16) && (e3o == 0)) {
        e3o = turn;
        turn +=1;
      }
      if ((voodoo == 17) && (e4o == 0)) {
        e4o = turn;
        turn += 1;
      }
      if ((voodoo == 18) && (e5o == 0)) {
        e5o = turn;
        turn += 1;
      }
      if ((voodoo == 19) && (e6o == 0)) {
        e6o = turn;
        turn += 1;
      }
      if ((voodoo == 20) && (f1o == 0)) {
        f1o = turn;
        turn += 1;
      }
      if ((voodoo == 21) && (f2o == 0)) {
        f2o = turn;
        turn +=1;
      }
      if ((voodoo == 22) && (f3o == 0)) {
        f3o =turn;
        turn += 1;
      }
       if ((voodoo == 23) && (g1o == 0)) {
        g1o = turn;
        turn += 1;
       }
       if ((voodoo == 24) && (g2o ==0)) {
        g2o = turn;
        turn +=1;
       }

       if ((a1o >= 1) && (a2o >= 1) && (a3o >= 1) && (a4o >= 1) && (b1o >= 1) && (b2o >= 1) && (c1o >= 1) && (c2o >= 1) && (c3o >= 1) && (d1o >= 1) && (d2o >= 1) && (d3o >= 1) && (d4o >= 1) && (e1o >=1) && (e2o >= 1) && (e3o >= 1) && (e4o >= 1) && (e5o >= 1) && (e6o >= 1) && (f1o >= 1) && (f2o >= 1) && (f3o >=1) && (g1o >= 1) && g2o >=1) {
        tergiv = 1;
        turn = 1;
       }
       
      
      if (tgivx >= 1) {
        if ((a1o == turn) && (xloc == 4) && (yloc == 6) && (ab.pressed(B_BUTTON))&& ab.everyXFrames(10)) {
          a1 += 1;
          troo = a1;
          if (turn == 1) {
            tgiv1 -=1;;
          }
          
          //if at start up turn +=1;
        }
        if ((a2o == turn) && (xloc == 13) && (yloc == 15) && (ab.pressed(B_BUTTON))&& ab.everyXFrames(10)) {
          a2 += 1;
          troo = a2;
          if (turn == 1) {
            tgiv1 -=1;;
          }
          //if at start up turn +=1;
        }
        if ((a3o == turn) && (xloc == 22) && (yloc == 11) && (ab.pressed(B_BUTTON))&& ab.everyXFrames(10)) {
          a3 += 1;
          troo = a3;
          if (turn == 1) {
            tgiv1 -=1;;
          }
          //if at start up turn +=1;
        }
        if ((a4o == turn) && (xloc == 30) && (yloc == 6) && (ab.pressed(B_BUTTON))&& ab.everyXFrames(10)) {
          a4 += 1;
          troo = a4;
  
          if (turn == 1) {            tgiv1 -=1;           }
          if (turn == 2) {            tgiv2 -=1;           }
          if (turn == 3) {            tgiv3 -=1;           }
          if (turn == 4) {            tgiv4 -=1;           }
          if (turn == 5) {            tgiv1 -=1;           }
          if (turn == 6) {            tgiv1 -=1;           }
          //if at start up turn +=1;
        }
        if ((b1o == turn) && (xloc == 13) && (yloc == 26) && (ab.pressed(B_BUTTON))&& ab.everyXFrames(10)) {
          b1 += 1;
          troo = b1;
          if (turn == 1) {            tgiv1 -=1;           }
          if (turn == 2) {            tgiv2 -=1;           }
          if (turn == 3) {            tgiv3 -=1;           }
          if (turn == 4) {            tgiv4 -=1;           }
          if (turn == 5) {            tgiv1 -=1;           }
          if (turn == 6) {            tgiv1 -=1;           }
          //if at start up turn +=1;
        }
        if ((b2o == turn) && (xloc == 17) && (yloc == 31) && (ab.pressed(B_BUTTON))&& ab.everyXFrames(10)) {
          b2 += 1;
          troo = b2;
          if (turn == 1) {            tgiv1 -=1;           }
          if (turn == 2) {            tgiv2 -=1;           }
          if (turn == 3) {            tgiv3 -=1;           }
          if (turn == 4) {            tgiv4 -=1;           }
          if (turn == 5) {            tgiv1 -=1;           }
          if (turn == 6) {            tgiv1 -=1;           }
          //if at start up turn +=1;
        }
        if ((c1o == turn) && (xloc == 24) && (yloc == 32) && (ab.pressed(B_BUTTON))&& ab.everyXFrames(10)) {
          c1 += 1;
          troo = c1;
          if (turn == 1) {            tgiv1 -=1;           }
          if (turn == 2) {            tgiv2 -=1;           }
          if (turn == 3) {            tgiv3 -=1;           }
          if (turn == 4) {            tgiv4 -=1;           }
          if (turn == 5) {            tgiv1 -=1;           }
          if (turn == 6) {            tgiv1 -=1;           }
          //if at start up turn +=1;
        }
        if ((c2o == turn) && (xloc == 30) && (yloc == 38) && (ab.pressed(B_BUTTON))&& ab.everyXFrames(10)) {
          c2 += 1;
          troo = c2;
          if (turn == 1) {            tgiv1 -=1;           }
          if (turn == 2) {            tgiv2 -=1;           }
          if (turn == 3) {            tgiv3 -=1;           }
          if (turn == 4) {            tgiv4 -=1;           }
          if (turn == 5) {            tgiv1 -=1;           }
          if (turn == 6) {            tgiv1 -=1;           }
          //if at start up turn +=1;
        }
        if ((c3o == turn) && (xloc == 28) && (yloc == 49) && (ab.pressed(B_BUTTON))&& ab.everyXFrames(10)) {
          c3 += 1;
          troo = c3;
          if (turn == 1) {            tgiv1 -=1;           }
          if (turn == 2) {            tgiv2 -=1;           }
          if (turn == 3) {            tgiv3 -=1;           }
          if (turn == 4) {            tgiv4 -=1;           }
          if (turn == 5) {            tgiv1 -=1;           }
          if (turn == 6) {            tgiv1 -=1;           }
          //if at start up turn +=1;
        }
        if ((d1o == turn) && (xloc == 45) && (yloc == 3) && (ab.pressed(B_BUTTON))&& ab.everyXFrames(10)) {
          d1 += 1;
          troo = d1;
          if (turn == 1) {            tgiv1 -=1;           }
          if (turn == 2) {            tgiv2 -=1;           }
          if (turn == 3) {            tgiv3 -=1;           }
          if (turn == 4) {            tgiv4 -=1;           }
          if (turn == 5) {            tgiv1 -=1;           }
          if (turn == 6) {            tgiv1 -=1;           }
          //if at start up turn +=1;
        }
        if ((d2o == turn) && (xloc == 62) && (yloc == 10) && (ab.pressed(B_BUTTON))&& ab.everyXFrames(10)) {
          d2 += 1;
          troo = d2;
          if (turn == 1) {            tgiv1 -=1;           }
          if (turn == 2) {            tgiv2 -=1;           }
          if (turn == 3) {            tgiv3 -=1;           }
          if (turn == 4) {            tgiv4 -=1;           }
          if (turn == 5) {            tgiv1 -=1;           }
          if (turn == 6) {            tgiv1 -=1;           }
          //if at start up turn +=1;
        }
        if ((d3o == turn) && (xloc == 75) && (yloc == 9) && (ab.pressed(B_BUTTON))&& ab.everyXFrames(10)) {
          d3 += 1;
          troo = d3;
          if (turn == 1) {            tgiv1 -=1;           }
          if (turn == 2) {            tgiv2 -=1;           }
          if (turn == 3) {            tgiv3 -=1;           }
          if (turn == 4) {            tgiv4 -=1;           }
          if (turn == 5) {            tgiv1 -=1;           }
          if (turn == 6) {            tgiv1 -=1;           }
          //if at start up turn +=1;
        }
        if ((d4o == turn) && (xloc == 76) && (yloc == 20) && (ab.pressed(B_BUTTON))&& ab.everyXFrames(10)) {
          d4 += 1;
          troo = d4;
          if (turn == 1) {            tgiv1 -=1;           }
          if (turn == 2) {            tgiv2 -=1;           }
          if (turn == 3) {            tgiv3 -=1;           }
          if (turn == 4) {            tgiv4 -=1;           }
          if (turn == 5) {            tgiv1 -=1;           }
          if (turn == 6) {            tgiv1 -=1;           }
          //if at start up turn +=1;
        }
        if ((e1o == turn) && (xloc == 93) && (yloc == 8) && (ab.pressed(B_BUTTON))&& ab.everyXFrames(10)) {
          e1 += 1;
          troo = e1;
          if (turn == 1) {            tgiv1 -=1;           }
          if (turn == 2) {            tgiv2 -=1;           }
          if (turn == 3) {            tgiv3 -=1;           }
          if (turn == 4) {            tgiv4 -=1;           }
          if (turn == 5) {            tgiv1 -=1;           }
          if (turn == 6) {            tgiv1 -=1;           }
          //if at start up turn +=1;
        }
        if ((e2o == turn) && (xloc == 107) && (yloc == 7) && (ab.pressed(B_BUTTON))&& ab.everyXFrames(10)) {
          e2 += 1;
          troo = e2;
          if (turn == 1) {            tgiv1 -=1;           }
          if (turn == 2) {            tgiv2 -=1;           }
          if (turn == 3) {            tgiv3 -=1;           }
          if (turn == 4) {            tgiv4 -=1;           }
          if (turn == 5) {            tgiv1 -=1;           }
          if (turn == 6) {            tgiv1 -=1;           }
          //if at start up turn +=1;
        }
        if ((e3o == turn) && (xloc == 110) && (yloc == 15) && (ab.pressed(B_BUTTON))&& ab.everyXFrames(10)) {
          e3 += 1;
          troo = e3;
          if (turn == 1) {            tgiv1 -=1;           }
          if (turn == 2) {            tgiv2 -=1;           }
          if (turn == 3) {            tgiv3 -=1;           }
          if (turn == 4) {            tgiv4 -=1;           }
          if (turn == 5) {            tgiv1 -=1;           }
          if (turn == 6) {            tgiv1 -=1;           }
          //if at start up turn +=1;
        }
        if ((e4o == turn) && (xloc == 106) && (yloc == 29) && (ab.pressed(B_BUTTON))&& ab.everyXFrames(10)) {
          e4 += 1;
          troo = e4;
          if (turn == 1) {            tgiv1 -=1;           }
          if (turn == 2) {            tgiv2 -=1;           }
          if (turn == 3) {            tgiv3 -=1;           }
          if (turn == 4) {            tgiv4 -=1;           }
          if (turn == 5) {            tgiv1 -=1;           }
          if (turn == 6) {            tgiv1 -=1;           }
          //if at start up turn +=1;
        }
        if ((e5o == turn) && (xloc == 102) && (yloc == 35) && (ab.pressed(B_BUTTON))&& ab.everyXFrames(10)) {
          e5 += 1;
          troo = e5;
          if (turn == 1) {            tgiv1 -=1;           }
          if (turn == 2) {            tgiv2 -=1;           }
          if (turn == 3) {            tgiv3 -=1;           }
          if (turn == 4) {            tgiv4 -=1;           }
          if (turn == 5) {            tgiv1 -=1;           }
          if (turn == 6) {            tgiv1 -=1;           }
          //if at start up turn +=1;
        }
        if ((e6o == turn) && (xloc == 95) && (yloc == 19) && (ab.pressed(B_BUTTON))&& ab.everyXFrames(10)) {
          e6 += 1;
          troo = e6;
          if (turn == 1) {            tgiv1 -=1;           }
          if (turn == 2) {            tgiv2 -=1;           }
          if (turn == 3) {            tgiv3 -=1;           }
          if (turn == 4) {            tgiv4 -=1;           }
          if (turn == 5) {            tgiv1 -=1;           }
          if (turn == 6) {            tgiv1 -=1;           }
          //if at start up turn +=1;
        }
        if ((f1o == turn) && (xloc == 115) && (yloc == 37) && (ab.pressed(B_BUTTON))&& ab.everyXFrames(10)) {
          f1 += 1;
          troo = f1;
          if (turn == 1) {            tgiv1 -=1;           }
          if (turn == 2) {            tgiv2 -=1;           }
          if (turn == 3) {            tgiv3 -=1;           }
          if (turn == 4) {            tgiv4 -=1;           }
          if (turn == 5) {            tgiv1 -=1;           }
          if (turn == 6) {            tgiv1 -=1;           }
          //if at start up turn +=1;
        }
        if ((f2o == turn) && (xloc == 106) && (yloc == 45) && (ab.pressed(B_BUTTON))&& ab.everyXFrames(10)) {
          f2 += 1;
          troo = f2;
          if (turn == 1) {            tgiv1 -=1;           }
          if (turn == 2) {            tgiv2 -=1;           }
          if (turn == 3) {            tgiv3 -=1;           }
          if (turn == 4) {            tgiv4 -=1;           }
          if (turn == 5) {            tgiv1 -=1;           }
          if (turn == 6) {            tgiv1 -=1;           }
          //if at start up turn +=1;
        }
        if ((f3o == turn) && (xloc == 113) && (yloc == 46) && (ab.pressed(B_BUTTON))&& ab.everyXFrames(10)) {
          f3 += 1;
          troo = f3;
          if (turn == 1) {            tgiv1 -=1;           }
          if (turn == 2) {            tgiv2 -=1;           }
          if (turn == 3) {            tgiv3 -=1;           }
          if (turn == 4) {            tgiv4 -=1;           }
          if (turn == 5) {            tgiv1 -=1;           }
          if (turn == 6) {            tgiv1 -=1;           }
          //if at start up turn +=1;
        }
        if ((g1o == turn) && (xloc == 57) && (yloc == 24) && (ab.pressed(B_BUTTON))&& ab.everyXFrames(10)) {
          g1 += 1;
          troo = g1;
          if (turn == 1) {            tgiv1 -=1;           }
          if (turn == 2) {            tgiv2 -=1;           }
          if (turn == 3) {            tgiv3 -=1;           }
          if (turn == 4) {            tgiv4 -=1;           }
          if (turn == 5) {            tgiv1 -=1;           }
          if (turn == 6) {            tgiv1 -=1;           }
          //if at start up turn +=1;
        }
        if ((g2o == turn) && (xloc == 66) && (yloc == 33) && (ab.pressed(B_BUTTON))&& ab.everyXFrames(10)) {
          g2 += 1;
          troo = g2;
          if (turn == 1) {            tgiv1 -=1;           }
          if (turn == 2) {            tgiv2 -=1;           }
          if (turn == 3) {            tgiv3 -=1;           }
          if (turn == 4) {            tgiv4 -=1;           }
          if (turn == 5) {            tgiv1 -=1;           }
          if (turn == 6) {            tgiv1 -=1;           }
          //if at start up turn +=1;
        }
        if ((g3o == turn) && (xloc == 65) && (yloc == 44) && (ab.pressed(B_BUTTON))&& ab.everyXFrames(10)) {
          g3 += 1;
          troo = g3;
          if (turn == 1) {            tgiv1 -=1;           }
          if (turn == 2) {            tgiv2 -=1;           }
          if (turn == 3) {            tgiv3 -=1;           }
          if (turn == 4) {            tgiv4 -=1;           }
          if (turn == 5) {            tgiv1 -=1;           }
          if (turn == 6) {            tgiv1 -=1;           }
          
          //if at start up turn +=1;
        }
        if ((g4o == turn) && (xloc == 75) && (yloc == 43) && (ab.pressed(B_BUTTON))&& ab.everyXFrames(10)) {
          g4 += 1;
          troo = g4;
          if (turn == 1) {            tgiv1 -=1;           }
          if (turn == 2) {            tgiv2 -=1;           }
          if (turn == 3) {            tgiv3 -=1;           }
          if (turn == 4) {            tgiv4 -=1;           }
          if (turn == 5) {            tgiv1 -=1;           }
          if (turn == 6) {            tgiv1 -=1;           }
          //if at start up turn +=1;
        }
        
      }
      
      // NORTH AMERICA
      // NORTH AMERICA
      if ((xloc == 4) && (yloc == 6) && ab.pressed(LEFT_BUTTON)&& ab.everyXFrames(30))  { //if at a1 and press left
        xloc = 107; //move to  e2
        yloc = 7;
        own = e2o; //what player owns terirory cursor is over
        troo = e1; // how many troopers are stationed there
      }
      if ((xloc == 13) && (yloc == 15) && ab.pressed(LEFT_BUTTON)&& ab.everyXFrames(29))  { //if at a2 and press left
        xloc = 4; //move to  a1
        yloc = 6;
        own = a1o; //what player owns terirory cursor is over
        troo = 11; // how many troopers are stationed there
      }
       if ((xloc == 22) && (yloc == 11) && ab.pressed(LEFT_BUTTON)&& ab.everyXFrames(28))  { //if at a3 and press left
        xloc = 13; //move to  a2
        yloc = 15;
        own = a2o; //what player owns terirory cursor is over
        troo = a2; // how many troopers are stationed there
      }
       if ((xloc == 30) && (yloc == 6) && ab.pressed(LEFT_BUTTON)&& ab.everyXFrames(27))  { //if at a4 and press left
        xloc = 22; //move to  a3
        yloc = 11;
        own = a3o; //what player owns terirory cursor is over
        troo = a3; // how many troopers are stationed there
      }
      // AFRICA
       if ((xloc == 75) && (yloc == 43) && ab.pressed(LEFT_BUTTON)&& ab.everyXFrames(13))  { //if at G4 and press LEFT
        xloc = 65; //move to  G3
        yloc = 44; 
        own = g3o; //what player owns terirory cursor is over
        troo = g3; // how many troopers are stationed there
      }
       if ((xloc == 57) && (yloc == 24) && ab.pressed(LEFT_BUTTON)&& ab.everyXFrames(13))  { //if at G1 and press LEFT
        xloc = 30; //move to  c2
        yloc = 38; 
        own = c2o; //what player owns terirory cursor is over
        troo = c2; // how many troopers are stationed there
      }
     //LEFT EUROPE D
     if ((xloc == 76) && (yloc == 20) && ab.pressed(LEFT_BUTTON)&& ab.everyXFrames(23))  { //if at D4 and press LEFT
        xloc = 57; //move to  G1
        yloc = 24;
        own = g1o; //what player owns terirory cursor is over
        troo = g1; // how many troopers are stationed there 
      }
      if ((xloc == 75) && (yloc == 9) && ab.pressed(LEFT_BUTTON)&& ab.everyXFrames(13))  { //if at D3 and press LEFT
        xloc = 62; //move to  D2
        yloc = 10; 
        own = d2o; //what player owns terirory cursor is over
        troo = d2; // how many troopers are stationed there
      }
      if ((xloc == 62) && (yloc == 10) && ab.pressed(LEFT_BUTTON)&& ab.everyXFrames(15))  { //if at D2 and press LEFT
        xloc = 45; //move to  D1
        yloc = 3; 
        own = d1o; //what player owns terirory cursor is over
        troo = d1; // how many troopers are stationed there
      }
      if ((xloc == 45) && (yloc == 3) && ab.pressed(LEFT_BUTTON)&& ab.everyXFrames(17))  { //if at D2 and press LEFT
        xloc = 30; //move to  A4
        yloc = 6; 
        own = a4o; //what player owns terirory cursor is over
        troo = a4; // how many troopers are stationed there
      }
      //ASIA LEFT
        if ((xloc == 107) && (yloc == 7) && ab.pressed(LEFT_BUTTON)&& ab.everyXFrames(19))  { //if at E2 and press LEFT
        xloc = 93; //move to  E1
        yloc = 8;
        own = e1o; //what player owns terirory cursor is over
        troo = e1; // how many troopers are stationed there
      }
        if ((xloc == 93) && (yloc == 8) && ab.pressed(LEFT_BUTTON)&& ab.everyXFrames(23))  { //if at E1 and press LEFT
        xloc = 75; //move to  D3
        yloc = 9;
        own = d3o; //what player owns terirory cursor is over
        troo = d3; // how many troopers are stationed there
      }
        if ((xloc == 95) && (yloc == 19) && ab.pressed(LEFT_BUTTON)&& ab.everyXFrames(17))  { //if at e6 and press LEFT
        xloc = 76; //move to  D4
        yloc = 20; 
        own = d4o; //what player owns terirory cursor is over
        troo = d4; // how many troopers are stationed there
      }
        if ((xloc == 110) && (yloc == 15) && ab.pressed(LEFT_BUTTON)&& ab.everyXFrames(18))  { //if at e3 and press LEFT
        xloc = 95; //move to  E6
        yloc = 19; 
        own = e6o; //what player owns terirory cursor is over
        troo = e6; // how many troopers are stationed there
      }
      if ((xloc == 106) && (yloc == 29) && ab.pressed(LEFT_BUTTON)&& ab.everyXFrames(18))  { //if at e4 and press LEFT
        xloc = 95; //move to  E6
        yloc = 19;
        own = e6o; //what player owns terirory cursor is over
        troo = e6; // how many troopers are stationed there 
      }
      //AUS LEFT
      if ((xloc == 113) && (yloc == 46) && ab.pressed(LEFT_BUTTON)&& ab.everyXFrames(18))  { //if at e4 and press LEFT
        xloc = 106; //move to F2
        yloc = 45; 
        own = f2o; //what player owns terirory cursor is over
        troo = f2; // how many troopers are stationed there
      }
    //RIGHT
    // NORTH AMERICA
      if ((xloc == 4) && (yloc == 6) && ab.pressed(RIGHT_BUTTON)&& ab.everyXFrames(26))  { //if at a1 and press right
        xloc = 13; //move to  a2
        yloc = 15;
        own = a2o; //what player owns terirory cursor is over
        troo = a2; // how many troopers are stationed there
      } // end if at a1 and right button pushed move to a2
    
      if ((xloc == 13) && (yloc == 15) && ab.pressed(RIGHT_BUTTON)&& ab.everyXFrames(25))  { //if at a2 and press right
        xloc = 22; //move to  a3
        yloc = 11;
        own = a3o; //what player owns terirory cursor is over
        troo = a3; // how many troopers are stationed there
        
      } 
       if ((xloc == 22) && (yloc == 11) && ab.pressed(RIGHT_BUTTON)&& ab.everyXFrames(24))  { //if at a3 and press right
        xloc = 30; //move to A4
        yloc = 6;
        own = a4o; //what player owns terirory cursor is over
        troo = a4; // how many troopers are stationed there
      }
       if ((xloc == 30) && (yloc == 6) && ab.pressed(RIGHT_BUTTON)&& ab.everyXFrames(23))  { //if at a4 and press right
        xloc = 45; //move to  D1
        yloc = 3;
        own = d1o; //what player owns terirory cursor is over
        troo = d1; // how many troopers are stationed there
      }      
      // ASIA
        if ((xloc == 107) && (yloc == 7) && ab.pressed(RIGHT_BUTTON)&& ab.everyXFrames(22))  { //if at e2 and press right
        xloc = 4; //move to  a1
        yloc = 6; 
        own = a1o; //what player owns terirory cursor is over
        troo = a1; // how many troopers are stationed there
      }
       if ((xloc == 93) && (yloc == 8) && ab.pressed(RIGHT_BUTTON)&& ab.everyXFrames(19))  { //if at E1 and press right
        xloc = 107; //move to  E2
        yloc = 7;
        own = e2o; //what player owns terirory cursor is over
        troo = e2; // how many troopers are stationed there
      }      
    //SOUTH AMERICA
       if ((xloc == 30) && (yloc == 38) && ab.pressed(RIGHT_BUTTON)&& ab.everyXFrames(27))  { //if at c2 and press left
        xloc = 57; //move to  g1
        yloc = 24;
        own = g1o; //what player owns terirory cursor is over
        troo = g1; // how many troopers are stationed there
      }
    // AFRICA
      if ((xloc == 65) && (yloc == 44) && ab.pressed(RIGHT_BUTTON)&& ab.everyXFrames(13))  { //if at G3 and press RIGHT
        xloc = 75; //move to  G4
        yloc = 43; 
        own = g4o; //what player owns terirory cursor is over
        troo = g4; // how many troopers are stationed there
      }
       if ((xloc == 66) && (yloc == 33) && ab.pressed(RIGHT_BUTTON)&& ab.everyXFrames(20))  { //if at G2 and press RIGHT
        xloc = 76; //move to  d4
        yloc = 20;
        own = d4o; //what player owns terirory cursor is over
        troo = d4; // how many troopers are stationed there 
      }
       if ((xloc == 57) && (yloc == 24) && ab.pressed(RIGHT_BUTTON)&& ab.everyXFrames(20))  { //if at G1 and press RIGHT
        xloc = 76; //move to  d4
        yloc = 20;
        own = d4o; //what player owns terirory cursor is over
        troo = d4; // how many troopers are stationed there  
      }
    //EUROPE RIGHT
        if ((xloc == 45) && (yloc == 3) && ab.pressed(RIGHT_BUTTON)&& ab.everyXFrames(15))  { //if at D1 and press right
        xloc = 62; //move to  D2
        yloc = 10;
        own = d2o; //what player owns terirory cursor is over
        troo = d2; // how many troopers are stationed there 
      }
       if ((xloc == 62) && (yloc == 10) && ab.pressed(RIGHT_BUTTON)&& ab.everyXFrames(19))  { //if at D2 and press right
        xloc = 75; //move to  D3
        yloc = 9;
        own = d3o; //what player owns terirory cursor is over
        troo = d3; // how many troopers are stationed there 
      }
        if ((xloc == 75) && (yloc == 9) && ab.pressed(RIGHT_BUTTON)&& ab.everyXFrames(10))  { //if at D3 and press right
        xloc = 93; //move to  E1
        yloc = 8;
        own = e1o; //what player owns terirory cursor is over
        troo = e1; // how many troopers are stationed there 
      }  
       if ((xloc == 76) && (yloc == 20) && ab.pressed(RIGHT_BUTTON)&& ab.everyXFrames(15))  { //if at D4 and press right
        xloc = 95; //move to  E6
        yloc = 19;
        own = e6o; //what player owns terirory cursor is over
        troo = e6; // how many troopers are stationed there 
      }  
      //ASIA RIGHT
      if ((xloc == 95) && (yloc == 19) && ab.pressed(RIGHT_BUTTON)&& ab.everyXFrames(15))  { //if at E6 and press right
        xloc = 110; //move to  E3 JAPAN
        yloc = 15;
        own = e3o; //what player owns terirory cursor is over
        troo = e3; // how many troopers are stationed there 
      }
      if ((xloc == 106) && (yloc == 29) && ab.pressed(RIGHT_BUTTON)&& ab.everyXFrames(15))  { //if at E4 and press right
        xloc = 115; //move to  F1? 
        yloc = 37;
        own = f1o; //what player owns terirory cursor is over
        troo = f1; // how many troopers are stationed there 
      }
      //AUS RIGHT
      if ((xloc == 106) && (yloc == 45) && ab.pressed(RIGHT_BUTTON)&& ab.everyXFrames(15))  { //if at F2 and press right
        xloc = 113; //move to  F3? 
        yloc = 46;
        own = f3o; //what player owns terirory cursor is over
        troo = f3; // how many troopers are stationed there 
      }
      
      //UP
   
      // CENTRAL AMERICA UP
       if ((xloc == 13) && (yloc == 26) && ab.pressed(UP_BUTTON)&& ab.everyXFrames(22))  { //if at b1 and press UP
        xloc = 13; //move to  a2
        yloc = 15; 
        own = a2o; //what player owns terirory cursor is over
        troo = a2; // how many troopers are stationed there 
      }
        if ((xloc == 17) && (yloc == 31) && ab.pressed(UP_BUTTON)&& ab.everyXFrames(21))  { //if at b2 and press UP
        xloc = 13; //move to  B1
        yloc = 26; 
        own = b1o; //what player owns terirory cursor is over
        troo = b1; // how many troopers are stationed there 
      }
      // SOUTH AMERICA UP
      if ((xloc == 28) && (yloc == 49) && ab.pressed(UP_BUTTON)&& ab.everyXFrames(20))  { //if at C3 and press UP
        xloc = 30; //move to C2
        yloc = 38; 
        own = c2o; //what player owns terirory cursor is over
        troo = c2; // how many troopers are stationed there 
      }
      if ((xloc == 30) && (yloc == 38) && ab.pressed(UP_BUTTON)&& ab.everyXFrames(19))  { //if at C2 and press UP
        xloc = 24; //move to C1
        yloc = 32;
        own = c1o; //what player owns terirory cursor is over
        troo = c1; // how many troopers are stationed there  
      }
      if ((xloc == 24) && (yloc == 32) && ab.pressed(UP_BUTTON)&& ab.everyXFrames(18))  { //if at c1 and press UP
        xloc = 17; //move to b2
        yloc = 31; 
        own = b2o; //what player owns terirory cursor is over
        troo = b2; // how many troopers are stationed there 
      }
      //AFRICA UP
       if ((xloc == 65) && (yloc == 44) && ab.pressed(UP_BUTTON)&& ab.everyXFrames(20))  { //if at G3 and press UP
        xloc = 66; //move to G2
        yloc = 33; 
        own = g2o; //what player owns terirory cursor is over
        troo = g2; // how many troopers are stationed there 
      }
       if ((xloc == 66) && (yloc == 33) && ab.pressed(UP_BUTTON)&& ab.everyXFrames(25))  { //if at G2 and press UP
        xloc = 57; //move to G1
        yloc = 24; 
        own = g1o; //what player owns terirory cursor is over
        troo = g1; // how many troopers are stationed there 
      }
      //EUROPE UP
      if ((xloc == 76) && (yloc == 20) && ab.pressed(UP_BUTTON)&& ab.everyXFrames(25))  { //if at D4 and press UP
        xloc = 75; //move to D3
        yloc = 9; 
        own = d3o; //what player owns terirory cursor is over
        troo = d3; // how many troopers are stationed there 
      }
      
      //ASIA UP
      // JAPAN UP
      if ((xloc == 110) && (yloc == 15) && ab.pressed(UP_BUTTON)&& ab.everyXFrames(28))  { //if at E3 and press UP
        xloc = 107; //move to E2
        yloc = 7; 
        own = e2o; //what player owns terirory cursor is over
        troo = e2; // how many troopers are stationed there 
      }
      if ((xloc == 102) && (yloc == 35) && ab.pressed(UP_BUTTON)&& ab.everyXFrames(28))  { //if at E5 and press UP
        xloc = 95; //move to E6
        yloc = 19; 
        own = e6o; //what player owns terirory cursor is over
        troo = e6; // how many troopers are stationed there 
      }
     if ((xloc == 106) && (yloc == 29) && ab.pressed(UP_BUTTON)&& ab.everyXFrames(28))  { //if at E4 and press UP
        xloc = 110; //move to E3
        yloc = 15;
        own = e3o; //what player owns terirory cursor is over
        troo = e3; // how many troopers are stationed there  
      }
      // AUS UP
      if ((xloc == 106) && (yloc == 45) && ab.pressed(UP_BUTTON)&& ab.everyXFrames(25))  { //if at F2 and press UP
        xloc = 102; //move to E5
        yloc = 35; 
        own = e5o; //what player owns terirory cursor is over
        troo = e5; // how many troopers are stationed there 
      }
      if ((xloc == 95) && (yloc == 19) && ab.pressed(UP_BUTTON)&& ab.everyXFrames(24))  { //if at E6 and press UP
        xloc = 93; //move to E1
        yloc = 8; 
        own = e1o; //what player owns terirory cursor is over
        troo = e1; // how many troopers are stationed there 
      }
       if ((xloc == 113) && (yloc == 46) && ab.pressed(UP_BUTTON)&& ab.everyXFrames(25))  { //if at F3 and press UP
        xloc = 115; //move to F1
        yloc = 37; 
        own = f1o; //what player owns terirory cursor is over
        troo = f1; // how many troopers are stationed there 
      }
      if ((xloc == 115) && (yloc == 37) && ab.pressed(UP_BUTTON)&& ab.everyXFrames(24))  { //if at F1 and press UP
        xloc = 106; //move to e4
        yloc = 29; 
        own = e4o; //what player owns terirory cursor is over
        troo = e4; // how many troopers are stationed there 
      }
    // DOWN
    //DOWN
    //NORTH AMERICA
       if ((xloc == 13) && (yloc == 15) && ab.pressed(DOWN_BUTTON)&& ab.everyXFrames(17))  { //if at a2 and press down
        xloc = 13; //move to  b1
        yloc = 26; 
        own = b1o; //what player owns terirory cursor is over
        troo = b1; // how many troopers are stationed there 
      }
       if ((xloc == 13) && (yloc == 26) && ab.pressed(DOWN_BUTTON)&& ab.everyXFrames(16))  { //if at B1 and press down
        xloc = 17; //move to  b2
        yloc = 31;
        own = b2o; //what player owns terirory cursor is over
        troo = b2; // how many troopers are stationed there  
      }
      if ((xloc == 17) && (yloc == 31) && ab.pressed(DOWN_BUTTON)&& ab.everyXFrames(15))  { //if at B2 and press down
        xloc = 24; //move to  C1
        yloc = 32; 
        own = c1o; //what player owns terirory cursor is over
        troo = c1; // how many troopers are stationed there 
      }
      //SOUTH AMERICA
      if ((xloc == 24) && (yloc == 32) && ab.pressed(DOWN_BUTTON)&& ab.everyXFrames(14))  { //if at C1 and press down
        xloc = 30; //move to  C2
        yloc = 38; 
        own = c2o; //what player owns terirory cursor is over
        troo = c2; // how many troopers are stationed there 
      }
      if ((xloc == 30) && (yloc == 38) && ab.pressed(DOWN_BUTTON)&& ab.everyXFrames(13))  { //if at C2 and press down
        xloc = 28; //move to  C3
        yloc = 49;
        own = c3o; //what player owns terirory cursor is over
        troo = c3; // how many troopers are stationed there  
      }
      // AFRICA
      if ((xloc == 57) && (yloc == 24) && ab.pressed(DOWN_BUTTON)&& ab.everyXFrames(15))  { //if at G1 and press down
        xloc = 66; //move to  G2
        yloc = 33; 
        own = g2o; //what player owns terirory cursor is over
        troo = g2; // how many troopers are stationed there 
      }
       if ((xloc == 66) && (yloc == 33) && ab.pressed(DOWN_BUTTON)&& ab.everyXFrames(17))  { //if at G1 and press down
        xloc = 65; //move to  G3
        yloc = 44;
        own = g3o; //what player owns terirory cursor is over
        troo = g3; // how many troopers are stationed there  
      }
    //END AFRICA DOWN
    //EUROPE DOWN
     if ((xloc == 75) && (yloc == 9) && ab.pressed(DOWN_BUTTON)&& ab.everyXFrames(17))  { //if at D3 and press down
        xloc = 76; //move to  D4
        yloc = 20;
        own = d4o; //what player owns terirory cursor is over
        troo = d4; // how many troopers are stationed there  
      }
     if ((xloc == 76) && (yloc == 20) && ab.pressed(DOWN_BUTTON)&& ab.everyXFrames(17))  { //if at D4 and press down
        xloc = 66; //move to  g2
        yloc = 33; 
        own = g2o; //what player owns terirory cursor is over
        troo = g2; // how many troopers are stationed there 
      }
      //ASIA DOWN
      //E1 TO E6
      if ((xloc == 93) && (yloc == 8) && ab.pressed(DOWN_BUTTON)&& ab.everyXFrames(26))  { //if at E1 and press DOWN
        xloc = 95; //move to E6
        yloc = 19; 
        own = e6o; //what player owns terirory cursor is over
        troo = e6; // how many troopers are stationed there 
      }
      //E2 TO JAPAN
      if ((xloc == 107) && (yloc == 7) && ab.pressed(DOWN_BUTTON)&& ab.everyXFrames(26))  { //if at E2 and press DOWN
        xloc = 110; //move to E3
        yloc = 15; 
        own = e3o; //what player owns terirory cursor is over
        troo = e3; // how many troopers are stationed there 
      }
      //E3 TO E4
      if ((xloc == 110) && (yloc == 15) && ab.pressed(DOWN_BUTTON)&& ab.everyXFrames(25))  { //if at E3 and press DOWN
        xloc = 106; //move to E4
        yloc = 29; 
        own = e4o; //what player owns terirory cursor is over
        troo = e4; // how many troopers are stationed there 
      }
      //E5 TO E5
      if ((xloc == 106) && (yloc == 29) && ab.pressed(DOWN_BUTTON)&& ab.everyXFrames(24))  { //if at E1 and press DOWN
        xloc = 102; //move to E5
        yloc = 35; 
        own = e5o; //what player owns terirory cursor is over
        troo = e5; // how many troopers are stationed there 
      }
      //E6 TO E5
      if ((xloc == 95) && (yloc == 19) && ab.pressed(DOWN_BUTTON)&& ab.everyXFrames(25))  { //if at E5 and press DOWN
        xloc = 102; //move to E6
        yloc = 35; 
        own = e6o; //what player owns terirory cursor is over
        troo = e6; // how many troopers are stationed there 
      }
      //E5 TO  F2?
    if ((xloc == 102) && (yloc == 35) && ab.pressed(DOWN_BUTTON)&& ab.everyXFrames(24))  { //if at E5 and press DOWN
        xloc = 106; //move to F2?
        yloc = 45; 
        own = f2o; //what player owns terirory cursor is over
        troo = f2; // how many troopers are stationed there 
      }
      //AUS DOWN
      if ((xloc == 115) && (yloc == 37) && ab.pressed(DOWN_BUTTON)&& ab.everyXFrames(20))  { //if at F1 and press DOWN
        xloc = 113; //move to F3?
        yloc = 46;
        own = f3o; //what player owns terirory cursor is over
        troo = f3; // how many troopers are stationed there  
      }
    ab.drawBitmap((0), (0), mapyo, 128, 54, WHITE);
    ab.setCursor((0), (35));
      ab.print("T");
      ab.setCursor((10), (35));
      ab.print(turn); //whos turn it is
      ab.setCursor((0), (45));
      ab.print("P");
      ab.setCursor((10), (45));
      ab.print(own); //what player owns that teritory    
      ab.setCursor((0), (55));
      ab.print(troo); //how many troopers are stationed there
      ab.setCursor((xloc), (yloc)); // cursor
      ab.print(turn);
      if (turn == 1) {
        tgivx = tgiv1;
        
      }
      if (turn == 2) {
        tgivx = tgiv2;
      }
      if (turn == 3) {
        tgivx = tgiv3;
      }
      if (turn == 4) {
        tgivx = tgiv4;
      }
      if (turn == 5) {
        tgivx = tgiv5;
      }
      if (turn == 6) {
        tgivx = tgiv6;
      }
     if ((tergiv >= 1) && (tgivx >= 1)) {
        
      ab.setCursor((90), (50));
      ab.print(tgivx);
       //do nothing eh
      }
      
      
    }
    if (gamestate == 3) { //pause screen
      ab.setCursor((70), (50));
      ab.print("pause");
if (ab.pressed(B_BUTTON)) {
        ab.clear();
        gamestate -= 1;
      }
    }
    if (gamestate == 4) {
     //win screen
     if (ab.pressed(A_BUTTON)) {
        ab.clear();
        gamestate = 0;
      }
    }
    if (gamestate == 5) {
    // table flip
    if (ab.pressed(A_BUTTON)) {
        ab.clear();
        gamestate = 0;
      }
    
    }
    ab.display();
}
