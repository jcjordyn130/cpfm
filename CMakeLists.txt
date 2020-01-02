cmake_minimum_required(VERSION 3.5)

project(qtfm LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_executable(qtfm
  main.cpp
  mainwindow.cpp
  mainwindow.h
  mainwindow.ui
  fileviewwidget.h
  fileviewwidget.cpp
  sidebar/widgets/mimetype.h
  sidebar/widgets/mimetype.cpp
)

target_link_libraries(qtfm PRIVATE Qt5::Widgets)
