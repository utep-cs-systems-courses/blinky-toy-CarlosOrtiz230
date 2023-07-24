#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"
#include "led.h"

void crazySound(){
  
  int i  = 0;
  while (1) {
    // Reproduce el primer sonido
    if(i%2==0){
      buzzer_set_period(9000);    // 2kHz
    }else{
      buzzer_set_period(500);
    }
    delay_cycle(1000000);
  }
}
