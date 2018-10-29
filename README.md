# ocv_sketch

##Summary

This project aim to get working with OpenCV more convenient and simple. It includes as simplified functions to interact with OpenCV and also a working build with instructuion, how-to create the same one. 

## Build OpenCV from sources for MinGW and CMake

Link to the last my build archive (3.4.0): https://1drv.ms/u/s!AjuYISBbgHIFncJ7zEFazhkLFZTlrw

* Download the OpenCV source files. Link
* Unpack to C:\opencv (or a folder of your choice)
* Open CMake and select source (directory of 2.) and build for example C:\opencv\mingw-build
* Click Configure and select MinGW Makefiles. (If you experience problems, ensure that the minGW/bin directory is added to the evironment path labelled, 'PATH')
* Wait for the configuration to be done, edit your properties of your needs (in my case I don't need tests, docs and python).
Click Configure again. When everything is white click Generate else edit the red fields.
* open cmd and dir to build directory of 3.
* Run mingw32-make (or mingw64-make). This takes a while. 
* Once it is done, run mingw32-make install (or mingw64-make install).
This creates an install folder, where everything you need for building your own OpenCV apps is included.
* To system PATH add C:\opencv\mingw-build\install\x86\mingw\bin
* Restart your PC.

## Minimal CMakeLists.txt

    set(CMAKE_CXX_STANDARD 14)
    set(PROJECT_NAME write_name_here)
    add_executable(${PROJECT_NAME} main.cpp)
    
    #libraries
    set(OpenCV_DIR C:/opencv/install)
    
    cmake_minimum_required(VERSION 3.12)
    project(${PROJECT_NAME})
    
    #OpenCV
    find_package( OpenCV REQUIRED )
    set(OpenCV_LIBS opencv_core opencv_imgproc opencv_highgui opencv_imgcodecs)
    target_link_libraries( ${PROJECT_NAME} ${OpenCV_LIBS} )

## ocv_sketch classes

* OcvCamera


## References

https://stackoverflow.com/questions/35984678/use-opencv-with-clion-ide-on-windows