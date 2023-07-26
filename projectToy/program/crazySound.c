#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"
#include "led.h"

void crazySound() {
  int i = 0;
  while (1) {
    // Reproduce el primer sonido
    if (i % 2 == 0) {
      P1OUT |= LED_GREEN;         // Turn on green LED
      P1OUT &= ~LED_RED;          // Turn off red 
      buzzer_set_period(9000);    // 2kHz
    } else {
      P1OUT |= LED_RED;           // tURN ON RED led
      P1OUT &= ~LED_GREEN;        // tURN OFF GREEN led
      buzzer_set_period(500);
    }
    // Add a delay between sound patterns (adjust the value as needed)
    __delay_cycles(1000000); // This uses the built-in delay function for MSP430
    // Toggle i to switch between two frequencies
    i++;
  }
}
