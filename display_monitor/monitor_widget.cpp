#include "monitor_widget.h"

namespace monitor {

MonitorWidget::MonitorWidget(QWidget *parent) {}

// 主窗体
QWidget *MonitorWidget::ShowAllMonitorWidget(const std::string& name) {
  QWidget *widget = new QWidget();
  // QStackedLayout类提供了多页面切换的布局，一次只能看到一个界面
  stack_menu_ = new QStackedLayout();
  // 堆栈式菜单，类似于窗口容器，把自定义的窗口都添加进去
  stack_menu_->addWidget(InitCpuMonitorWidget());
  stack_menu_->addWidget(InitSoftIrqMonitorWidget());
  stack_menu_->addWidget(InitMemMonitorWidget());
  stack_menu_->addWidget(InitNetMonitorWidget());

  // 设置布局，给按钮菜单和窗口容器的位置排序
  QGridLayout *layout = new QGridLayout(this);
  layout->addWidget(InitButtonMenu(name), 1, 0);
  layout->addLayout(stack_menu_, 2, 0);
  widget->setLayout(layout);
  return widget;
}

// 菜单按钮控件，控制大窗体每次只显示单独窗口
QWidget *MonitorWidget::InitButtonMenu(const std::string& name) {
  // char *name = getenv("USER");
  // 创建按钮并设置字体
  QPushButton *cpu_button = new QPushButton(QString::fromStdString(name) + "_cpu", this);
  QPushButton *soft_irq_button = new QPushButton(QString::fromStdString(name) + "_soft_irq", this);
  QPushButton *mem_button = new QPushButton(QString::fromStdString(name) + "_mem", this);
  QPushButton *net_button = new QPushButton(QString::fromStdString(name) + "_net", this);
  QFont *font = new QFont("Microsoft YaHei", 15, 40);
  cpu_button->setFont(*font);
  soft_irq_button->setFont(*font);
  mem_button->setFont(*font);
  net_button->setFont(*font);

  // QHBoxLayout()水平布局
  QHBoxLayout *layout = new QHBoxLayout();
  layout->addWidget(cpu_button);
  layout->addWidget(soft_irq_button);
  layout->addWidget(mem_button);
  layout->addWidget(net_button);

  QWidget *widget = new QWidget();
  widget->setLayout(layout);

  // connect()将按钮点击产生的信号连接到槽函数，在槽函数中编写按钮点击后要执行的代码
  connect(cpu_button, SIGNAL(clicked()), this, SLOT(ClickCpuButton()));
  connect(soft_irq_button, SIGNAL(clicked()), this, SLOT(ClickSoftIrqButton()));
  connect(mem_button, SIGNAL(clicked()), this, SLOT(ClickMemButton()));
  connect(net_button, SIGNAL(clicked()), this, SLOT(ClickNetButton()));

  return widget;
}

// cup_load和cpu_stat放在同一个窗体
QWidget *MonitorWidget::InitCpuMonitorWidget() {
  QWidget *widget = new QWidget();
  // 标签
  QLabel *cpu_load_label = new QLabel(this);
  cpu_load_label->setText(tr("Monitor CpuLoad:"));
  cpu_load_label->setFont(QFont("Microsoft YaHei", 10, 40));
  // 表格视图 + 数据
  cpu_load_monitor_view_ = new QTableView;
  cpu_load_model_ = new CpuLoadModel;
  cpu_load_monitor_view_->setModel(cpu_load_model_);
  cpu_load_monitor_view_->show();
  // 
  QLabel *cpu_stat_label = new QLabel(this);
  cpu_stat_label->setText(tr("Monitor CpuStat:"));
  cpu_stat_label->setFont(QFont("Microsoft YaHei", 10, 40));

  cpu_stat_monitor_view_ = new QTableView;
  cpu_stat_model_ = new CpuStatModel;
  cpu_stat_monitor_view_->setModel(cpu_stat_model_);
  cpu_stat_monitor_view_->show();

  QGridLayout *layout = new QGridLayout();

  layout->addWidget(cpu_stat_label, 1, 0, 1, 1);
  layout->addWidget(cpu_stat_monitor_view_, 2, 0, 1, 2);

  layout->addWidget(cpu_load_label, 3, 0);
  layout->addWidget(cpu_load_monitor_view_, 4, 0, 2, 2);

  widget->setLayout(layout);
  return widget;
}

QWidget *MonitorWidget::InitSoftIrqMonitorWidget() {
  // 新建一个窗口
  QWidget *widget = new QWidget();

  // 设置文本标签，字体，大小，间距等
  QLabel *monitor_label = new QLabel(this);
  monitor_label->setText(tr("Monitor softirq:"));
  monitor_label->setFont(QFont("Microsoft YaHei", 10, 40));

  // 设置表格视图
  monitor_view_ = new QTableView;
  monitor_model_ = new MonitorBaseModel;
  // QSortFilterProxyModel设置表格数据可排序model
  QSortFilterProxyModel *sort_proxy = new QSortFilterProxyModel(this);
  // 导入数据源
  sort_proxy->setSourceModel(monitor_model_);
  monitor_view_->setModel(sort_proxy);
  monitor_view_->setSortingEnabled(true); // 可排序
  monitor_view_->show(); // 展示

  // 设置布局
  QGridLayout *layout = new QGridLayout();
  // （控件，行，列，占用行，占用列）
  layout->addWidget(monitor_label, 1, 0);
  layout->addWidget(monitor_view_, 2, 0, 1, 2);
  widget->setLayout(layout);

  return widget;
}

QWidget *MonitorWidget::InitMemMonitorWidget() {
  QWidget *widget = new QWidget();

  // 文本组件对象，设置显示的文字，字体类型，大小
  QLabel *mem_label = new QLabel(this); // 标签 
  mem_label->setText(tr("Monitor mem:"));
  // QFont()方法用来设置字体类型和大小，字间距等
  mem_label->setFont(QFont("Microsoft YaHei", 10, 40));

  // 表格控件对象，再用成员方法setModel把数据添加进去，show()展示出来
  mem_monitor_view_ = new QTableView; // 表格
  mem_model_ = new MemModel;  // 数据
  mem_monitor_view_->setModel(mem_model_);
  mem_monitor_view_->show();

  // Qt的布局管理器，设置控件对象在窗口中的排列
  QGridLayout *layout = new QGridLayout();
  // addwidget(要添加的控件，行，列，占用行数，占用列数)
  layout->addWidget(mem_label, 1, 0);
  layout->addWidget(mem_monitor_view_, 2, 0, 1, 1);
  // 再调用窗口的成员方法应用这个布局
  widget->setLayout(layout);
  return widget;
}

QWidget *MonitorWidget::InitNetMonitorWidget() {
  QWidget *widget = new QWidget();

  // 标签
  QLabel *net_label = new QLabel(this);
  net_label->setText(tr("Monitor net:"));
  net_label->setFont(QFont("Microsoft YaHei", 10, 40));

  // 表格+数据
  net_monitor_view_ = new QTableView;
  net_model_ = new NetModel;
  net_monitor_view_->setModel(net_model_);
  net_monitor_view_->show();//展示
  
  // 布局
  QGridLayout *layout = new QGridLayout();
  layout->addWidget(net_label, 1, 0);
  layout->addWidget(net_monitor_view_, 2, 0, 1, 1);
  widget->setLayout(layout);

  return widget;
}

// 刷新操作是通过data_model进行刷新的
void MonitorWidget::UpdateData(
    const monitor::proto::MonitorInfo &monitor_info) {
  monitor_model_->UpdateMonitorInfo(monitor_info);
  cpu_load_model_->UpdateMonitorInfo(monitor_info);
  cpu_stat_model_->UpdateMonitorInfo(monitor_info);
  mem_model_->UpdateMonitorInfo(monitor_info);
  net_model_->UpdateMonitorInfo(monitor_info);
}


// 实现槽函数，将stack_menu中的窗口按序号显示出来，0 表示显示第一个添加的页面
void MonitorWidget::ClickCpuButton() { stack_menu_->setCurrentIndex(0); }
void MonitorWidget::ClickSoftIrqButton() { stack_menu_->setCurrentIndex(1); }
void MonitorWidget::ClickMemButton() { stack_menu_->setCurrentIndex(2); }
void MonitorWidget::ClickNetButton() { stack_menu_->setCurrentIndex(3); }
}  // namespace monitor
