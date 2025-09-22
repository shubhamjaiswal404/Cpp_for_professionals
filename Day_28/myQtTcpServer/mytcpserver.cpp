#include "mytcpserver.h"
#include"myconnectrun.h"

MyTcpServer::MyTcpServer(QObject *parent) : QTcpServer(parent)
{
    pool = new QThreadPool(this);
    pool->setMaxThreadCount(5);
}

void MyTcpServer::startServer()
{
    if(this->listen(QHostAddress::LocalHost, 1234))
    {
        qInfo("Server Start Successfully on localhost port 1234");
    }
    else{
        qInfo("Server Start not Successfully on localhost port 1234");
    }
}

void MyTcpServer::incomingConnection(qintptr handle)
{
    qInfo() << "Incoming Connection  Received " << handle;
    myConnectRun *task = new myConnectRun();
    task->socketdescriptor = handle;
    task->setAutoDelete(true);
    pool->start(task);

}

