#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pico/stdlib.h"
#include "pico/multicore.h""
#include "hardware/clocks.h"

#define PICO_OVERCLOCK_HZ 250000
#define GPIO_PIN_PWM 4

uint slice;

int main()
{
  set_sys_clock_khz(PICO_OVERCLOCK_HZ, true);
   
  stdio_init_all();

  gpio_set_function(GPIO_PIN_PWM, GPIO_FUNC_PWM);

  gpio_set_drive_strength(GPIO_PIN_PWM, 3);

  gpio_set_slew_rate(GPIO_PIN_PWM, 1);

  slice = pwm_gpio_to_slice_num(GPIO_PIN_PWM);
  
  pwm_set_wrap(slice_num, 5);
  
  pwm_set_clkdiv(slice_num, 1.0f);

  pwm_set_chan_level(slice_num, PWM_CHAN_A, 3);

  pwm_set_mask_enabled((1u << slice_num));
   
  while(1)
  {

  }
}
