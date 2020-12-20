# cmake_minimum_required(VERSION 3.19)
#project(server)
# set(CMAKE_CXX_STANDARD 14)
#set(CMAKE_CXX_FLAGS "-pthread")
#add_executable(server server.cpp)

cmake_minimum_required(VERSION 3.5)

project(qt LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

add_executable(qt
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        mainwindow.cpp)

target_link_libraries(qt PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
