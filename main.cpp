#include <QApplication>

#include "mainwindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    mainwindow w;
    w.setWindowTitle("illSurf");
    w.show();

    return app.exec();
}
