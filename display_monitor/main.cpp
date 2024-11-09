#pragma once

#include <QApplication>
#include <thread>

#include "client/rpc_client.h"
#include "monitor_widget.h"

int main(int argc, char* argv[]) {
  // Qt的GUI应用对象，管理GUI程序的控制流和主要设置，具有唯一性
  // 相当于Qt程序的入口，声明Qt程序，与后面的app.exec()对应，启动Qt程序
  QApplication app(argc, argv);

  std::string server_address = "localhost:50051";
  if (argc > 1) {
    server_address = argv[1];
  }

  monitor::MonitorWidget moitor_widget;  //继承QWidget类的子类窗口
  monitor::RpcClient rpc_client(server_address); //初始化一个RPC客户端
  monitor::proto::MonitorInfo monitor_info;

  // get board name 调用RPC服务获取数据，数据从monitor_info传出
  rpc_client.GetMonitorInfo(&monitor_info);
  std::string name = monitor_info.name();

  // 调用主窗体，父类QWidget指针指向子类moitor_widget对象
  QWidget* widget = moitor_widget.ShowAllMonitorWidget(name);
  widget->show();  // 调用父类的成员方法show()呈现窗体

  // 通过子线程不断从grpc中获取数据
  std::unique_ptr<std::thread> thread_;
  thread_ = std::make_unique<std::thread>([&]() {
    while (true) {
      monitor_info.Clear();
      rpc_client.GetMonitorInfo(&monitor_info);
      // 每2秒更新一次数据
      moitor_widget.UpdateData(monitor_info);
      std::this_thread::sleep_for(std::chrono::seconds(2));
    }
  });
  // 若采用join，将无法继续向下指向，主线程会阻塞等待回收子线程
  // detach采用线程分离，不等待回收子线程的资源
  thread_->detach();

  return app.exec();
}