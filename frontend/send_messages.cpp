#include "send_messages.h"

#include <QTextEdit>
#include <QScrollBar>

SendMessages::SendMessages(QWidget *parent) : QWidget(parent),
    verticalLayout_(new QBoxLayout(QBoxLayout::TopToBottom, this)) { }

void SendMessages::AddMessage(const QTextEdit* text,  const Qt::AlignmentFlag& flag) {
    auto* message = new QTextEdit(text->toPlainText());

    message->setStyleSheet(styleShitTextEdit_);
    message->setReadOnly(true);
    message->show();
    message->setFixedWidth(400);
    message->setFixedHeight(message->document()->size().toSize().height() + 20);
    message->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    verticalLayout_->insertStretch(0, 100);
    verticalLayout_->addWidget(message, 0, flag | Qt::AlignBottom);

    emit MessageAdd();
}

ScrollMessagesArea::ScrollMessagesArea(QWidget* parent) : QScrollArea(parent) {
    setWidgetResizable(true);
    setStyleSheet(styleShitArea_);
}

void ScrollMessagesArea::Scroll() {
    verticalScrollBar()->setSliderPosition(maximumHeight());
}