#include <msp430.h>
#include <libTimer.h>
#include "stateMachines.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"
#include "display.h"
#include <lcdutils.h>
#include <lcddraw.h>

void state_advance(){
  switch(state){
  case 1:
    clearWindow(); //clear screen each state so shapes dont overlap
    drawCyanTriangle();
    beep();
    greenLights();
    redrawScreen = 1;
    state = 0;
    break;
  case 2:
    clearWindow();
    drawRect();
    song();
    dimRed();
    redrawScreen = 1;
    state = 0;
    break;
  case 3:
    clearWindow();
    flagShape();
    errorSong();
    redLights();
    redrawScreen = 1;
    state = 0;
    break;
  case 4:
    drawInit();
    redrawScreen = 1;
    state = 0;
    break;
  default:
    break;
  }
}
