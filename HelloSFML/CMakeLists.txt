cmake_minimum_required(VERSION 3.23)
project(HelloSFML)

set(CMAKE_CXX_STANDARD 17)

add_executable(HelloSFML main.cpp Polygon.cpp Line.cpp Intersects.cpp VectorMath.cpp)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR D:/Tetris/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(D:/Tetris/SFML/include)
target_link_libraries(HelloSFML sfml-system sfml-window sfml-graphics sfml-audio sfml-network)