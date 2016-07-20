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

set(qtapp_sources main.cpp qtapp.qrc gemma.png)

if(ANDROID)
  add_library(qtapp SHARED ${qtapp_sources})
  set_target_properties(qtapp PROPERTIES VERSION 1.0)

  hunter_add_package(QtAndroidCMake)
  list(APPEND CMAKE_MODULE_PATH "${QTANDROIDCMAKE_ROOT}")
  include(AddQtAndroidApk) # add_qt_android_apk

  add_qt_android_apk(
      TARGET qtapp-apk
      BASE_TARGET qtapp
      PACKAGE_NAME com.github.forexample.qtresourcesistream
      INSTALL
  )
else()
  add_executable(qtapp ${qtapp_sources})
endif()

add_library(foo foo.cpp foo.hpp)

target_link_libraries(qtapp PUBLIC Qt5::Widgets foo)

if(ANDROID OR IOS)
  # Test manually
else()
  enable_testing()
  add_test(NAME QtRun COMMAND qtapp)
endif()
