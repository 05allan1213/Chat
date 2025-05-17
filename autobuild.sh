#########################################################################
# File Name: autobuild.sh
# Author: shi lei
# mail: shitou3000@qq.com
# Created Time: 2020年05月17日 星期六 14时40分28秒
#########################################################################
#!/bin/bash

# 启用调试模式：显示执行的每条命令
set -x

# 项目根目录
PROJECT_DIR=$(pwd)

# 构建目录和可执行文件输出目录
BUILD_DIR="$PROJECT_DIR/build"
BIN_DIR="$PROJECT_DIR/bin"

# 如果 build 目录不存在，则创建
if [ ! -d "$BUILD_DIR" ]; then
    mkdir "$BUILD_DIR"
fi

# 如果 bin 目录不存在，则创建
if [ ! -d "$BIN_DIR" ]; then
    mkdir "$BIN_DIR"
fi

# 清空 build 和 bin 目录中的内容
rm -rf "$BUILD_DIR"/*
rm -rf "$BIN_DIR"/*

# 进入 build 目录，执行 cmake 和 make
cd "$BUILD_DIR" &&
    cmake .. &&
    make

# 将生成的可执行文件移动到 bin 目录

if [ -f "$BUILD_DIR/chatserver" ]; then
    mv "$BUILD_DIR/chatserver" "$BIN_DIR/"
fi

if [ -f "$BUILD_DIR/chatclient" ]; then
    mv "$BUILD_DIR/chatclient" "$BIN_DIR/"
fi
