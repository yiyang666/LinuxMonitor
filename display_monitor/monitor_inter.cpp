#include "monitor_inter.h"

#include <QColor>
#include <QFont>

namespace monitor {

QVariant MonitorInterModel::headerData(int section, Qt::Orientation orientation,
                                       int role) const {
  // 字体设置
  if (role == Qt::FontRole) {
    return QVariant::fromValue(QFont("Microsoft YaHei", 10, QFont::Bold));
  }
  // 背景颜色
  if (role == Qt::BackgroundRole) {
    // return QVariant::fromValue(QColor(Qt::lightGray));
    return QVariant::fromValue(QColor(220, 220, 220));
  }
  // 前景颜色
  if (role == Qt::ForegroundRole) {
    return QVariant::fromValue(QColor(Qt::darkBlue));
  }

  return QAbstractTableModel::headerData(section, orientation, role);
}

QVariant MonitorInterModel::data(const QModelIndex &index, int role) const {
  // 文字布局
  if (role == Qt::TextAlignmentRole) {
    return QVariant(Qt::AlignLeft | Qt::AlignVCenter);
  }
  // 颜色
  // if (role == Qt::TextColorRole) {
  if (role == Qt::ForegroundRole) {
    return QVariant::fromValue(QColor(Qt::black));
  }
  // 单元格背景
  if (role == Qt::BackgroundRole) {
    // 背景交替颜色
    if (index.row() % 2 == 0) {
      return QVariant::fromValue(QColor(230, 230, 230));// 浅灰色
    } else {
      return QVariant::fromValue(QColor(225,255,255));  // 白色
    }
  }

  return QVariant();
}

}  // namespace monitor