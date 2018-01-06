#
#
#
cmake_minimum_required(VERSION 3.2)
project (olqt)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

add_subdirectory(src/ol)
add_subdirectory(examples)

add_subdirectory(3rdparty)
add_subdirectory(test)
