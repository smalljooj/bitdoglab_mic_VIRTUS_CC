#include "joystick.h"
#include "pico/stdlib.h"
#include "hardware/adc.h"
#include "hardware/gpio.h"


volatile int16_t j_y = 0;
volatile int16_t j_x = 0;

void joystick_init()
{
    adc_init();
    adc_gpio_init(26);
    adc_gpio_init(27);
    gpio_init(22);
    gpio_set_dir(22, GPIO_IN);
    gpio_pull_up(22);
}

float joystick_x()
{
    adc_select_input(0);
    j_x = adc_read();
    j_x -= 2048;
    return j_x / 2048.0;
}

float joystick_y()
{
    adc_select_input(1);
    j_y = adc_read();
    j_y -= 2048;
    return j_y / 2048.0;
}

uint8_t joystick_switch()
{
    return gpio_get(22) ^ 0x01; 
}