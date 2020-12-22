#ifndef QT_MESSAGE_SENT_CPP_H
#define QT_MESSAGE_SENT_CPP_H

#include <QApplication>
#include <QWidget>
#include <QTextEdit>
#include <QPushButton>
#include <QHBoxLayout>

class Message : public QWidget {
public:
    explicit Message(QBoxLayout* mL, QWidget* parent = nullptr) : QWidget(parent), textEdit(new QTextEdit(this)),
            sendButton(new QPushButton("send", this)), mL(mL) {
        textEdit->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        textEdit->setFixedHeight(2 * sendButton->height());
        QObject::connect(sendButton, SIGNAL(clicked()), this, SLOT(Send()));
    }

    void addToLayout(QHBoxLayout* layout) {
        if (layout == nullptr) {
            return;
        }
        layout->setSpacing(1);
        layout->addWidget(textEdit, 1);
        layout->addWidget(sendButton, 0);
    }

public slots:
    void Send() {
        auto* prevMessage = new QTextEdit(textEdit->toPlainText());
        prevMessage->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        prevMessage->setFixedHeight(2 * sendButton->height());

        mL->addWidget(prevMessage, 1, Qt::AlignRight | Qt::AlignBottom);
        mL->insertStretch(0, 100);
        textEdit->clear();
    }

private:
    QTextEdit* textEdit = nullptr;
    QPushButton* sendButton = nullptr;
    QBoxLayout* mL = nullptr;
    Q_OBJECT
};

#endif //QT_MESSAGE_SENT_CPP_H
