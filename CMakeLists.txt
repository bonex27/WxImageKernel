#cmake_minimum_required(VERSION 3.20)  //ho messo la 3.17 perchè mi dava problemi
cmake_minimum_required(VERSION 3.17)
project(WxImageKernel)

set(CMAKE_CXX_STANDARD 14)


file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/Image/Ferrari-sf21.jpeg DESTINATION DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/Image/)

find_package(wxWidgets REQUIRED net gl core base)
include(${wxWidgets_USE_FILE})
add_executable(WxImageKernel main.cpp wxImagePanel.cpp wxImagePanel.h MainFrame.cpp MainFrame.h)
target_link_libraries(WxImageKernel ${wxWidgets_LIBRARIES})