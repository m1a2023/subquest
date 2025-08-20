#include <QApplication>
#include "widgets/mainwindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    todo::MainWindow window;
    window.show();
    return QApplication::exec();
}
