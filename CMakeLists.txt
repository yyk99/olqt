#
#
#
cmake_minimum_required(VERSION 3.2)
project (olqt)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(src/ol)
add_subdirectory(examples)