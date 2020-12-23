#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLayout>
#include <QScrollArea>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
public:
    MainWindow(QScrollArea* scrollArea, QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow* ui;
    Q_OBJECT
};
#endif // MAINWINDOW_H
