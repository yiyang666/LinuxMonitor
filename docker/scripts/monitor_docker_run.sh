#!/usr/bin/env bash

# BASH_SOURCE[0] == /home/young/workspace/c++_work/private-node/docker/scripts/monitor_docker_run.sh
# dirname BASH_SOURCE[0] == /home/young/workspace/c++_work/private-node/docker/scripts
# MONITOR_HOME_DIR == /home/young/workspace/c++_work/private-node

MONITOR_HOME_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )/../.." && pwd )"

display=""
if [ -z ${DISPLAY} ];then
    display=":1"
else
    display="${DISPLAY}"
fi

# 本机信息
local_host="$(hostname)"
user="${USER}"
uid="$(id -u)"
group="$(id -g -n)"
gid="$(id -g)"

# 先停止删除上一个同名容器，> /dev/null 把输出丢弃
# 所以每次重新run，都要重新 cmake 和 make，相当于新创建了一个容器
echo "stop and rm docker" 
docker stop linux_monitor > /dev/null
docker rm -v -f linux_monitor > /dev/null

echo "start docker"
# -it 交互型 -d后台运行 -e 设置容器所需的环境变量 --name 命名
# -v 参数 挂载数据卷，把主机文件目录挂载到容器的/work里  MONITOR_HOME_DIR --> /work
# --net host 使用本机的所有资源
# 注意 \ 后面不能有空格
docker run -it -d \
--name linux_monitor \
-e DISPLAY=$display \
--privileged=true \
-e DOCKER_USER="${user}" \
-e USER="${user}" \
-e DOCKER_USER_ID="${uid}" \
-e DOCKER_GRP="${group}" \
-e DOCKER_GRP_ID="${gid}" \
-e XDG_RUNTIME_DIR=$XDG_RUNTIME_DIR \
-v ${MONITOR_HOME_DIR}:/work \
-v ${XDG_RUNTIME_DIR}:${XDG_RUNTIME_DIR} \
--net host \
linux:monitor
#容器id