#
#
#

enable_testing()

add_executable(t1 t1.cpp)
target_link_libraries(t1 olqt gtest_main)
add_test(t1 t1)

set_target_properties(t1 PROPERTIES FOLDER "test")
