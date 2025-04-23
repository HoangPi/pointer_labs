cmake_minimum_required(VERSION 3.28)
project("Pointer_labs")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

# Set default source file if not specified
if(NOT DEFINED SOURCE_FILE OR SOURCE_FILE STREQUAL "")
    set(SOURCE_FILE "./lab1_core_concepts/simple_declaration.cpp")
endif()

# Set up binary file for debug if required
if(NOT DEFINED DEBUG OR DEBUG STREQUAL "1")
    # check which compiler to set correct flags
    if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
        set(OP_FLAG "/O0 /Zi")
    elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
        set(OP_FLAG "-O0 -g")
    endif()
else()
    # check which compiler to set correct flags
    if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
        set(OP_FLAG "/O2")
    elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
        set(OP_FLAG "-O3")
    endif()
endif()

# Add source file
add_executable(program.exe ${SOURCE_FILE})

add_compile_options(program.exe ${OP_FLAG})
