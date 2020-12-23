#include "mainwindow.h"

#include <QApplication>
#include <QScrollArea>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    auto* area = new QScrollArea;
    area->resize(800, 800);
    area->setMinimumHeight(500);
    area->setMinimumWidth(500);
    area->setWidgetResizable(true);

    auto* window = new MainWindow(area);
    area->setWidget(window);
    area->show();

    return QApplication::exec();
}
