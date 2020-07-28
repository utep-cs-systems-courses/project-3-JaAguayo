#ifndef led_included
#define led_included

#define LED_RED BIT6
#define LED_GREEN BIT0
#define LEDS (BIT0 | BIT6)

void led_init();
void led_update();
void redLights();
void greenLights();
void dimLights();
void dimRed();

extern unsigned char leds_changed,greenn_led_state,red_led_state;

#endif
