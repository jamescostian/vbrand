cmake_minimum_required(VERSION 3.9)
project(vbrand)

set(CMAKE_CXX_STANDARD 11)

SET(brand "I am lazy and did not see how to change the brand in the README, so I will use the default one" CACHE STRING "The brand that will be appended to your files")
ADD_DEFINITIONS(-DTHE_BRAND=\"${brand}\")

add_executable(vbrand main.cc eof_tools.cc)
