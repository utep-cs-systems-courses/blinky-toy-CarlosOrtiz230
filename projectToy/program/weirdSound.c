#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"
#include "led.h"

void weirdSound()
{
  // int secondCount;
  //  secondCount ++;
  // if (secondCount >= 250) {
  // secondCount = 0;	       
    P1OUT ^= LED_GREEN;	       
    //   }
    
}
