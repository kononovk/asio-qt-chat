#include "main_window.h"

#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    auto* window = new MainWindow();
    window->resize(800, 800);
    window->show();

    return QApplication::exec();
}
