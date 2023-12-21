# 设置要求的最低CMake版本
cmake_minimum_required(VERSION 3.20)

# 设置项目名称、版本所用语言
project(string VERSION 1.0.0 LANGUAGES C)

# 设置C语言标准
set(CMAKE_C_STANDARD 11)

set(project_name string)

# 启用GCC所有警告，视警告为错误
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror")

# 设置可执行文件的生成
add_executable(${project_name}
               main.c
               apple_string.c)

target_link_libraries(${project_name}
                      cmocka)
