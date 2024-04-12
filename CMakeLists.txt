cmake_minimum_required(VERSION 3.13)

set(CMAKE_BUILD_TYPE "Release")
add_compile_options(-Ofast -mthumb)

include(pico_sdk_import.cmake)

project(msxpico-project)

pico_sdk_init()

################################################################################
# Helper function
function(set_linker_script TARGET script)
    target_link_directories(${TARGET} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
    pico_set_linker_script(${TARGET} ${CMAKE_CURRENT_SOURCE_DIR}/${script})

    # Add dependencies on the 'included' linker scripts so that the target gets
    # rebuilt if they are changed
    pico_add_link_depend(${TARGET} ${CMAKE_CURRENT_SOURCE_DIR}/${script})
endfunction()

add_executable(bootloader)
target_sources(bootloader PRIVATE bootloader.c)
target_link_libraries(bootloader PRIVATE pico_stdlib)
pico_add_extra_outputs(bootloader)
set_linker_script(bootloader bootloader.ld)

add_executable(firmware0)
target_sources(firmware0 PRIVATE firmware0.c)
target_link_libraries(firmware0 PRIVATE pico_stdlib)
pico_add_extra_outputs(firmware0)
set_linker_script(firmware0 firmware0.ld)

add_executable(firmware1)
target_sources(firmware1 PRIVATE firmware1.c)
target_link_libraries(firmware1 PRIVATE pico_stdlib)
pico_add_extra_outputs(firmware1)
set_linker_script(firmware1 firmware1.ld)

add_executable(firmware2)
target_sources(firmware2 PRIVATE firmware2.c)
target_link_libraries(firmware2 PRIVATE pico_stdlib)
pico_add_extra_outputs(firmware2)
set_linker_script(firmware2 firmware2.ld)

add_executable(firmware3)
target_sources(firmware3 PRIVATE firmware3.c)
target_link_libraries(firmware3 PRIVATE pico_stdlib)
pico_add_extra_outputs(firmware3)
set_linker_script(firmware3 firmware3.ld)

add_executable(firmware4)
target_sources(firmware4 PRIVATE firmware4.c)
target_link_libraries(firmware4 PRIVATE pico_stdlib)
pico_add_extra_outputs(firmware4)
set_linker_script(firmware4 firmware4.ld)

add_executable(firmware5)
target_sources(firmware5 PRIVATE firmware5.c)
target_link_libraries(firmware5 PRIVATE pico_stdlib)
pico_add_extra_outputs(firmware5)
set_linker_script(firmware5 firmware5.ld)
