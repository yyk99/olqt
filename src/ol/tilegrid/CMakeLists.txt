#
# olqt/src/ol/tilegrid/CMakeLists.txt
#

set (TARGET tilegrid_obj)

set (SRC_FILES
	TileGrid.cpp
	TileGrid.h
)

add_library (${TARGET} OBJECT ${SRC_FILES})

set_target_properties(${TARGET} PROPERTIES FOLDER "ol")

# end of file
