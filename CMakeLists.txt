cmake_minimum_required(VERSION 3.22)
project(JognRTOS)

include(toolchain.cmake)

set(LINKER_SCRIPT_PATH ${CMAKE_SOURCE_DIR}/linker_scripts/stm32l476_linker_script.ld)
add_link_options(-T${LINKER_SCRIPT_PATH} -nostdlib)

add_subdirectory(src)
