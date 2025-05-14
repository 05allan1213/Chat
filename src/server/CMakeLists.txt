# 获取指定目录下的所有源文件
aux_source_directory(. SRC_LIST)
aux_source_directory(./db DB_SRC_LIST)
aux_source_directory(./model MODEL_SRC_LIST)
# 指定生成可执行文件
add_executable(ChatServer ${SRC_LIST} ${DB_SRC_LIST} ${MODEL_SRC_LIST})
# 指定可执行文件链接时需要依赖的库文件
target_link_libraries(ChatServer PRIVATE muduo_net muduo_base mysqlclient pthread)