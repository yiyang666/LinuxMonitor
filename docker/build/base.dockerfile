FROM  ubuntu:18.04

# 非交互方式模式构建（非全局，仅限当前文件中的RUN命令）
ARG DEBIAN_FRONTEND=noninteractive
# 时区  
ENV TZ=Asia/Shanghai

# 使用bash终端 
SHELL ["/bin/bash", "-c"]

# 清理自带的/不必要的软件
RUN apt-get clean && \
    apt-get autoclean

# 镜像源拷贝进去
COPY apt/sources.list /etc/apt/

# 更新apt-get -y表示默认输入yes
# 在容器内安装一些必要的，基础包，能够自己默认装好的库
RUN apt-get update  && apt-get upgrade -y  && \
    apt-get install -y \
    htop \
    apt-utils \
    curl \
    cmake \
    git \
    openssh-server \
    build-essential \
    qtbase5-dev \
    qtchooser \
    qt5-qmake \
    qtbase5-dev-tools \
    libboost-all-dev \
    net-tools \
    vim \
    stress 
# grpc需要的软件包
RUN apt-get install -y libc-ares-dev  libssl-dev gcc g++ make 
# qt需要的软件包，需要能够访问到主机的Xserver来显示图形，如X11服务
RUN apt-get install -y  \
    libx11-xcb1 \
    libfreetype6 \
    libdbus-1-3 \
    libfontconfig1 \
    libxkbcommon0   \
    libxkbcommon-x11-0
# python库，下面QT的安装需要，现在目前看是不需要了
RUN apt-get install -y python-dev \
    python3-dev \
    python-pip \
    python-all-dev 


# 上面装过了
# COPY install/cmake /tmp/install/cmake
# RUN /tmp/install/cmake/install_cmake.sh

# 下面这些库需要自己下载压缩包，编译，安装
# 编写shell脚本来安装
# COPY：当前目录->目的目录，前者的目录是通过数据卷映射过来的
COPY install/protobuf /tmp/install/protobuf
RUN /tmp/install/protobuf/install_protobuf.sh

COPY install/abseil /tmp/install/abseil
RUN /tmp/install/abseil/install_abseil.sh

COPY install/grpc /tmp/install/grpc
RUN /tmp/install/grpc/install_grpc.sh

# 下面这些不需要了

# RUN apt-get install -y python3-pip
# RUN pip3 install cuteci -i https://mirrors.aliyun.com/pypi/simple

# COPY install/qt /tmp/install/qt
# RUN /tmp/install/qt/install_qt.sh






