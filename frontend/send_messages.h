#ifndef QT_SEND_MESSAGES_H
#define QT_SEND_MESSAGES_H

#include <QWidget>
#include <QBoxLayout>
#include <QTextEdit>
#include <QScrollArea>

class SendMessages : public QWidget {
Q_OBJECT
public:
    explicit SendMessages(QWidget* parent = nullptr);

    ~SendMessages() override = default;

public slots:
    void AddMessage(const QTextEdit* text,  const Qt::AlignmentFlag& flag);

signals:
    void MessageAdd();

private:
    QBoxLayout* verticalLayout_ = nullptr;
    QString styleShitTextEdit_ = "background-color: #8ead9e; "
                                 "border-style: outset; "
                                 "border-width: 4px; "
                                 "border-radius: 20px; "
                                 "border-color: #8e90b6; "
                                 "font: bold 14px; "
                                 "color: black; "
                                 "padding: 6px; ";
};

class ScrollMessagesArea : public QScrollArea {
Q_OBJECT
public:
    explicit ScrollMessagesArea(QWidget* parent = nullptr);

    ~ScrollMessagesArea() override = default;

public slots:
    void Scroll();

private:
    QString styleShitArea_ = " border: 0px; ";
};

#endif //QT_SEND_MESSAGES_H