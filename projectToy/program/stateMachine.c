#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"
#include "led.h"

void toy_stateMachine(){
  char p1val = P1IN;            /* Detects input in the bottom board */
  char p2val = P2IN;/* Detects input in the top board */
  


  if( p2val & TOPS1 ? 0 : 1 ){
    /* down=(Dim-to-bright) green LED and (Low-to-High) buzz */
    //   greenTimeAdvStateMachines();
    P1OUT &= ~LED_RED;
 
  } else if( p2val & TOPS2 ? 0 : 1){
    /* down=(Bright-to-dim) red LED and (High-to-Low) buzz*/
    //    redTimeAdvStateMachines();
    P1OUT &= ~LED_GREEN;
    
  } else if( p2val & TOPS3 ? 0 : 1){
    // A little song that corresponds with the lights.
    crazySound();
   
  } else if( p2val & TOPS4 ? 0 : 1){
    //    song2();
  } else if (p1val & SW1 ? 0 : 1){
    // siren();
  } else{
    buzzer_set_period(0);
    P1OUT &= ~LEDS;
  }
}
