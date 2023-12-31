#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"
int main() {
  
  configureClocks();

  buzzer_init();
  while (1) {

    // Reproduce el primer sonido

    buzzer_set_period(9000);    // 2kHz
    __delay_cycles(1000000);    // Espera un tiempo
    // Reproduce el segundo sonido
    buzzer_set_period(500);    // 1kHz
    __delay_cycles(1000000);    // Espera un tiempo
  }
  or_sr(0x18);          // CPU off, GIE on
}

