cmake_minimum_required(VERSION 3.5)
set(CMAKE_C_STANDARD 11)

# Pull in SDK (must be before project)
include(pico_sdk_import.cmake)

set(PICO_PLATFORM rp2040)
set(PICO_BOARD pico)

set(PROJECT pwm_controller_V1)

project(${PROJECT} C CXX)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

################################################################################
################################################################################
set(PWM_CONTROLLER pwm_controller)

add_compile_options(
    $<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>
    -fno-exceptions 
    -fno-check-new 
    $<$<COMPILE_LANGUAGE:CXX>:-fno-enforce-eh-specs>
    -g 
    -ffunction-sections 
    -fdata-sections 
    -O3
    -funroll-loops 
    -Werror
    -Wall
    -Wextra 
    # -Wconversion 
    -Wunreachable-code 
    -Wuninitialized 
    #    -Wno-error=conversion
    #    -Wno-error=unused-variable 
    -Wno-unused-parameter 
    -Wno-missing-field-initializers 
    #    -Wno-implicit-fallthrough
    #    -Wno-error=conversion 
    #    -Wno-error=float-conversion 
    #    -Wno-error=conversion-null 
    #    -Wno-error=pointer-arith 
    -Wno-format-truncation
)

file(GLOB_RECURSE sources      src/*.cpp src/include/*.hpp src/device/*.cpp src/device/include/*.hpp modules/*/include/*.hpp modules/*/src/*.cpp)
add_executable(${PWM_CONTROLLER} ${sources} ) 

include_directories("${CMAKE_SOURCE_DIR}/src/" "${CMAKE_SOURCE_DIR}/src/include/" "${CMAKE_SOURCE_DIR}/src/device/" "${CMAKE_SOURCE_DIR}/src/device/include/" "${CMAKE_SOURCE_DIR}/src/modules/*/src/" "${CMAKE_SOURCE_DIR}/src/modules/*/include/")


pico_generate_pio_header(${PWM_CONTROLLER} ${CMAKE_CURRENT_LIST_DIR}/src/uart.pio)

add_compile_definitions(DEBUG)

target_compile_options(${PWM_CONTROLLER} PRIVATE -Os)
target_link_libraries(${PWM_CONTROLLER} pico_stdlib hardware_watchdog hardware_flash hardware_pio hardware_uart hardware_irq hardware_adc pico_multicore hardware_pwm)

pico_add_hex_output(${PWM_CONTROLLER})
pico_add_bin_output(${PWM_CONTROLLER})


# Use a separate linker script for the application to make sure it is built
# to run at the right location (after the flashloader).
# Tell the linker to use pages no bigger than 4k or the UF2 generation from
# the ELF image has issues
# (see https://github.com/raspberrypi/pico-sdk/issues/573)
target_link_options(${PWM_CONTROLLER} PRIVATE -Wl,-z,max-page-size=4096)
pico_set_linker_script(${PWM_CONTROLLER} ${CMAKE_CURRENT_SOURCE_DIR}/memmap_default.ld)


