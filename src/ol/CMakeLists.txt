#
#
#

add_definitions (-Dolqt_EXPORTS)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/..)

add_subdirectory(layer)
add_subdirectory(source)
add_subdirectory(tilegrid)

set (STRUCTS_SRC
	structs/PriorityQueue.cpp
	structs/PriorityQueue.h
)

set (EVENTS_SRC
	events/EventTarget.cpp
	events/EventTarget.h
)

add_library(olqt SHARED
    exports.h
	Disposable.cpp
	Disposable.h
    Object.cpp
    Object.h
	TileQueue.cpp
	TileQueue.h
    Map.cpp
    Map.h
    PluggableMap.cpp
    PluggableMap.h
    View.cpp
    View.h
	Tile.cpp
	Tile.h

	${STRUCTS_SRC}
	${EVENTS_SRC}

    $<TARGET_OBJECTS:layer_obj>
    $<TARGET_OBJECTS:source_obj>
    $<TARGET_OBJECTS:tilegrid_obj>
)

source_group("Source Files\\structs" FILES ${STRUCTS_SRC})
source_group("Source Files\\events" FILES ${EVENTS_SRC})

target_include_directories(olqt SYSTEM INTERFACE "${olqt_SOURCE_DIR}/src")

set_target_properties(olqt PROPERTIES FOLDER "ol")

# end of file
