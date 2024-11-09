#
# Dependencies
#
# find_package(Threads)

#
# Sources
#
set(SOURCES
    # main.cpp 客户端不需要一直运行
    rpc_client.cpp
)

# source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCES})

#
# Target
#
# add_executable(client ${SOURCES})
add_library(client  ${SOURCES})

# Public这个关键字表示 "monitor_proto" 库是公开的，
# 也就是说，任何链接到 "client" 库的目标都可以间接地链接到 "monitor_proto" 库。
target_link_libraries(client
    PUBLIC
    monitor_proto

)


# INSTALL(TARGETS client
#        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
#        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
#        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
# )
