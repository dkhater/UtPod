cmake_minimum_required(VERSION 3.12)
project(HW5_UTPod)

set(CMAKE_CXX_STANDARD 11)

add_executable(HW5_UTPod utPod_driver.cpp Song.h Song.cpp UtPod.cpp UtPod.h)