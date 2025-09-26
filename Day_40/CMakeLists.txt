cmake_minimum_required(VERSION 3.1)
project(myReadFile)
set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -lpthread -std=c++11")
enable_testing()
add_executable(myReadFile myReadFile.cpp)
add_executable(myThreadReadFile myThreadReadFile.cpp)
add_test(myTest1 myThreadReadFile example.txt) 
add_test(myTest2 myReadFile example.txt)

# cmake -DCMAKE_BUILD_TYPE=Release .
# cmake --build .
# ctest
# cd Testing 
# cd Temporary
