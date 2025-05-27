cmake_minimum_required(VERSION 3.28)
project(GTK-Demo)
set(CMAKE_CXX_STANDARD 20)

#set(PKG_CONFIG_EXECUTABLE "C:/msys64/mingw64/bin/pkg-config")
find_package(PkgConfig REQUIRED)

pkg_check_modules(GTK3 REQUIRED gtk+-3.0)
pkg_check_modules(GTKMM REQUIRED gtkmm-3.0)

include_directories(${GTK3_INCLUDE_DIRS})
include_directories(${GTKMM_INCLUDE_DIRS})
link_directories(${GTK3_LIBRARY_DIRS})
link_directories(${GTKMM_LIBRARY_DIRS})

add_definitions(${GTK3_CFLAGS_OTHER})

add_executable(GTK-Demo main.cpp
        MainWindow.cpp
        MainWindow.h)

target_link_libraries(GTK-Demo ${GTK3_LIBRARIES} ${GTKMM_LIBRARIES})
