set(MAIN_SOURCES
    vector_table.c
    systick.c
    main.c
    thread.c
)

add_subdirectory(gpio)

add_executable(final.elf ${MAIN_SOURCES})
target_link_libraries(final.elf PRIVATE Gpio)
target_link_options(final.elf PRIVATE LINKER:-Map=final.map)