#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"
#include "led.h"


int notes[] = {587, 880, 1047, 784};
// Function to control the LED dimming from brightest to dimmest

 

// Function to play the melody
void weirdSound() {
  int numNotes = sizeof(notes) / sizeof(notes[0]);
  // Repeat the melody and LED dimming effect four times
  for (int repeat = 0; repeat < 4; repeat++) {
    for (int i = 0; i < numNotes; i++) {
      buzzer_set_period(notes[i]);
          __delay_cycles(10000000);
    }
  }
  // Turn off the buzzer when the melody is done
  buzzer_set_period(0);
}
      
