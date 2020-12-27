#include "main_window.h"
#include "frontend/input_field.h"
#include "frontend/send_messages.h"
#include "server.h"

#include <QApplication>
#include <QScrollArea>

void Ui_MainWindow::SetupUi(QMainWindow* MainWindow) {
    if (MainWindow->objectName().isEmpty()) {
        MainWindow->setObjectName("MainWindow");
    }
    centralWidget = new QWidget(MainWindow);
    centralWidget->setObjectName("centralWidget");

    auto* generalLayout = new QBoxLayout(QBoxLayout::TopToBottom);
    auto* textInput = new InputField();
    auto* sendMessages = new SendMessages();
    auto* area = new ScrollMessagesArea();
    auto* server = new Server(9000);

    area->setWidget(sendMessages);

    QObject::connect(textInput, &InputField::Send, sendMessages, &SendMessages::AddMessage);
    QObject::connect(textInput, &InputField::Send, server, &Server::SendToClient);
    QObject::connect(sendMessages, &SendMessages::MessageAdd, area, &ScrollMessagesArea::Scroll);
    QObject::connect(server, &Server::GetMessage, sendMessages, &SendMessages::AddMessage);

    generalLayout->addWidget(area, 0);
    generalLayout->addWidget(textInput, 0);

    centralWidget->setLayout(generalLayout);
    MainWindow->setCentralWidget(centralWidget);
    RetranslateUi(MainWindow);
    QMetaObject::connectSlotsByName(MainWindow);
}

void Ui_MainWindow::RetranslateUi(QMainWindow* MainWindow) {
    MainWindow->setWindowTitle(QApplication::translate("MainWindow",
            "MainWindow", Q_NULLPTR));
}

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent), ui(new Ui::MainWindow()) {
    ui->SetupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}