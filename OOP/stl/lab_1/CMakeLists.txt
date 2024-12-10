cmake_minimum_required(VERSION 3.24)
project(OOP)

set(CMAKE_CXX_STANDARD 17)

#.CPP файлы в корневом каталоге проекта
file (GLOB files *.cpp)
foreach (file ${files})
    string(REGEX REPLACE ".+/(.+)\\..*" "\\1" exe ${file})
    add_executable (${exe} ${file} cmake-build-debug/task1.cpp)
    message (\ \ \ \ --\ src/${exe}.cpp\ will\ be\ compiled\ to\ bin/${exe})
endforeach ()
