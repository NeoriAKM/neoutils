cmake_minimum_required(VERSION 3.16)
project(nu C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_library(pub STATIC lib/pub.c)
target_include_directories(pub PUBLIC lib)

set(COMMON_FLAGS
    -Wall -Wextra -Wpedantic -Werror
    -Wshadow -Wunused-variable -Wsign-conversion
)

file(GLOB UTIL_SOURCES "src/*.c")

foreach(SOURCE_FILE ${UTIL_SOURCES})
    get_filename_component(UTIL_NAME ${SOURCE_FILE} NAME_WE)

    add_executable(${UTIL_NAME} ${SOURCE_FILE})
    target_compile_options(${UTIL_NAME} PRIVATE ${COMMON_FLAGS})

    target_link_libraries(${UTIL_NAME} PRIVATE pub)

    install(TARGETS ${UTIL_NAME} DESTINATION bin)
endforeach()

# target_compile_options(nu PRIVATE -fsanitize=address -fno-omit-frame-pointer -g)
# target_link_options(nu PRIVATE -fsanitize=address)