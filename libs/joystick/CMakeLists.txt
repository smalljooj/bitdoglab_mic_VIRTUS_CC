cmake_minimum_required(VERSION 3.13)

project(joystick)

add_library(joystick joystick.c joystick.h)

target_link_libraries(joystick
    pico_stdlib
    hardware_adc
)