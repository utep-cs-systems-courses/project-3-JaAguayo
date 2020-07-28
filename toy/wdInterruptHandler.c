#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "switches.h"

void
__interrupt_vec(WDT_VECTOR) WDT(){
  static char count = 0;
  P1OUT |= LED_GREEN;
  if (++count == 125){
    state_advance();
    count = 0;
  }
  if (blink){
    if (count == 5){
      state_advance();
      count = 0;
    }
  }
  P1OUT &= ~LED_GREEN;
}
