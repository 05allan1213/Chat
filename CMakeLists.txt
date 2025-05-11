# 设置 CMake 最低版本要求
cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

# 定义项目名称和语言
project(chat LANGUAGES CXX)

# --- 编译器设置 ---
# 设置 C++ 标准为 C++11
set(CMAKE_CXX_STANDARD 11)
# 强制要求支持 C++11 标准
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# 关闭编译器特定的扩展，以提高可移植性
set(CMAKE_CXX_EXTENSIONS OFF)

# --- 构建类型处理 ---
if(NOT CMAKE_BUILD_TYPE)
    # 如果用户未指定构建类型，则默认为 Debug
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "构建类型 (Debug, Release, RelWithDebInfo, MinSizeRel)" FORCE)
    message(STATUS "未指定构建类型，默认为: ${CMAKE_BUILD_TYPE}")
else()
    message(STATUS "当前使用的构建类型: ${CMAKE_BUILD_TYPE}")
endif()

# --- 输出目录设置 ---
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin) # 设置可执行文件输出目录

# --- 设置头文件搜索路径 ---
include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/include/server)
include_directories(${PROJECT_SOURCE_DIR}/include/server/db)

# 加载子目录
add_subdirectory(src)