//
// Created by m1a on 8/18/25.
//

#include "mainwindow.h"

namespace todo {
    MainWindow::MainWindow(QWidget *parent)
        : QMainWindow{parent} {
        setWindowTitle("todoish");
        resize(1400, 800);

        initUI();
    }

    MainWindow::~MainWindow() { }

    void MainWindow::initUI() {
        m_todoListWidget = new TodoListWidget();
    }
} // todo