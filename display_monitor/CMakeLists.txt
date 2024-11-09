#
# Dependencies

# 查找Qt的依赖库
find_package(Qt5 
  REQUIRED COMPONENTS
  Core
  Widgets
)
# 设置源文件
set(SOURCES
    main.cpp
    monitor_inter.cpp
    cpu_softirq_model.cpp
    cpu_load_model.cpp
    monitor_widget.cpp
    cpu_stat_model.cpp
    mem_model.cpp
    net_model.cpp
)

# source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCES})

#
# Target
#
add_executable(display ${SOURCES})

# AUTOMOC是Qt编译器的一个特性，它可以自动生成元对象代码（Meta-Object Code）。
# 这些代码是Qt用来实现信号与槽机制、动态属性、以及其他一些高级功能的基础。
# 在类之前需要加上 Q_OBJECT ，才能使用QT中的signal和slot机制
# 与此同时，这里也需要将AUTOMOC设置打开，才能顺利使用Q_OBJECT
set_target_properties(display PROPERTIES AUTOMOC TRUE)

# 添加额外的头文件库的路径
target_include_directories(display PUBLIC
  ${PROJECT_SOURCE_DIR}/rpc_manager
)

# 指定依赖库
target_link_libraries(display
    PUBLIC
    client
    monitor_proto
    Qt5::Widgets
    Qt5::Core
    # qwt-qt5
)


# INSTALL(TARGETS client
#        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
#        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
#        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
# )
