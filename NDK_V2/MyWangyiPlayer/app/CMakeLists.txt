#CMakeLists.txt 放在app目录下

cmake_minimum_required(VERSION 3.4.1)
file(GLOB SOURCE ${CMAKE_SOURCE_DIR}/src/main/cpp/*.cpp) #/src/main/cpp目录下所有的CPP文件

add_library(
        native-lib
        SHARED
        ${SOURCE}
        #[[native-lib.cpp]])

find_library(
        log-lib
        log)

#添加头文件目录
include_directories(${CMAKE_SOURCE_DIR}/src/main/cpp/include)
set(my_lib_path  ${CMAKE_SOURCE_DIR}/libs/${ANDROID_ABI})
#添加预编译库
#CMAKE_CXX_FLAGS 是C++，CMAKE_C_FLAGS 是C
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -L${my_lib_path}")

target_link_libraries(
        native-lib
        avfilter avformat avcodec avutil swresample swscale
        ${log-lib}
        z
        OpenSLES
        android
        )