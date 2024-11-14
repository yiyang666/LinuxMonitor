#pragma once

#include <QAbstractTableModel>
#include <vector>
#include "monitor_inter.h"

#include "monitor_info.grpc.pb.h"
#include "monitor_info.pb.h"

namespace monitor {

class CpuLoadModel : public MonitorInterModel {
  Q_OBJECT

 public:
  // 禁止隐式类型转换，避免意外的类型转换
  explicit CpuLoadModel(QObject *parent = nullptr);

  virtual ~CpuLoadModel() {}

  int rowCount(const QModelIndex &parent = QModelIndex()) const override;
  int columnCount(const QModelIndex &parent = QModelIndex()) const override;
  QVariant data(const QModelIndex &index,
                int role = Qt::DisplayRole) const override;
  QVariant headerData(int section, Qt::Orientation orientation,
                      int role) const override;

  void UpdateMonitorInfo(const monitor::proto::MonitorInfo &monitor_info);

 signals:
  // 数据刷新，dataChanged()用于局部数据变动，而beginResetModel()用于整个视图的变化
  // 优化后统一使用beginResetModel()，这里没用上
  void dataChanged(const QModelIndex &topLeft, const QModelIndex &bottomRight,
                   const QVector<int> &roles);

 private:
  // 类型转换，通过这个函数把转换好的数据（QT数据类型）加入到数组中
  std::vector<QVariant> insert_one_cpu_load(
      const monitor::proto::CpuLoad &cpu_load);
  // Qt自带的数据类型的二维数组存放表格数据   
  std::vector<std::vector<QVariant>> monitor_data_;
  QStringList header_; // 标题
  // 枚举类型
  enum CpuLoad {
    CPU_AVG_1 = 0,
    CPU_AVG_3,
    CPU_AVG_15,
    COLUMN_MAX
  };
};

}  // namespace monitor