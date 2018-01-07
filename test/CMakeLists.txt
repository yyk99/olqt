#
#
#

macro (olqt_simple_test test_name)
	add_executable(${test_name} ${test_name}.cpp)
	target_link_libraries(${test_name} olqt gtest_main)
	add_test(NAME ${test_name} COMMAND ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${test_name})
	set_target_properties(${test_name} PROPERTIES FOLDER "test")
endmacro(olqt_simple_test)

olqt_simple_test(t1)
olqt_simple_test(ol.object.test)
olqt_simple_test(ol.structs.PriorityQueue.test)

