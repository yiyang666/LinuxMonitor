#!/usr/bin/env bash

set -e # 遇到错误返回值不为0，直接报错

cd "$(dirname "${BASH_SOURCE[0]}")" # 进入到相应的目录下
# temp/install/abseil

# https://github.com/abseil/abseil-cpp/archive/refs/tags/20200225.2.tar.gz
# Install abseil.
THREAD_NUM=$(nproc)
VERSION="20200225.2"
PKG_NAME="abseil-cpp-${VERSION}.tar.gz"

tar xzf "${PKG_NAME}"
pushd "abseil-cpp-${VERSION}"
    mkdir build && cd build
    # 用cmake生产MakeFile文件
    # 动态库# C++14 # 安装目录，第三软件目录
    cmake .. \
        -DBUILD_SHARED_LIBS=ON \
        -DCMAKE_CXX_STANDARD=14 \
        -DCMAKE_INSTALL_PREFIX=/usr/local

    # 编译 -j 指定核心数
    make -j${THREAD_NUM}
    make install
popd

ldconfig

# Clean up，装好后把整个文件删除，避免囤积，包括安装包
# 通过清除中间产物，可以减小构建镜像的大小
rm -rf "abseil-cpp-${VERSION}" "${PKG_NAME}"