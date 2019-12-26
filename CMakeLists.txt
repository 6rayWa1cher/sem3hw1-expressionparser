cmake_minimum_required(VERSION 3.9.2)
project(hw1sem3)
set(CMAKE_CXX_STANDARD 14)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)


configure_file(CMakeLists.txt.in pmicric-download/CMakeLists.txt)

execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/pmicric-download)
if (result)
    message(FATAL_ERROR "CMake step for pmicric failed: ${result}")
endif ()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/pmicric-download)
if (result)
    message(FATAL_ERROR "Build step for pmicric failed: ${result}")
endif ()

add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/pmicric-src
        ${CMAKE_CURRENT_BINARY_DIR}/pmicric-build
        EXCLUDE_FROM_ALL)
add_executable(app src/main.cpp src/ExpressionParser.cpp include/ExpressionParser.h)

target_link_libraries(app PRIVATE micric-lib)