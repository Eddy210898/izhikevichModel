# Minimum version of CMake required to build this project
cmake_minimum_required(VERSION 3.0)

# Name of the project
project(izhikevichModel)

# Add a library to this build. The name of the library is MyLibrary and it
# consists of only the MyLibrary.cpp file
add_library(izhikevichModel src/izhikevichParams.cpp src/izhikevichStep.cpp src/izhikevichModel.cpp)

link_directories(getNextRungeKuta)

add_subdirectory(getNextRungeKuta)

# Link the executable and the library together
target_link_libraries(izhikevichModel getNextRungeKuta)