#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"
#include "led.h"

void toy_stateMachine(){
  char p1val = P1IN;            /* Detects input in the bottom board */
  char p2val = P2IN;/* Detects input in the top board */
  
  /* This entire state machine functions by detecting if any of the buttons are down.  If a certain
   button is down, that button's pattern will be initiated and will occur as long as that button is
   down. Otherwise, if no buttons are pressed, the toy will be in a default state. */

  /* Detects if TOPS1 (or S1 on the top board) is pressed.  If so, a pattern involving the green 
     light and buzzer will occur and the red light will remain off as long as the button is
     pressed down.  Otherwise, the toy will 
     remain in a default state. */

  if( p2val & TOPS1 ? 0 : 1 ){
    /* down=(Dim-to-bright) green LED and (Low-to-High) buzz */
    greenTimeAdvStateMachines();
    P1OUT &= ~LED_RED;
    /* Detects if TOPS2 (or S2 on the top board) is pressed.  If so, a pattern involving the red 
       light and buzzer will occur and the green light will remain off as long as the button is 
       pressed down.  Otherwise, the toy will remain in a default state. */

  } else if( p2val & TOPS2 ? 0 : 1){
    /* down=(Bright-to-dim) red LED and (High-to-Low) buzz*/
    redTimeAdvStateMachines();
    P1OUT &= ~LED_GREEN;

    /* Detects if TOPS3 (or S3 on the top board) is pressed.  If so, a pattern involving both 
       lights and the buzzer will occur as long as the button is pressed down.  Otherwise, the toy
       will remain in a default state. */
    
  } else if( p2val & TOPS3 ? 0 : 1){
    // A little song that corresponds with the lights.
    crazySound();
    /* Detects if TOPS4 (or S4 on the top board) is pressed.  If so, a pattern involving the buzzer
       will occur as long as the button is pressed down. Otherwise, the toy will remain in a 
       default state */

  } else if( p2val & TOPS4 ? 0 : 1){
    song2();
    /* Detects if SW1 (or P1.3 on the bottom board) is pressed.  If so, a pattern involving the
       buzzer and lights will occur as long as the button is pressed down.  Otherwise, the toy
       will remain in a default state.*/
  } else if (p1val & SW1 ? 0 : 1){
    /* A siren involving sound and lights, not unlike a police car siren.*/
    // siren();
  } else{
    /* Default state; Both lights are off and the buzzer emits a frequency so low that there is 
       virtually no sound. */
    buzzer_set_period(0);
    P1OUT &= ~LEDS;
  }
}
