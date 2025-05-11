# 获取指定目录下的所有源文件
aux_source_directory(. SRC_LIST)
# 找到 Boost 库
find_package(Boost REQUIRED COMPONENTS system filesystem)
# 指定生成可执行文件
add_executable(ChatServer ${SRC_LIST})
# 指定编译时需要依赖的头文件
target_include_directories(ChatServer PRIVATE
    /usr/local/include
    ${Boost_INCLUDE_DIRS}
)
# 指定可执行文件链接时需要依赖的库文件
target_link_libraries(ChatServer PRIVATE muduo_net muduo_base pthread)