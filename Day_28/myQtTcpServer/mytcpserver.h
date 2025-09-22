#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H


#include<QObject>
#include<QTcpServer>
#include<QTcpSocket>
#include<QThreadPool>
#include<iostream>

class MyTcpServer : public QTcpServer
{
    // Q_OBJECT

public:
    explicit MyTcpServer(QObject *parent = nullptr);
    void startServer();

signals:
protected:
    void incomingConnection(qintptr handle) override;

private:
    QThreadPool *pool;

};

#endif // MYTCPSERVER_H
