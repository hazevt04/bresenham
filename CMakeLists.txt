cmake_minimum_required( VERSION 2.8.9 )

project( bresenham )

include_directories( $CMAKE_SOURCE_DIR )

add_definitions(-std=c++11 )

set(SRCS
   "BresenhamLineDrawer.cpp"
   "ImageData.cpp"
   "PNGRenderer.cpp"
   "main.cpp"
)


add_executable( bresenham "${SRCS}" )

target_link_libraries( bresenham png z )

