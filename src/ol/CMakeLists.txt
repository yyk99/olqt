#
#
#

add_definitions (-Dolqt_EXPORTS)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/..)

add_subdirectory(layer)
add_subdirectory(source)
add_subdirectory(tilegrid)

add_library(olqt SHARED
    exports.h
    Object.cpp
    Object.h
    Map.cpp
    Map.h
    PluggableMap.cpp
    PluggableMap.h
    View.cpp
    View.h

    $<TARGET_OBJECTS:layer_obj>
    $<TARGET_OBJECTS:source_obj>
    $<TARGET_OBJECTS:tilegrid_obj>
)

set_target_properties(olqt PROPERTIES FOLDER "ol")

# end of file
