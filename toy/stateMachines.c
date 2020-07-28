#include <msp430.h>
#include <libTimer.h>
#include "stateMachines.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"
#include <lcdutils.h>
#include <lcddraw.h>

void state_advance(int state){
  switch(state){
  case 1:
    clearWindow();
    drawCyanTriangle();
    beep();
    greenLights();
    state = 0;
    break;
  case 2:
    clearWindow();
    drawRect();
    song();
    dimRed();
    state = 0;
    break;
  case 3:
    clearWindow();
    flagShape();
    errorSong();
    redLights();
    state = 0;
    break;
  case 4:
    drawInit();
    buzzer_off();
    state = 0;
    break;
  default:
    break;
  }
}
