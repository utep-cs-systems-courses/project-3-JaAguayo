#include <msp430.h>
#include <shape.h>
#include "libTimer.h"
#include "switches.h"
#include "led.h"
#include "buzzer.h"
#include "stateMachines.h"
#include "lcdutils.h"
#include "lcddraw.h"
#include "display.h"

int redrawScreen = 1;

int main(void){

  P1DIR |= LED_GREEN;
  P1OUT |= LED_GREEN;
  
  configureClocks();
  clearScreen(COLOR_GREEN);
  switch_init();
  buzzer_init();
  led_init();
  enableWDTInterrupts();
  lcd_init();
  shapeInit();
  drawInit();

  or_sr(0x8);

  for(;;){
    while(!redrawScreen){
      P1OUT &= ~LED_GREEN;
      or_sr(0x10);
    }
    P1OUT |= LED_GREEN;
    __delay_cycles(30000);
    redrawScreen = 0;
  }

  void wdt_c_handler(){
    static short count = 0;
    count++;
    if (count == 125){
      state_advance();
      count = 0;
    }
  }
}
