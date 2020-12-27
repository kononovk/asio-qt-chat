#ifndef QT_SERVER_H
#define QT_SERVER_H

#include <QTextEdit>
#include <QTcpServer>
#include <QTextEdit>

class Server : public QWidget {
Q_OBJECT
public:
    Server(int port, QWidget* parent = nullptr);

    ~Server() override = default;

public slots:
    virtual void SlotNewConnection();
    void SlotReadClient();
    void SendToClient(const QTextEdit* message,  const Qt::AlignmentFlag& flag);
signals:
    void GetMessage(const QTextEdit* message,  const Qt::AlignmentFlag& flag);

private:
    QTcpServer* server_ = nullptr;
    QTcpSocket* socket_ = nullptr;
    quint16 receivedBlockSize_ = 0;
};


#endif //QT_SERVER_H
