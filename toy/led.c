#include <msp430.h>
#include "led.h"
#include "stateMachines.h"
#include "buzzer.h"
#include "switches.c"

void led_init(){
  P1DIR |= LEDS;
}

void led_update(){
  if (switch_state_changed){
    char ledFlags = 0;
    ledFlags |= switch_state_down ? LED_RED : 0;
    ledFlags |= switch_state_down ? 0 : LED_GREEN;

    P1OUT &= (0xff - LEDS) | ledFlags;
    P1OUT |= ledFlags;
  }
  switch_state_changed = 0;
}

void greenLights(){
  for(int i=0;i<10;i++){
    P1OUT = LED_GREEN;
    __delay_cycles(800000);
    P1OUT = !LED_GREEN;
    __delay_cycles(800000);
  }
}

void redLights(){
  for(int i=0;i<10;i++){
    P1OUT = LED_RED;
    __delay_cycles(800000);
    P1OUT = !LED_RED;
    __delay_cycles(800000);
  }
}

void dimLights(){
  for(int j=0;j<10000;j++){
    P1OUT = LED_RED;
    P1OUT = !LED_RED;
  }
}
