#
#
#

include_directories(${CMAKE_SOURCE_DIR}/src)

set (STRUCTS_SRC
	structs/PriorityQueue.cpp
	structs/PriorityQueue.h
)

set (EVENTS_SRC
	events/EventTarget.cpp
	events/EventTarget.h
)

set (LAYER_SRC
    layer/Base.cpp 
    layer/Base.h
    layer/Layer.cpp
    layer/Layer.h
    layer/Tile.cpp
    layer/Tile.h
)

set (SOURCE_SRC
    source/OSM.cpp
    source/OSM.h
    source/Source.cpp
    source/Source.h
    source/Tile.cpp
    source/Tile.h
    source/TileImage.cpp
    source/TileImage.h
    source/UrlTile.cpp
    source/UrlTile.h
    source/XYZ.cpp
    source/XYZ.h
)

set (TILEGRID_SRC
	tilegrid/TileGrid.cpp
	tilegrid/TileGrid.h
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

	${EVENTS_SRC}
    ${LAYER_SRC}
    ${SOURCE_SRC}
	${STRUCTS_SRC}
    ${TILEGRID_SRC}
)

source_group("Source Files\\structs" FILES ${STRUCTS_SRC})
source_group("Source Files\\events" FILES ${EVENTS_SRC})
source_group("Source Files\\layer" FILES ${LAYER_SRC})
source_group("Source Files\\source" FILES ${SOURCE_SRC})
source_group("Source Files\\tilegrid" FILES ${TILEGRID_SRC})

target_include_directories(olqt SYSTEM INTERFACE "${olqt_SOURCE_DIR}/src")

set_target_properties(olqt PROPERTIES FOLDER "ol")

# end of file
