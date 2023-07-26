#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"
#include "led.h"


void crazySound(){

  static int secondCount = 0;
  while(secondCount!=1000)
  {
     secondCount ++;
     if (secondCount%25==0) { /* once each sec... */
	 // P1OUT |= LED_GREEN;
	 // P1OUT &= ~LED_RED;
       buzzer_set_period(9000);
     }
    
     
     else {
       // P1OUT |= LED_RED;
       // P1OUT &= ~LED_GREEN;
       buzzer_set_period(500);
     }
  }//while
}

