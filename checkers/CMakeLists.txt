cmake_minimum_required(VERSION 3.15)

project(checkers)

set(CMAKE_CXX_STANDARD 14)

set(SOURCES main.cpp)


add_executable(checkers ${SOURCES})

add_subdirectory(strategies)
add_subdirectory(game)

target_link_libraries(checkers strategies game)
