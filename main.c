#include <stdio.h> 
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/adc.h"
#include "joystick/joystick.h"
#include "mic/mic.h"
#include "malha_led/malha_led.h"

// Arrays storing LED pin mappings for each row of the 5x5 LED matrix
uint8_t led_1[5] = {4, 5, 14, 15, 24};
uint8_t led_2[5] = {3, 6, 13, 16, 23};
uint8_t led_3[5] = {2, 7, 12, 17, 22};
uint8_t led_4[5] = {1, 8, 11, 18, 21};
uint8_t led_5[5] = {0, 9, 10, 19, 20};

// Function prototype for displaying microphone samples on the LED matrix
void show_sample_matriz(float read, uint8_t sample_num);

int main()
{
    // Initialize standard I/O (UART)
    stdio_init_all();
    // Initialize joystick (presumably for additional controls)
    joystick_init();

    // Set up microphone sampling at 8000 samples per second
    init_mic(8000);
    // Record microphone data for 1 second
    record_mic(1);
    // Get a pointer to the buffer holding the recorded samples
    float* samples = get_samples_mic();

    // Initialize LED matrix
    npInit();

    float read; // Variable to store microphone readings

    // Infinite loop to continuously update LED matrix in real-time
    while (true) 
    {
        for(int i = 0; i < 5; i++)
        {
            // Get a new sample from the microphone
            read = read_mic();

            // Set LED color to green (R=0, G=15, B=0)
            set_cor(0, 15, 0);
            sleep_us(500); // Short delay for LED stabilization
            show_sample_matriz(read, i); // Update the corresponding row of LEDs
            npWrite(); // Render the LED matrix
        }
        sleep_ms(100); // 100ms pause before the next update cycle
        npClear(); // Clear all LEDs after each cycle
    }
    deinit_mic(); // Release microphone resources
}

// Maps microphone readings to LED matrix rows
void show_sample_matriz(float read, uint8_t sample_num)
{
    switch (sample_num)
    {
        case 0:
            if (read <= -0.5)
                npSetLED(led_1[0], 20); // Down
            else if (read <= -0.25)
                npSetLED(led_1[1], 20);
            else if (read <= 0.25)
                npSetLED(led_1[2], 20); // Center 
            else if (read <= 0.5)
                npSetLED(led_1[3], 20);
            else 
                npSetLED(led_1[4], 20); // Up
            break;
        case 1:
            if (read <= -0.5)
                npSetLED(led_2[0], 20);
            else if (read <= -0.25)
                npSetLED(led_2[1], 20);
            else if (read <= 0.25)
                npSetLED(led_2[2], 20);
            else if (read <= 0.5)
                npSetLED(led_2[3], 20);
            else 
                npSetLED(led_2[4], 20);
            break;
        case 2:
            if (read <= -0.5)
                npSetLED(led_3[0], 20);
            else if (read <= -0.25)
                npSetLED(led_3[1], 20);
            else if (read <= 0.25)
                npSetLED(led_3[2], 20);
            else if (read <= 0.5)
                npSetLED(led_3[3], 20);
            else 
                npSetLED(led_3[4], 20);
            break;
        case 3:
            if (read <= -0.5)
                npSetLED(led_4[0], 20);
            else if (read <= -0.25)
                npSetLED(led_4[1], 20);
            else if (read <= 0.25)
                npSetLED(led_4[2], 20);
            else if (read <= 0.5)
                npSetLED(led_4[3], 20);
            else 
                npSetLED(led_4[4], 20);
            break;
        case 4:
            if (read <= -0.5)
                npSetLED(led_5[0], 20);
            else if (read <= -0.25)
                npSetLED(led_5[1], 20);
            else if (read <= 0.25)
                npSetLED(led_5[2], 20);
            else if (read <= 0.5)
                npSetLED(led_5[3], 20);
            else 
                npSetLED(led_5[4], 20);
            break;
        default:
            break;
    }
}
