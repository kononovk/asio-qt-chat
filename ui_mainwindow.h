#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget* centralWidget;

    void setupUi(QScrollArea* scrollArea, QMainWindow *MainWindow);
    static void retranslateUi(QMainWindow *MainWindow);
};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
}

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
