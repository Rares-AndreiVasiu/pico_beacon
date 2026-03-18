#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pico/stdlib.h"
#include "pico/multicore.h"
#include "hardware/clocks.h"
#include "hardware/pwm.h"
#include "hardware/timer.h"

#define PICO_OVERCLOCK_HZ 250000
#define GPIO_PIN_PWM 4
#define WRAP_VALUE 5
#define CLOCK_DIVISION 1.0f
#define DEFAULT_DUTY 3
#define ALARM_NUM 0
#define ALARM_IRQ TIMER_IRQ_0
#define DELAY 1000

uint slice;

unsigned int counter;

unsigned int state;

static void alarm_irq(void)
{
  hw_clear_bits(&timer_hw -> intr, 1u << ALARM_NUM);

  timer_hw -> alarm[ALARM_NUM] = timer_hw -> timerawl + DELAY;

  if (1000 > counter) 
  {
    if (state) 
    {
      pwm_set_chan_level(slice, PWM_CHAN_A, DEFAULT_DUTY);
    
      state = 0;
    }
    else 
    {
      pwm_set_chan_level(slice, PWM_CHAN_A, 0);
    
      state = 1;
    }
  }
  else 
  {
    if (2000 > counter) 
    {
      pwm_set_chan_level(slice, PWM_CHAN_A, DEFAULT_DUTY);
    }
    else 
    {
      counter = 0;
    }
  }
  counter += 1;
}

int main()
{
  set_sys_clock_khz(PICO_OVERCLOCK_HZ, true);
   
  stdio_init_all();

  gpio_set_function(GPIO_PIN_PWM, GPIO_FUNC_PWM);

  gpio_set_drive_strength(GPIO_PIN_PWM, 3);

  gpio_set_slew_rate(GPIO_PIN_PWM, 1);

  slice = pwm_gpio_to_slice_num(GPIO_PIN_PWM);
  
  pwm_set_wrap(slice, WRAP_VALUE);
  
  pwm_set_clkdiv(slice, CLOCK_DIVISION);

  pwm_set_chan_level(slice, PWM_CHAN_A, DEFAULT_DUTY);

  pwm_set_mask_enabled((1u << slice));

  hw_set_bits(&timer_hw->inte, 1u << ALARM_NUM);

  irq_set_exclusive_handler(ALARM_IRQ, alarm_irq);

  irq_set_enabled(ALARM_IRQ, true);

  timer_hw->alarm[ALARM_NUM] = timer_hw->timerawl + DELAY;
   
  while(1)
  {

  }
}

