# LinuxMonitor
分布式LinuxC++性能监控

**技术栈：** C++，C++常用特性，Docker，CMake，gRPC，Protobuf，Qt

**项目概述：**这个项目旨在构建一个分布式的、功能强大和易于拓展的Linux系统性能分析监控系统，通过docker进行项目部署，实现对多台服务器的系统资源（CPU，内存，网络等）进行实时监控、分析和可视化。它可以帮助用户实时了解服务器的运行状态，及时发现潜在的问题，从而提高系统的稳定性和可靠性。

**主要工作：**

1. **Docker模块**：dockerfile指定相应的cmake，grpc，proto等源码和依赖，构建整个项目环境，易于在多台服务器上部署环境，并编写容器操作的脚本指令，易于启动操作项目所依赖的环境。
2. **monitor模块**：采用工厂方法，通过构造monitor的抽象类定义接口，然后实现相应的CPU状态，系统负载，软中断，mem，net监控，易于为之后扩展更多系统监控；并为了模拟出真实的性能问题，使用stress工具进行模拟压测，分析相应时刻服务器的cpu状况和中断状况。
3. 通过**grpc框架**，构建出相应的server， client；server在所要监控的服务器部署，client生成库供monitor模块和display模块调用，并考虑为了降低耦合性，项目每个模块相互独立，可拆解，只通过调用grpc服务来进行远程连接。
4. 使用**protobuf**序列化协议，构建出整个项目的数据结构。
5. **display模块**分为两大部分：UI界面的构造，datamodel构造；
UI界面使用QWidget、QTableView、QStackedLayout、QPushButton等进行构建
datamodel：通过继承QAbstractTableModel，构建出相应的cpu_model、softirq_model、mem_model等。