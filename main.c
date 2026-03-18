#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pico/stdlib.h"
#include "hardware/clocks.h"

#define PICO_OVERCLOCK_HZ 250000
#define GPIO_PIN_PWM 4


int main()
{
  set_sys_clock_khz(PICO_OVERCLOCK_HZ, true);
   
  stdio_init_all();

  gpio_set_function(GPIO_PIN_PWM, GPIO_FUNC_PWM);

  gpio_set_drive_strength(GPIO_PIN_PWM, 2);

  gpio_set_slew_rate(GPIO_PIN_PWM, 1);
  
  while(1);
}
