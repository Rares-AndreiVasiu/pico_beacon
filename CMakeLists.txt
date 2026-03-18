cmake_minimum_required(VERSION 3.17)

include(pico_sdk_import.cmake)

project(beacon C CXX ASM)

pico_sdk_init()

add_executable(beacon)

target_sources(beacon PRIVATE main.c)

target_link_libraries(beacon pico_stdlib pico_multicore pico_bootsel_via_double_reset hardware_pwm)

pico_add_extra_outputs(beacon)
