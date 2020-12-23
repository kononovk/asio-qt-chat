#ifndef QT_MESSAGE_SENT_CPP_H
#define QT_MESSAGE_SENT_CPP_H

#include <QApplication>
#include <QWidget>
#include <QTextEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QShortcut>
#include <QScrollArea>

class Message : public QWidget {
public:
    explicit Message(QScrollArea* scrollArea, QWidget* parent = nullptr);

    void AddToLayout(QHBoxLayout* layout);
    void SetShortcutOnSending(const QString& shortcut);

    ~Message() = default;

public slots:
    void SendMessage();

private:
    QTextEdit* textEdit_ = nullptr;
    QPushButton* sendButton_ = nullptr;
    QBoxLayout* layoutSentMessages_ = nullptr;
    QMap<QString, QShortcut*> keyboards;
    QScrollArea* scrollArea_ = nullptr;
    QString styleShitTextBox_ = " background-color: #8ead9e; "
                                "border-style: outset; "
                                "border-width: 4px; "
                                "border-radius: 20px; "
                                "border-color: #8e90b6; "
                                "font: bold 14px; "
                                "color: black; "
                                "padding: 6px; ";
    QString styleShitButton_ = " background-color: #8ead9e; "
                               "border-style: outset; "
                               "border-width: 2px; "
                               "border-radius: 10px; "
                               "border-color: #8e90b6; "
                               "font: bold 13px; "
                               "color: black; "
                               "min-width: 4em; "
                               "padding: 6px; ";
    bool TextEditIsEmpty() const;

    Q_OBJECT
};

#endif //QT_MESSAGE_SENT_CPP_H
