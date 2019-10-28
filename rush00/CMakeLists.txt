cmake_minimum_required(VERSION 3.14)
project(rush00)

set(CMAKE_CXX_STANDARD 98)

link_libraries(curses)

add_executable(rush00 main.cpp Bullet.cpp Enemy.cpp List.cpp Point.cpp Ship.cpp Player.cpp Object.cpp)