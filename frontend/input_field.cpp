#include "frontend/input_field.h"

#include <QWidget>
#include <QTextEdit>
#include <QPushButton>
#include <QShortcut>

InputField::InputField(QWidget* parent) : QWidget(parent), textEdit_(new QTextEdit()),
        sendButton_(new QPushButton("send")),
        horizontalLayout_(new QBoxLayout(QBoxLayout::LeftToRight, this)) {
    sendButton_->setFixedSize(50, 40);
    sendButton_->setStyleSheet(styleShitButton_);

    textEdit_->setStyleSheet(styleShitTextEdit_);
    textEdit_->setFixedHeight(2 * sendButton_->height());
    textEdit_->setMinimumWidth(4 * sendButton_->width());
    textEdit_->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

    horizontalLayout_->setSpacing(10);
    horizontalLayout_->addWidget(textEdit_, 1);
    horizontalLayout_->addWidget(sendButton_, 0);

    auto* key = new QShortcut(QKeySequence("Ctrl+Return"), this);
    QObject::connect(sendButton_, &QPushButton::clicked, this, &InputField::SendMessage);
    QObject::connect(key, &QShortcut::activated, this, &InputField::SendMessage);
}

void InputField::SendMessage() {
    if (InputIsEmpty()) {
        return;
    }
    emit InputField::Send(textEdit_, Qt::AlignRight);
    textEdit_->clear();
}

bool InputField::InputIsEmpty() const {
    return textEdit_->toPlainText().remove(" ").remove( "\n").isEmpty();
}
