#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"
int main() {
  
  configureClocks();

  buzzer_init();
  int i = 0;
  while(1){
    if(i%2==0){
      buzzer_set_period(500);/* start buzzing!!! 2MHz/1000 = 2kHz*/
      continue;
    }
    buzzer_set_period(1000);/* start buzzing!!! 2MHz/1000 = 2kHz*/
    i++;
  }
  or_sr(0x18);          // CPU off, GIE on
}

