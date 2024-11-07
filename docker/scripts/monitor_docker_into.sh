#!/usr/bin/env bash

# docker exec 
# 进入一个已经启动的容器,开启一个新终端,至少需要两个参数，这个终端(exit)不会停止容器，可以继续
# docker attach 
# 进入容器正在执行的终端，不会启动新的进程，在这个终端(exit)会停止整个容器，相当于stop
# docker start "容器id" 启动一个已有容器,分配默认终端
# docler stop "容器id"  关闭一个已有容器

# xhost +local:root指定本地root用户才能访问Xserver
# exec会以root的身份在容器内开启一个终端
# 这个终端就有了范围主机Xserver的权限
# 再把这个权限在本地回收，容器内的终端不影响

# 1>/dev/null 表示终端输出的重定向到 /dev/null（特殊目录，用来丢弃一些输出）
# 2>&1 表示把标准错误重定向到标准输出相同的地址上

xhost +local:root 1>/dev/null 2>&1
docker exec \
    -u root \
    -it linux_monitor \
    /bin/bash
xhost -local:root 1>/dev/null 2>&1