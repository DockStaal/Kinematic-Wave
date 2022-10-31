cmake_minimum_required(VERSION 3.23)

find_program(clang++ NAMES clang++)
if (NOT CMAKE_CXX_COMPILER AND clang++)
    set(CMAKE_CXX_COMPILER ${clang++})
endif()

project(Serial_Kinematic_Wave_Equation_Solvers 
        VERSION 1.0
        LANGUAGES CXX)
find_package(PythonLibs REQUIRED)
#find_program(clang-tidy NAMES clang-tidy REQUIRED)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/lib")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# set(CMAKE_CXX_CLANG_TIDY 
#     ${clang-tidy}
#     -checks=-*,cppcoreguidelines-*,readability-*,modernize-*,performance-*,bugprone-*,portability-*,clang-analyzer-*
#     )

add_subdirectory(source)
add_subdirectory(tests)
add_subdirectory(implementations)
