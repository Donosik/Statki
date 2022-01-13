cmake_minimum_required(VERSION 3.21)
project(Statki)

set(CMAKE_CXX_STANDARD 23)

add_executable(Statki main.cpp App.cpp App.h Board.cpp Board.h)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(c:/SFML/include)
target_link_libraries(Statki sfml-system sfml-window sfml-graphics sfml-audio sfml-network)
