//
// Created by m1a on 8/18/25.
//

#ifndef SIMPLETODO_TODOITEM_H
#define SIMPLETODO_TODOITEM_H
#include <QVariant>

namespace todo {
    class TodoItem {
    public:
        TodoItem(QVariant data, TodoItem *parent = nullptr);
        TodoItem(TodoItem &&item);
        TodoItem& operator=(TodoItem &&item);
        ~TodoItem();

        void appendChild(std::unique_ptr<TodoItem> &&child);

        TodoItem* child(int row) const;
        inline TodoItem* parent() const;
        inline int childCount() const;
        int row() const;
        QVariant data(int column) const;
        void removeChild(int row);
        void removeChildRecursively() const;

        TodoItem(TodoItem &item) = delete;
        TodoItem& operator=(TodoItem &item) = delete;

    protected:
        std::vector<TodoItem*>& internalTodos();

    private:
        std::vector<TodoItem *> m_child;
        TodoItem *m_parent;
        QVariant m_data;
    };
} // todo

#endif //SIMPLETODO_TODOITEM_H