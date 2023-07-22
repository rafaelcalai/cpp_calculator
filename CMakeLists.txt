cmake_minimum_required(VERSION 3.25)
project(cpp_calculator)

find_package(PkgConfig)
pkg_check_modules(GTKMM gtkmm-3.0)

set(CMAKE_CXX_STANDARD_LIBRARIES)
set(CMAKE_CXX_STANDARD 17)
link_directories(${GTKMM_LIBRARY_DIRS}  )
include_directories(${GTKMM_INCLUDE_DIRS})

add_executable(cpp_calculator main.cpp SourceFiles/MainWindow.cpp Include/MainWindow.h)

target_link_libraries(cpp_calculator ${GTKMM_LIBRARIES})