#include "server.h"

#include <iostream>
#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>

Server::Server(int port, QWidget* parent) : QWidget(parent), server_(new QTcpServer(this)),
        socket_(new QTcpSocket(this)) {
    if (!server_->listen(QHostAddress::Any, port)) {
        std::cerr << "Server Error: unable to start the server" << std::endl;
        server_->close();
        return;
    }
    connect(server_, SIGNAL(newConnection()), this, SLOT(SlotNewConnection()));
}

void Server::SlotNewConnection() {
    QTcpSocket* clientSocket = server_->nextPendingConnection();
    socket_ = clientSocket;
    connect(clientSocket, SIGNAL(disconnected()), clientSocket, SLOT(DeleteLater()));
    connect(clientSocket, SIGNAL(readyRead()),this, SLOT(SlotReadClient()));
}

void Server::SlotReadClient() {
    auto* clientSocket = qobject_cast<QTcpSocket*>(sender());
    socket_ = clientSocket;
    QDataStream in(clientSocket);
    in.setVersion(QDataStream::Qt_5_9);
    while (true) {
        if (receivedBlockSize_ == 0) {
            if (static_cast<unsigned int>(clientSocket->bytesAvailable()) < sizeof(quint16)) {
                break;
            }
            in >> receivedBlockSize_;
        }
        if (clientSocket->bytesAvailable() < receivedBlockSize_) {
            break;
        }
        QString message;
        in >> message;
        receivedBlockSize_ = 0;
        auto* edit = new QTextEdit(message);
        emit GetMessage(edit, Qt::AlignLeft);
    }
}

void Server::SendToClient(const QTextEdit* message,  const Qt::AlignmentFlag& flag) {
    QByteArray arrBlock;
    QDataStream out(&arrBlock, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_9);
    out << quint16(0) << message->toPlainText();

    out.device()->seek(0);
    out << quint16(arrBlock.size() - sizeof(quint16));

    socket_->write(arrBlock);
}