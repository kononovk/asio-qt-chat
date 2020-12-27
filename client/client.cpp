#include "client.h"

#include <iostream>
#include <QWidget>
#include <QTcpSocket>

Client::Client(const QString& host, int port, QWidget* parent) : QWidget(parent),
        socket_(new QTcpSocket(this)) {
    socket_->connectToHost(host, port);
    connect(socket_, SIGNAL(connected()), SLOT(SlotConnected()));
    connect(socket_, SIGNAL(readyRead()), SLOT(SlotReadyRead()));
    connect(socket_, SIGNAL(error(QAbstractSocket::SocketError)),
            this, SLOT(SlotError(QAbstractSocket::SocketError)));
}

void Client::SlotReadyRead() {
    QDataStream in(socket_);
    in.setVersion(QDataStream::Qt_5_9);
    while (true) {
        if (receivedBlockSize_ == 0) {
            if (static_cast<unsigned int>(socket_->bytesAvailable()) < sizeof(quint16)) {
                break;
            }
            in >> receivedBlockSize_;
        }

        if (socket_->bytesAvailable() < receivedBlockSize_) {
            break;
        }
        QString message;
        in >> message;
        receivedBlockSize_ = 0;
        auto* edit = new QTextEdit(message);
        emit GetMessage(edit, Qt::AlignLeft);
    }
}

void Client::SlotError(QAbstractSocket::SocketError err) {
    QString strError("Client Error: ");
    if (err == QAbstractSocket::HostNotFoundError) {
        strError.append("The host was not found.");
    } else if (err == QAbstractSocket::RemoteHostClosedError) {
        strError.append( "The remote host is closed.");
    } else if (err == QAbstractSocket::ConnectionRefusedError) {
        strError.append( "The connection was refused.");
    } else {
        strError.append(err);
    }
    std::cerr << strError.toStdString() << std::endl;
}

void Client::SlotSendToServer(const QTextEdit* message,  const Qt::AlignmentFlag& flag) {
    QByteArray arrBlock;
    QDataStream out(&arrBlock, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_9);
    out << quint16(0) << message->toPlainText();

    out.device()->seek(0);
    out << quint16(arrBlock.size() - sizeof(quint16));

    socket_->write(arrBlock);
}

void Client::SlotConnected() {
    std::cout << "successful connection"<< std::endl;
}
