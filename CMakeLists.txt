cmake_minimum_required(VERSION 3.28)
project(illSurf)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(illSurf main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui)
target_link_libraries(illSurf
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

