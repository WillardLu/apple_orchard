# 设置要求的最低CMake版本
cmake_minimum_required(VERSION 3.20)

# 设置项目名称、版本所用语言
project(SubStr VERSION 1.0.0 LANGUAGES C)

# 设置C语言标准
set(CMAKE_C_STANDARD 11)

set(project_name SubStr)

# 设置可执行文件的生成
add_executable(${project_name}
               main.c
               sub_str.c)

target_link_libraries(${project_name}
                      cmocka)
