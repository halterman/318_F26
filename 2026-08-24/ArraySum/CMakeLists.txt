cmake_minimum_required(VERSION 3.25.0)

#-----------------------------------------------------
# Edit project-specific information
#-----------------------------------------------------

set(EXECUTABLE prog)

#-----------------------------------------------------
# Usually leave the rest untouched
#-----------------------------------------------------

project(${EXECUTABLE} VERSION 0.1.0 LANGUAGES C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED YES)

# Use stricter compiler warnings
if (MSVC)
    # Microsoft Visual C++
    add_compile_options(/W4) 
    add_compile_definitions(_CRT_SECURE_NO_WARNINGS)
else()
    # GCC and Clang
    add_compile_options(-Wall -Wextra -pedantic -Wno-char-subscripts)
endif()

file(GLOB SRCS_LIST "*.c" "*.h")

add_executable(${EXECUTABLE} ${SRCS_LIST})

