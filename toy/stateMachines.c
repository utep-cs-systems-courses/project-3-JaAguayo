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
    clearScreen(COLOR_BLACK);
    drawCyanTriangle();
    beep();
    greenLights();
    state = 0;
    break;
  case 2:
    clearScreen(COLOR_BLACK);
    drawRect();
    song();
    dimLights();
    state = 0;
    break;
  case 3:
    clearScreen(COLOR_BLACK);
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
