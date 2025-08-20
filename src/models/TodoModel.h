//
// Created by m1a on 8/18/25.
//

#ifndef SIMPLETODO_TODOMODEL_H
#define SIMPLETODO_TODOMODEL_H

#include <QAbstractItemModel>

#include "src/items/TodoItem.h"

namespace todo {

    class TodoModel : public QAbstractItemModel {
        Q_OBJECT;

    public:
        Q_DISABLE_COPY_MOVE(TodoModel);

        explicit TodoModel(const QString& data, QObject* parent = nullptr);
        ~TodoModel() override;

        QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
        Qt::ItemFlags flags(const QModelIndex& index) const override;
        QVariant headerData(int section,
            Qt::Orientation orientation,
            int role = Qt::DisplayRole) const override;
        QModelIndex index(int row, int column,
            const QModelIndex& parent = {}) const override;
        QModelIndex parent(const QModelIndex& child) const override;
        int rowCount(const QModelIndex& parent = {}) const override;
        int columnCount(const QModelIndex& parent = {}) const override;

    private:
        static void setupModelData(const QList<QStringView> &lines,
            TodoItem* item);

        std::unique_ptr<TodoItem> rootItem;
    };
} // todo

#endif //SIMPLETODO_TODOMODEL_H