#
# olqt/src/ol/layer/CMakeLists.txt
#

set (TARGET source_obj)

set (SRC_FILES
    OSM.cpp
    OSM.h
    Source.cpp
    Source.h
    Tile.cpp
    Tile.h
    TileImage.cpp
    TileImage.h
    UrlTile.cpp
    UrlTile.h
    XYZ.cpp
    XYZ.h
)

add_library (${TARGET} OBJECT ${SRC_FILES})

set_target_properties(${TARGET} PROPERTIES FOLDER "ol")

# end of file
