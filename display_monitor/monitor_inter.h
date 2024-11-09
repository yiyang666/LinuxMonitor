#pragma once
#include <QAbstractTableModel>
#include <QObject>

namespace monitor {

// QAbstractTableModel 继承自 QAbstractItemModel
// 主要用于为 QTableView 提供相关接口，我们可以子类化该抽象类并实现相关接口
// 自定义数据模型，就是给窗体中的表格进行修饰（行名，列名，数据，颜色，大小等）
class MonitorInterModel : public QAbstractTableModel {
  Q_OBJECT

 public:
  explicit MonitorInterModel(QObject *parent = nullptr)
      : QAbstractTableModel(parent) {}

  // 设置布局，颜色等
  QVariant data(const QModelIndex &index,
                int role = Qt::DisplayRole) const override;

  // 设置列名，大小，背景颜色等
  QVariant headerData(int section, Qt::Orientation orientation,
                      int role) const override;
  virtual ~MonitorInterModel() {}
};

}  // namespace monitor