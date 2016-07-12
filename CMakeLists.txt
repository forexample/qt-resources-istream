cmake_minimum_required(VERSION 3.0)

include("cmake/HunterGate.cmake")
HunterGate(
    URL "https://github.com/ruslo/hunter/archive/v0.14.29.tar.gz"
    SHA1 "9c29c30fff99b7c1479b2e9d4926dcc3f8d364e0"
)

project(QtResourcesToIstream)

hunter_add_package(Qt)
find_package(Qt5Widgets REQUIRED)

set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_executable(qtapp main.cpp qtapp.qrc config.ini)

add_library(foo foo.cpp foo.hpp)

target_link_libraries(qtapp PUBLIC Qt5::Widgets foo)
