#
# Dependencies
#
# find_package(Threads)

#
# Sources
#
set(SOURCES
    main.cpp
    rpc_manager.cpp
)

# source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCES})

# target_include_directories(server PUBLIC
#   ${PROJECT_SOURCE_DIR}/..
# )
#
# Target
#
# 可执行程序，时刻监听所有ip下指定端口的客户端请求
add_executable(server ${SOURCES})
# 链接库
target_link_libraries(server
    PUBLIC
    monitor_proto
)
