#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"

#define A3 2273
#define B3 2025
#define G3 2551
#define E3 3033
#define C3 3846
#define C4 1911
#define D4 1703
#define E4 1517
#define F4 1432
#define G4 1276
#define A4 1136
#define B4 1012
#define C5 956

void buzzer_init(){
  timerAUpmode();
  P2SEL2 &= ~(BIT6 | BIT7);
  P2SEL &= ~BIT7;
  P2SEL |= BIT6;
  P2DIR = BIT6;
}

void buzzer_set_period(short cycles){
  CCR0 = cycles;
  CCR1 = cycles >> 1;
}

void buzzer_off(){
  CCR0 = 0;
  CCR1 = 0;
}
  
void beep(){
  int sounds[] = {A4,0};

  for (int i =0;i<sizeof(sounds)/sizeof(*sounds);i++){
    buzzer_set_period(sounds[i]);
    __delay_cycles(1200000);
  }
}

void song(){
  int sounds[] = {A4,0,A3,0,E3,0,G3,0,F4,0,A4,0,A3,0,E3,0,G3,0,F4,0};

  for (int i =0;i<sizeof(sounds)/sizeof(*sounds);i++){
    buzzer_set_period(sounds[i]);
    __delay_cycles(1200000);
  }
}

void errorSong(){
  int sounds[] = {E4,0,E4,0,C5,0,C5,B4,B4,500,0};

  for (int i =0;i<sizeof(sounds)/sizeof(*sounds);i++){
    buzzer_set_period(sounds[i]);
    __delay_cycles(300000);
  }
}
