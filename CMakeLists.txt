cmake_minimum_required(VERSION 3.20)
project(WxImageKernel)

set(CMAKE_CXX_STANDARD 14)

find_package(wxWidgets REQUIRED net gl core base)
include(${wxWidgets_USE_FILE})
include_directories(Image)
add_executable(WxImageKernel main.cpp wxImagePanel.cpp wxImagePanel.h)
target_link_libraries(WxImageKernel ${wxWidgets_LIBRARIES})