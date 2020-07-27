#include <msp430.h>
#include "switches.h"
#include "led.h"
#include "buzzer.h"
#include "stateMachines.h"
#include "lcdutils.h"
#include "lcddraw.h"
#include "display.h"

char switch_state_changed,switch_state_down;
int redrawScreen;

static char
switch_update_interrupt_sense(){
  char p2val = P2IN;
  P2IES |= (p2val & SWITCHES);
  P2IES &= (p2val | ~SWITCHES);
  return p2val;
}

void
switch_init(){
  P2REN |= SWITCHES;
  P2IE = SWITCHES;
  P2OUT |= SWITCHES;
  P2DIR &= ~SWITCHES;
  switch_update_interrupt_sense();
}

void
switch_interrupt_handler(){
  char p2val = switch_update_interrupt_sense();

  if (p2val & SW1 ? 0 : 1){
    switch_state_changed = 1;
    redrawScreen = 1;
  }

  else if (p2val & SW2 ? 0 : 1){
    switch_state_changed = 2;
    redrawScreen = 1;
  }

  else if (p2val & SW3 ? 0 : 1){
    switch_state_changed = 3;
    redrawScreen  = 1;
  }

  else if (p2val & SW4 ? 0 : 1){
    switch_state_changed = 4;
    redrawScreen = 0;
  }
  else{
    clearWindow();
    switch_state_changed = 0;
  }
}