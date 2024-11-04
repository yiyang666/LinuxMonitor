#!/usr/bin/env bash

# docker exec 
# 进入一个已经启动的容器,开启一个新终端,至少需要两个参数，这个终端(exit)不会停止容器，可以继续
# docker attach 
# 进入容器正在执行的终端，不会启动新的进程，在这个终端(exit)会停止整个容器，相当于stop
# docker start "容器id" 启动一个已有容器,分配默认终端
# docler stop "容器id"  关闭一个已有容器

xhost +local:root 1>/dev/null 2>&1
docker exec \
    -u root \
    -it linux_monitor \
    /bin/bash
xhost -local:root 1>/dev/null 2>&1