cmake_minimum_required(VERSION 3.10)
project(ED1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SOURCES CONFIGURE_DEPENDS
    "src/*.cpp"
)

add_executable(ED1 ${SOURCES})

target_include_directories(ED1 PRIVATE include)