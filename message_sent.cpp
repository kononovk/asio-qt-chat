#include "message_sent.h"

#include <QWidget>
#include <QTextEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QShortcut>
#include <QScrollBar>

Message::Message(QScrollArea* scrollArea, QWidget* parent) : QWidget(parent),
        textEdit_(new QTextEdit(this)), sendButton_(new QPushButton("send", this)),
        keyboards({}), scrollArea_(scrollArea),
        layoutSentMessages_(new QBoxLayout(QBoxLayout::TopToBottom, this)) {
    sendButton_->setStyleSheet(styleShitButton_);
    textEdit_->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    textEdit_->setFixedHeight(2 * sendButton_->height());
    textEdit_->setFixedWidth(300);
    textEdit_->setStyleSheet(styleShitTextBox_);
    QObject::connect(sendButton_, SIGNAL(clicked()), this, SLOT(SendMessage()));
    SetShortcutOnSending("Ctrl+Return");
}

void Message::AddToLayout(QHBoxLayout* layout) {
    if (layout == nullptr) {
        return;
    }
    layout->setSpacing(1);
    layout->insertStretch(0, 1);
    layout->addWidget(textEdit_, 1);
    layout->addWidget(sendButton_, 0);
}

void Message::SetShortcutOnSending(const QString& shortcut) {
    if (keyboards.contains(shortcut)) {
        return;
    }
    auto key = new QShortcut(QKeySequence(shortcut), this);
    QObject::connect(key, SIGNAL(activated()), this, SLOT(SendMessage()));
    keyboards[shortcut] = key;
}

void Message::SendMessage() {
    if (TextEditIsEmpty()) {
        return;
    }
    auto* prevMessage = new QTextEdit(textEdit_->toPlainText());
    prevMessage->setStyleSheet(styleShitTextBox_);
    prevMessage->setReadOnly(true);
    prevMessage->setFixedWidth(textEdit_->width());
    prevMessage->setFixedHeight(textEdit_->document()->size().toSize().height() + 20);
    prevMessage->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    layoutSentMessages_->addWidget(prevMessage, 1, Qt::AlignRight | Qt::AlignBottom);
    layoutSentMessages_->insertStretch(0, 100);
    textEdit_->clear();
    scrollArea_->verticalScrollBar()->setValue(layoutSentMessages_->maximumSize().height());
}

bool Message::TextEditIsEmpty() const {
    return textEdit_->toPlainText().isEmpty() ? true : textEdit_->toPlainText().remove(" ").remove( "\n").isEmpty();
}