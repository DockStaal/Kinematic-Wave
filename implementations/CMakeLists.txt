add_executable(1d 1d.cpp)
add_executable(2d 2d.cpp)

target_include_directories(1d PUBLIC ../include)
target_link_libraries(1d PUBLIC SKW)

target_include_directories(2d PUBLIC ../include)
target_link_libraries(2d PUBLIC SKW)
