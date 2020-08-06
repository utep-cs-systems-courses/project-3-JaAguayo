#include <msp430.h>
#include "stateMachinesAssem.h"
#include "led.h"
#include "switches.h"
#include "libTimer.h"

void
__interrupt_vec(WDT_VECTOR) WDT(){
  static short count = 0;
  //P1OUT |= LED_GREEN;
  
  count ++;
  if (count == 125){ 
    state_advance();
    count = 0;
  }
  if (blink){  //for blink of the led
    if (count == 5){
      state_advance();
      count = 0;
    }
  }
  P1OUT &= ~LED_GREEN;
}
