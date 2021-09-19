#cmake_minimum_required(VERSION 3.20)  //ho messo la 3.17 perchè mi dava problemi
cmake_minimum_required(VERSION 3.17)
project(WxImageKernel)

set(CMAKE_CXX_STANDARD 14)

find_package(wxWidgets REQUIRED net gl core base)
include(${wxWidgets_USE_FILE})
include_directories(Image)
add_executable(WxImageKernel main.cpp wxImagePanel.cpp wxImagePanel.h MainFrame.cpp MainFrame.h)
target_link_libraries(WxImageKernel ${wxWidgets_LIBRARIES})