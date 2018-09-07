cmake_minimum_required(VERSION 3.4.1)

find_library(log-lib
             log )

#set(distribution_DIR ${CMAKE_SOURCE_DIR}/libs)            # 文件夹为libs的情况下
set(distribution_DIR ${CMAKE_SOURCE_DIR}/src/main/jniLibs) # 文件夹为jniLibs的情况下

add_library( fmod
             SHARED
             IMPORTED )

set_target_properties( fmod
                       PROPERTIES IMPORTED_LOCATION
                       ${distribution_DIR}/${ANDROID_ABI}/libfmod.so )

add_library( fmodL
             SHARED
             IMPORTED )

set_target_properties( fmodL
                      PROPERTIES IMPORTED_LOCATION
                      ${distribution_DIR}/${ANDROID_ABI}/libfmodL.so )

add_library(native-lib
            SHARED
            src/main/cpp/native-lib.cpp )

include_directories(src/main/cpp/inc)

target_link_libraries( native-lib fmod fmodL
                       ${log-lib} )


