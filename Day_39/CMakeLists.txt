# Cmake for myReadFile
# ...> vi CMakeLists.txt

#cmake_minimum_required(VERSION 3.1)
#project(myReadFile)
#add_executable(myReadFile myReadFile.cpp)

#Follow these commands in linux 

#...> cmake -DCMAKE_BUILD_TYPE=Release . // choose Release or Debug and . for current directory 
#...> cmake --build . 
#...> ls // we get are executable 
#...> rm -rf CMakeFiles cmake_install.cmake Makefile CMakeCache.txt CMakeLists.txt

#...> vi CMakeLists.txt // repeate same steps for myThreadReadFile.cpp

cmake_minimum_required(VERSION 3.1)
project(myThreadReadFile)
set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -lpthread -std=c++11")
add_executable(myThreadReadFile myThreadReadFile.cpp)


# add_library(pthread)
# set(CMAKE_CXX_COMPILER g++)
# set(CMAKE_CXX_STANDARD 11)
# set(CMAKE_CXX_STANDARD_REQUIRED True)
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lpthread -std=c++11")
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -lpthread -std=c++11")
# list(APPEND EXTRA_LIBS MathFunctions)


