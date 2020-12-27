cmake_minimum_required(VERSION 3.5)

project(qt LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(SRC_LIST_FRONTEND
        "frontend/input_field.h"
        "frontend/input_field.cpp"
        "frontend/send_messages.h"
        "frontend/send_messages.cpp")
set(SRC_LIST_SERVER
        "server/main.cpp"
        "server/main_window.h"
        "server/main_window.cpp"
        "server/server.h"
        "server/server.cpp")
set(SRC_LIST_CLIENT
        "client/main.cpp"
        "client/main_window.h"
        "client/main_window.cpp"
        "client/client.h"
        "client/client.cpp")

find_package(Qt5 COMPONENTS Widgets Network REQUIRED)
set(QT5_PREFERENCES Qt5::Widgets Qt5::Network)

add_executable(server ${SRC_LIST_FRONTEND} ${SRC_LIST_SERVER})
add_executable(client ${SRC_LIST_FRONTEND} ${SRC_LIST_CLIENT})

target_link_libraries(server PRIVATE ${QT5_PREFERENCES})
target_link_libraries(client PRIVATE ${QT5_PREFERENCES})