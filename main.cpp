#include <QApplication>
#include <QTextEdit>
#include <QPushButton>
#include <QVBoxLayout>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QTextEdit textEdit;
    QPushButton sendButton("send");

    QObject::connect(&sendButton, SIGNAL(clicked()), qApp, SLOT(quit()));

    QVBoxLayout layout;
    layout.addWidget(&textEdit);
    layout.addWidget(&sendButton);

    QWidget window;
    /* 17 */ window.setLayout(&layout);
    window.show();


    return QApplication::exec();
}
