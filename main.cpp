#include "message_sent.h"

#include <QApplication>
#include <QVBoxLayout>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    auto* messageLayout = new QBoxLayout(QBoxLayout::TopToBottom);

    auto* message = new Message(messageLayout);
    message->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

    auto* hLayout = new QHBoxLayout();
    message->addToLayout(hLayout);

    auto* layout = new QVBoxLayout();
    layout->setSpacing(10);
    layout->addLayout(messageLayout, 1);
    layout->addWidget(message, 0, Qt::AlignBottom);
    layout->addLayout(hLayout, 1);

    auto* window = new QWidget();
    window->resize(800, 230);
    window->setLayout(layout);
    window->show();

    return QApplication::exec();
}
