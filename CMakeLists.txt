cmake_minimum_required(VERSION 3.10)
project(HttpServer)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(server
    src/main.cpp
    src/server.cpp
    src/request.cpp
    src/response.cpp
    src/serveFile.cpp
)