cmake_minimum_required(VERSION 3.13)

project(malha_led)

add_library(malha_led malha_led.c malha_led.h)

pico_generate_pio_header(malha_led ${CMAKE_CURRENT_LIST_DIR}/ws2818b.pio)

target_link_libraries(malha_led 
    pico_stdlib
    hardware_pio
)