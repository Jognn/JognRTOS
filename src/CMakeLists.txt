set(MAIN_SOURCES
    vector_table.c
    init.c
    systick.c
    main.c
    thread.c
)

add_subdirectory(gpio)

add_executable(final.elf ${MAIN_SOURCES})
target_link_libraries(final.elf PRIVATE Gpio)
target_link_options(final.elf PRIVATE LINKER:-Map=final.map)

add_custom_command(
    TARGET final.elf
    POST_BUILD
    COMMAND ${OBJDUMP} -S -t final.elf > final.S
    COMMENT "Disassembling final.elf..."
)

add_custom_target(disassemble_final_elf
    DEPENDS final.elf
)