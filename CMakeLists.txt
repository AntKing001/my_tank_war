cmake_minimum_required(VERSION 3.27)
project(my_tank_war)

set(CMAKE_CXX_STANDARD 17)

include_directories("/opt/homebrew/Cellar/mysql/8.2.0_1/include")
include_directories("/opt/homebrew/Cellar/mysql/8.2.0_1/lib")

add_executable(my_tank_war mysql_data.h
        mysql_data.cpp)

target_link_libraries(my_tank_war /opt/homebrew/Cellar/mysql/8.2.0_1/lib/libmysqlclient.dylib)
