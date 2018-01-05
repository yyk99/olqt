#
#
#

set(TARGET simple_map)

find_package(Qt5Widgets)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

#qt5_wrap_ui(UI_HEADERS mainwindow.ui) 

set (SRC_FILES simple_map.cpp simple_map.h MainWindow.h MainWindow.cpp)

include_directories(${CMAKE_SOURCE_DIR}/src) # inlude <ol/....>

add_executable(${TARGET} ${SRC_FILES} ${UI_HEADERS})

target_link_libraries(${TARGET} olqt)

qt5_use_modules(${TARGET} Widgets)

set_property(SOURCE "${UI_HEADERS}" PROPERTY SKIP_AUTOMOC ON)

set_target_properties(${TARGET} PROPERTIES FOLDER "examples")

# end of file
