//
// Created by m1a on 8/18/25.
//

#ifndef SIMPLETODO_TODOLISTWIDGET_H
#define SIMPLETODO_TODOLISTWIDGET_H
#include <QWidget>

namespace todo {
    class TodoListWidget : public QWidget {
        Q_OBJECT
    public:
        explicit TodoListWidget(QWidget *parent = nullptr);
        ~TodoListWidget() override;

        void initUI();

    private:
        //
    };
} // todo

#endif //SIMPLETODO_TODOLISTWIDGET_H