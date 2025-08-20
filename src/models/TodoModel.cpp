//
// Created by m1a on 8/18/25.
//

#include "TodoModel.h"

namespace todo {
    TodoModel::TodoModel(const QString& data, QObject* parent)
        : QAbstractItemModel(parent)
        , rootItem{std::make_unique<TodoItem>(QVariantList
            {tr("Title"), tr("Summary")})} {
        setupModelData(QStringView{data}.split(u'\n'), rootItem.get());
    }

    int TodoModel::rowCount(const QModelIndex&) const {
        return 1;
    }

    int TodoModel::columnCount(const QModelIndex&) const {
        return 2;
    }

    QVariant TodoModel::data(const QModelIndex& index, int role) const {
        if (role == Qt::DisplayRole) {
            return QString("Row%1, Column%2")
                .arg(index.row() + 1)
                .arg(index.column() + 1);
        }
        return {};
    }

    QModelIndex TodoModel::index(int row, int column, const QModelIndex& parent) const {
        if (! hasIndex(row, column, parent)) {
            return {};
        }

        TodoItem* parentItem = parent.isValid()
            ? static_cast<TodoItem*>(parent.internalPointer())
            : rootItem.get();

        if (auto *childItem = parentItem->child(row)) {
            return createIndex(row, column, childItem);
        }
        return {};
    }

} // todo