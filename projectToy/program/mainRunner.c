#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"
#include "led.h"


int main() {
  configureClocks(); //sstarts timing from msp
  enableWDTInterrupts; //enables bottons
  //Lights are set to be off by default
  
  P1DIR |= LEDS; //output bits in msp to the bottom lights
  P1OUT &= ~LEDS;

  //enables resitors from bottom
  P1REN |= SWITCHES;
  P1IE |= SWITCHES; //interrupts are enabled

  P2REN |= TOPSW;
  P2IE |= TOPSW;

  
  buzzer_init();
 /* higher the pitch, the higher the number the lower the pitch */
  or_sr(0x18);          // CPU off, GIE on
}//main ends
  

//VECTORS THAT ALLOWS THE STATE MACHINE WDT

void stateMachine();
 
void __interrupt_vec(PORT2_VECTOR) Port_2(){
  if (P2IFG & TOPSW) {
    P2IFG &= ~TOPSW;
    stateMachine();
  }
}

/* Switch on P1 (S2) */

void __interrupt_vec(PORT1_VECTOR) Port_1(){
  if (P1IFG & SWITCHES) {    
      P1IFG &= ~SWITCHES;    
      stateMachine(); 
  }
}


void __interrupt_vec(WDT_VECTOR) WDT() {
   stateMachine();
}
