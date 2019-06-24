# CMakeList.txt: OpenCVTest 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)
#指定要引用的dll的头文件所在路径
include_directories("D:/DevelopEnv/opencv/build/include")
#指定该dll的lib所在路径
link_directories("D:/DevelopEnv/opencv/build/x64/vc15/lib")

# 将源代码添加到此项目的可执行文件。
add_executable (OpenCVTest "OpenCVTest.cpp" "OpenCVTest.h")

#指定链接库的名字，即该dll
# opencv_world410d.lib在D:\DevelopEnv\opencv\build\x64\vc15\lib目录下
target_link_libraries(OpenCVTest opencv_world410d)