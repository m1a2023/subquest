//
// Created by m1a on 8/18/25.
//

#ifndef SIMPLETODO_MAINWINDOW_H
#define SIMPLETODO_MAINWINDOW_H

#include <QMainWindow>
#include <qtmetamacros.h>

#include "todolistwidget.h"

namespace todo {
    class TodoModel;

    class MainWindow : public QMainWindow {
        Q_OBJECT

        /* Methods */
    public:
        explicit MainWindow(QWidget *parent = nullptr);
        ~MainWindow() override;

    private :
        void initUI();

        /* Members*/
    private:
        TodoModel *m_todoModel;
        TodoListWidget *m_todoListWidget = nullptr;


    };
} // todo

#endif //SIMPLETODO_MAINWINDOW_H