cmake_minimum_required(VERSION 3.13)

project(mic)

add_library(mic mic.c mic.h)

target_link_libraries(mic
    pico_stdlib
    hardware_adc
    hardware_timer
)