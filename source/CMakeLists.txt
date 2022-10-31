 add_library(SKW STATIC ../include/stepper_type.hpp
                       controller.cpp 
                       drain_direction_map.cpp 
                       node.cpp
                       stepper.cpp 
                       upwind.cpp
                       view.cpp) 
target_include_directories(SKW PUBLIC ../include ../external ${PYTHON_INCLUDE_DIRS})
target_link_libraries(SKW PUBLIC m ${PYTHON_LIBRARIES})
