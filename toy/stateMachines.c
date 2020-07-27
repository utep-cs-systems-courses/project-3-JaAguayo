#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"
#include "lcdutils.h"
#include "lcddraw.h"

void state_advance(){
  switch(switch_state_changed){
  case 1:
    beep();
    greenLights();
    switch_state_changed = 0;
    break;
  case 2:
    song();
    dimLights();
    switch_state_changed = 0;
    break;
  case 3:
    errorSong();
    redLights();
    switch_state_changed = 0;
    break;
  case 4:
    buzzer_off();
    switch_state_changed = 0;
    break;
  default:
    break;
  }
}
