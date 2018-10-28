set(PROJECT_NAME ocv_sketch)
add_executable(${PROJECT_NAME} main_dev1.cpp)

#libraries
set(OpenCV_DIR C:/opencv/install)
# ocv sketch
include_directories(inc)
file(GLOB OCVSKETCH_SRC src/*.cpp)

set(CMAKE_CXX_STANDARD 14)
cmake_minimum_required(VERSION 3.12)
project(${PROJECT_NAME})

#OpenCV
find_package( OpenCV REQUIRED )
set(OpenCV_LIBS opencv_core opencv_imgproc opencv_highgui opencv_imgcodecs)
target_link_libraries( ${PROJECT_NAME} ${OpenCV_LIBS} )

target_sources( ${PROJECT_NAME} PRIVATE ${OCVSKETCH_SRC})

