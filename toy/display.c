#include <msp430.h>
#include "switches.h"
#include "led.h"
#include "buzzer.h"
#include "stateMachines.h"
#include "lcdutils.h"
#include "lcddraw.h"
#include "display.h"

int redrawScreen;

void drawCyanTriangle(){
  int j;
  for(j=30;j<60;j++){
    int row = j;
    for (int col = j; col < 100-j;col++)
      drawPixel(col+15,row,COLOR_CYAN);
  }
}

void drawRect(){
  fillRectangle(37,22,57,47,COLOR_RED);
  fillRectangle(42,27,47,37,COLOR_YELLOW);
}

void drawInit(){
  redrawScreen=1;
  clearScreen(COLOR_GREEN);

  drawString5x7(10,130,"Comp Arch1 SU 2020",COLOR_VIOLET,COLOR_BLACK);
  drawString8x12(10,140,"PROJECT 3",COLOR_VIOLET,COLOR_BLACK);
  redrawScreen = 1;
}

void clearWindow(){
  fillRectangle (37,22,57,47,COLOR_WHITE);
  redrawScreen = 1;
}
