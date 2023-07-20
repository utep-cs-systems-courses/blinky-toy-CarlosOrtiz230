#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"
#define LED_GREEN BIT0
#define LED_RED BIT6
#define LEDS (BIT0|BIT6) //

#define SW1 BIT3		/* switch1 is p1.3 */
#define SWITCHES SW1		/* only msp swtich */



int main() {
  configureClocks();

   P1DIR |= LEDS;
   P1OUT &= ~LEDS;		/* leds initially off */
  
     
  P1REN |= SWITCHES;		/* enables resistors for switches */
  P1IE |= SWITCHES;		/* enable interrupts from switches */
  P1OUT |= SWITCHES;		/* pull-ups for switches */
  P1DIR &= ~SWITCHES;		/* set switches' bits for input */

   buzzer_init();

   initialState();
   or_sr(0x18);          // CPU off, GIE on
}

void initialState(){  //first state of state machine
   char p1val = P1IN;
  if (p1val & SW1) {
      firstBotton();
   } else {
     initialState();
   } 
}


void crazySound(){
   char p1val = P1IN;
  //sound periords
  
  while (1) {
    //GREEN OFF AND RED ON
    
    P1OUT |= LED_RED;
    P1OUT &= ~LED_GREEN;
    // Reproduce el primer sonido
    buzzer_set_period(9000);    // 2kHz
    __delay_cycles(100000000);    // Espera un tiempo
    // Reproduce el segundo sonido    buzzer_set_period(500);    // 1kHz
    __delay_cycles(10000000);// Espera un tiempo

    //green ON red OFF
    P1OUT |= LED_GREEN;
    P1OUT &= ~LED_RED;
    
    if (p1val & SW1) {
     continue;
   } else {
      break;
   } 
  } 
}

void firstBotton(){
  char p1val = P1IN;		/* switch is in P1 */

/* update switch interrupt sense to detect changes from current buttons */
  P1IES |= (p1val & SWITCHES);	/* if switch up, sense down */
  P1IES &= (p1val | ~SWITCHES);	/* if switch down, sense up */

/* up=red, down=green */
  if (p1val & SW1) {
    P1OUT |= LED_RED;
    P1OUT &= ~LED_GREEN;
  } else {
    crazySound();
  
 }
  initialState();
}
