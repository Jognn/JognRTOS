set(MAIN_SOURCES
    init.c
    main.c
    sleep.c
)

set(GPIO_SOURCES
    gpio.c
)

add_executable(final.elf ${MAIN_SOURCES} ${GPIO_SOURCES})
target_link_options(final.elf PRIVATE LINKER:-Map=final.map)