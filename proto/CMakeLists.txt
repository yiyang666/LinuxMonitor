find_package(protobuf CONFIG REQUIRED)
find_package(gRPC CONFIG REQUIRED)
find_package(c-ares CONFIG)
# find_package(Threads)

# 将 Protobuf 定义文件编译成 C++ 消息类和 gRPC 服务端/客户端代码的过程
# 为后续使用 gRPC 提供了基础
#
# Protobuf/Grpc source files
#
# std::vector<>PROTO_FILES
set(PROTO_FILES
    monitor_info.proto
    cpu_load.proto
    cpu_softirq.proto
    cpu_stat.proto
    mem_info.proto
    net_info.proto
)

# 
# Add Library target with protobuf sources
#

# 生成monitor_proto静态库
# ${PROTO_FILES} 变量中的所有 .proto 文件都会被编译成 C++ 源文件，并链接到这个静态库中。
add_library(monitor_proto ${PROTO_FILES})

# 添加相关依赖库，这些库提供了处理 Protobuf 数据和 RPC 调用所需要的函数和类。
# protobuf::libprotobuf 是 Protobuf 库，提供了序列化和反序列化的功能。
# gRPC::grpc 和 gRPC::grpc++ 是 gRPC 库，提供了基于 Protobuf 的 RPC 框架。
target_link_libraries(monitor_proto
    PUBLIC
        protobuf::libprotobuf
        gRPC::grpc
        gRPC::grpc++
)

# 设置包含目录，头文件目录和存放c++源文件的目录
target_include_directories(monitor_proto PUBLIC
${PROTOBUF_INCLUDE_DIRS} 
${CMAKE_CURRENT_BINARY_DIR}
)

#
# Compile protobuf and grpc files in mointor proto target to cpp

# 结合grpc，每一个类通过.proto文件进行编译,在cmake命令中，
# protobuf_generate对应了protobuf compiler
# 分别对应生成了四个文件，pb.cc,pb.h,grpc.pb.cc,grpc.pb.h,grpc.pb.cc
#

# 使用 get_target_property 命令获取 gRPC 插件 (gRPC::grpc_cpp_plugin) 的位置
get_target_property(grpc_cpp_plugin_location gRPC::grpc_cpp_plugin LOCATION)

# 生成 .pb.h 和 .pb.cc 文件：
protobuf_generate(TARGET monitor_proto LANGUAGE cpp)

# 也是使用 protobuf_generate 命令，但用于生成 gRPC 相关的代码
# LANGUAGE grpc 表示生成 gRPC 服务端和客户端的存根代码。
# GENERATE_EXTENSIONS 指定要生成的扩展名 .grpc.pb.h/.grpc.pb.cc
# PLUGIN 告诉 protobuf_generate 使用 gRPC 插件来生成代码，并指定插件的位置
protobuf_generate(TARGET monitor_proto
    LANGUAGE grpc
    GENERATE_EXTENSIONS .grpc.pb.h .grpc.pb.cc
    PLUGIN "protoc-gen-grpc=${grpc_cpp_plugin_location}")
