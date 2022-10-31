find_package(Catch2 REQUIRED)

add_executable(test 
               test_main.cpp 
               test_drain_direction_map.cpp 
               test_node.cpp 
               test_controller.cpp 
               test_stepper.cpp 
               test_utils.cpp
               test_view.cpp)

target_link_libraries(test PRIVATE Catch2::Catch2 SKW)
target_include_directories(test PUBLIC ../include)
set_target_properties(test PROPERTIES CXX_CLANG_TIDY "")
