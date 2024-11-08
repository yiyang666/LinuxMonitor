
# 设置依赖.cpp文件
set(SOURCES
   main.cpp
   monitor/cpu_softirq_monitor.cpp
   monitor/cpu_load_monitor.cpp
   monitor/cpu_stat_monitor.cpp
   monitor/mem_monitor.cpp
   monitor/net_monitor.cpp
   utils/read_file.cpp
)

# 命名可执行程序
add_executable(monitor ${SOURCES})

# target_include_directories(monitor PUBLIC
#   ../include/..
# )

# 设置头文件路径
target_include_directories(monitor PUBLIC
  ${PROJECT_SOURCE_DIR}/test_monitor/include
  ${PROJECT_SOURCE_DIR}/rpc_manager
)

# 第三方库
target_link_libraries(monitor
    PUBLIC
    monitor_proto
    client
    boost_system
    boost_chrono
)