#!/usr/bin/env bash
# BASH_SOURCE[0] == /home/young/workspace/c++_work/private-node/docker/scripts/monitor_docker_run.sh
# dirname BASH_SOURCE[0] == /home/young/workspace/c++_work/private-node/docker/scripts
# MONITOR_HOME_DIR == /home/young/workspace/c++_work/private-node
# 把这个这整个文件挂载到容器的/work里
# MONITOR_HOME_DIR --> /work
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


echo "stop and rm docker" 
docker stop linux_monitor > /dev/null
docker rm -v -f linux_monitor > /dev/null

echo "start docker"
# -it 交互型 -d后台运行 -e 容器所需的环境变量
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