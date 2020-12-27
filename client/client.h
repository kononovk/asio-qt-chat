#ifndef QT_CLIENT_H
#define QT_CLIENT_H

#include <QObject>
#include <QWidget>
#include <QTcpSocket>
#include <QTextEdit>

class Client : public QWidget {
Q_OBJECT
public:
    Client(const QString& host, int port, QWidget* parent = nullptr);

    ~Client() override = default;

public slots:
    void SlotSendToServer(const QTextEdit* message,  const Qt::AlignmentFlag& flag);
private slots:
    void SlotReadyRead();
    void SlotError(QAbstractSocket::SocketError);
    void SlotConnected();
signals:
    void GetMessage(const QTextEdit* message,  const Qt::AlignmentFlag& flag);

private:
    QTcpSocket* socket_ = nullptr;
    quint16 receivedBlockSize_ = 0;
};

#endif //QT_CLIENT_H