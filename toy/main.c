#include <msp430.h>
#include <libTimer.h>
#include "switches.h"
#include "led.h"
#include "buzzer.h"
#include "stateMachines.h"
#include <lcdutils.h>
#include <lcddraw.h>
#include "display.h"

int redrawScreen = 1;

int main(void){

  P1DIR |= LED_GREEN;
  P1OUT |= LED_GREEN;
  
  configureClocks();
  switch_init();
  buzzer_init();
  led_init();
  enableWDTInterrupts();
  lcd_init();
  drawInit();
  
  or_sr(0x18);

  for(;;){
    while(!redrawScreen){
      P1OUT &= ~LED_GREEN;
      or_sr(0x18);
    }
    P1OUT |= LED_GREEN;
    __delay_cycles(250000);
    redrawScreen = 0;
  }
}
