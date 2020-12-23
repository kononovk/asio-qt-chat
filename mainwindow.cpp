#include "mainwindow.h"
#include "message_sent.h"
#include "ui_mainwindow.h"

#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QHeaderView>
#include <QMainWindow>
#include <QWidget>
#include <QBoxLayout>

void Ui_MainWindow::setupUi(QScrollArea* scrollArea, QMainWindow *MainWindow)
{
    if (MainWindow->objectName().isEmpty())
        MainWindow->setObjectName("MainWindow");
//    MainWindow->resize(800, 800);

    auto* message = new Message(scrollArea);
    message->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

    auto* hLayout = new QHBoxLayout();
    message->AddToLayout(hLayout);

    auto* layout = new QVBoxLayout();
    layout->setSpacing(10);
    layout->addWidget(message, 0, Qt::AlignBottom);
    layout->addLayout(hLayout, 1);

    centralWidget = new QWidget(MainWindow);
    centralWidget->setObjectName("centralWidget");
    centralWidget->setLayout(layout);

    MainWindow->setCentralWidget(centralWidget);
    retranslateUi(MainWindow);

    QMetaObject::connectSlotsByName(MainWindow);
}

void Ui_MainWindow::retranslateUi(QMainWindow *MainWindow)
{
    MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
}

MainWindow::MainWindow(QScrollArea* scrollArea, QWidget *parent)
        : QMainWindow(parent)
        , ui(new Ui::MainWindow()) {
    ui->setupUi(scrollArea, this);
}

MainWindow::~MainWindow() {
    delete ui;
}