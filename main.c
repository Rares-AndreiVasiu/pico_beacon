#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pico/stdlib.h"
#include "pico/multicore.h""
#include "hardware/clocks.h"

#define PICO_OVERCLOCK_HZ 250000
#define GPIO_PIN_PWM 4
#define WRAP_VALUE 5
#define CLOCK_DIVISION 1.0f
#define DEFAULT_DUTY 3

uint slice;

int main()
{
  set_sys_clock_khz(PICO_OVERCLOCK_HZ, true);
   
  stdio_init_all();

  gpio_set_function(GPIO_PIN_PWM, GPIO_FUNC_PWM);

  gpio_set_drive_strength(GPIO_PIN_PWM, 3);

  gpio_set_slew_rate(GPIO_PIN_PWM, 1);

  slice = pwm_gpio_to_slice_num(GPIO_PIN_PWM);
  
  pwm_set_wrap(slice_num, WRAP_VALUE);
  
  pwm_set_clkdiv(slice_num, CLOCK_DIVISION);

  pwm_set_chan_level(slice_num, PWM_CHAN_A, DEFAULT_DUTY);

  pwm_set_mask_enabled((1u << slice_num));
   
  while(1)
  {

  }
}
