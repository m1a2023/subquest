//
// Created by m1a on 8/18/25.
//

#include "TodoItem.h"

namespace todo {
    TodoItem::TodoItem(QVariant data, TodoItem *parent)
        : m_parent{parent}, m_data{std::move(data)} { }

    TodoItem::TodoItem(TodoItem &&item)
        : m_parent{item.m_parent}, m_data{std::move(item.m_data)} {
        item.removeChildRecursively();
        item.m_parent = nullptr;
        item.m_data = 0;
    }

    TodoItem::~TodoItem() {
        removeChildRecursively();
        m_child.erase(m_child.begin(), m_child.end());
        m_parent = nullptr;
        m_data = 0;
    }

    TodoItem& TodoItem::operator=(TodoItem &&item) {
        m_parent = item.m_parent;
        m_data = std::move(item.m_data);
        m_child = std::move(item.m_child);

        item.removeChildRecursively();
        item.m_child.clear();
        item.m_parent = nullptr;
        item.m_data = 0;

        return *this;
    }

    void TodoItem::appendChild(std::unique_ptr<TodoItem> &&child) {
        m_child.push_back(child.get());
    }

    TodoItem* TodoItem::child(int row) const {
        return row >= 0 && row < childCount() ? m_child.at(row) : nullptr;
    }

    std::vector<TodoItem *>& TodoItem::internalTodos() {
        return m_child;
    }

    TodoItem *TodoItem::parent() const { return m_parent; }

    int TodoItem::childCount() const {
        return static_cast<int>(m_child.size());
    }

    int TodoItem::row() const {
        return 0;
    }

    QVariant TodoItem::data(int column) const { return m_data; }

    void TodoItem::removeChild(const int row) {
        if (row > 0 && row < m_child.size()) {
            m_child.erase(m_child.begin() + row - 1);
        }
    }

    void TodoItem::removeChildRecursively() const {
        for (const auto &item : m_child) {
            auto *tmp = item;
            if (! tmp->internalTodos().empty()) {
                tmp->removeChildRecursively();
            }
            delete tmp;
        }
    }
} // todo