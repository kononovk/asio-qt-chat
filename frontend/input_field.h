#ifndef QT_INPUT_FIELD_CPP_H
#define QT_INPUT_FIELD_CPP_H

#include <QWidget>
#include <QTextEdit>
#include <QPushButton>
#include <QBoxLayout>

class InputField : public QWidget {
Q_OBJECT
public:
    explicit InputField(QWidget* parent = nullptr);

    ~InputField() override = default;

public slots:
    void SendMessage();
signals:
    void Send(const QTextEdit* text, const Qt::AlignmentFlag& flag);

private:
    QTextEdit* textEdit_ = nullptr;
    QPushButton* sendButton_ = nullptr;
    QBoxLayout* horizontalLayout_ = nullptr;
    QString styleShitTextEdit_ = "background-color: #8ead9e; "
                                "border-style: outset; "
                                "border-width: 4px; "
                                "border-radius: 20px; "
                                "border-color: #8e90b6; "
                                "font: bold 14px; "
                                "color: black; "
                                "padding: 6px; ";
    QString styleShitButton_ = "background-color: #8ead9e; "
                               "border-style: outset; "
                               "border-width: 2px; "
                               "border-radius: 10px; "
                               "border-color: #8e90b6; "
                               "font: bold 13px; "
                               "color: black; "
                               "min-width: 4em; "
                               "padding: 6px; ";

    bool InputIsEmpty() const;
};

#endif //QT_INPUT_FIELD_CPP_H
