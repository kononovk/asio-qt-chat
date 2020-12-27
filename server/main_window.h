#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
class Ui_MainWindow {
public:
    QWidget* centralWidget = nullptr;

    void SetupUi(QMainWindow* MainWindow);
    static void RetranslateUi(QMainWindow* MainWindow);
};

namespace Ui {
    class MainWindow : public Ui_MainWindow {};
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
Q_OBJECT
public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow() override;

private:
    Ui::MainWindow* ui;
};

#endif // MAINWINDOW_H