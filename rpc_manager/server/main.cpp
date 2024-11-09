#include <iostream>

#include <grpc/grpc.h>
#include <grpcpp/server_builder.h>

#include "rpc_manager.h"

// 监听所有ip 端口号为50051
// constexpr是c++11引入的关键字，constexpr修饰的变量和函数在编译时就被求值
// 这允许编译器在编译时期完成更多的计算工作,从而提升程序的运行效率
constexpr char kServerPortInfo[] = "0.0.0.0:50051";
// 初始化服务器
void InitServer() {
  // ServerBuilder是用于创建和启动grpc::Server实例的构建器类
  grpc::ServerBuilder builder;
  // AddListeningPort指定我们要用于侦听客户端请求的地址和端口
  // grpc::InsecureChannelCredentials()表示没有身份验证或加密
  builder.AddListeningPort(kServerPortInfo, grpc::InsecureServerCredentials());
  // 继承了GrpcManager::Service的自定义server
  monitor::GrpcManagerImpl grpc_server;
  // 注册服务
  builder.RegisterService(&grpc_server);

  // builder.BuildAndStart()，准备好处理调用
  // 意味着服务器已经启动并且可以接受和处理来自客户端的请求
  std::unique_ptr<grpc::Server> server(builder.BuildAndStart());
  server->Wait();  // 阻塞等待监听

  return;
}

int main() {
  InitServer();
  return 0;
}