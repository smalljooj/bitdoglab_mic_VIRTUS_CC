#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/adc.h"
#include "joystick/joystick.h"

int main()
{
    stdio_init_all();
    joystick_init();

    while (true) {
        printf("Raw value: %.2f - %.2f - %d\n", joystick_x(), joystick_y(), joystick_switch());
        sleep_ms(500);
    }
}
