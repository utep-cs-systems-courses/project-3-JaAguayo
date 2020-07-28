#include <msp430.h>
#include "switches.h"
#include "led.h"
#include "buzzer.h"
#include "stateMachines.h"
#include <lcdutils.h>
#include <lcddraw.h>
#include "display.h"

int redrawScreen;

void drawCyanTriangle(){
  int j;
  for(j=30;j<60;j++){
    int row = j;
    for (int col = j; col < 100-j;col++)
      drawPixel(col+15,row+30,COLOR_CYAN);
  }
}

void flagShape(){
  int i,j;
  
   for(i=0;i<20;i++){
      for(j=0;j<i;j++){
	drawPixel(i+30,j+50,COLOR_RED);
      }
   }

   for (i=20;i<20+50;i++){
     for (j=5;j>1;j--){
       drawPixel(i+30,j+50,COLOR_WHITE);
     }
   }
}

void drawRect(){
  fillRectangle(37,22,57,47,COLOR_RED);
  fillRectangle(42,27,47,37,COLOR_YELLOW);
}

void drawInit(){
  redrawScreen=1;
  clearScreen(COLOR_FOREST_GREEN);

  drawString5x7(10,30,"Comp Arch1 SU 2020",COLOR_VIOLET,COLOR_BLACK);
  drawString8x12(10,40,"PROJECT 3",COLOR_VIOLET,COLOR_BLACK);
  redrawScreen = 1;
}

void clearWindow(){
  clearScreen(COLOR_BLACK);
  // redrawScreen = 1;
}
