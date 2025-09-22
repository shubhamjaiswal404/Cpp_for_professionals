#include "myconnectrun.h"

void myConnectRun::run()
{
    QByteArray inBuff;
    if(!socketdescriptor) return;
    QTcpSocket mySocket;
    mySocket.setSocketDescriptor(socketdescriptor);
    if(mySocket.isOpen())
    {
        mySocket.write("Hello Client I am server");
        mySocket.waitForBytesWritten();
        mySocket.flush();
        while(mySocket.waitForReadyRead())
        {
            inBuff = mySocket.readAll();
            qInfo() << socketdescriptor << "  : " << inBuff;
            if(!strncmp(inBuff , "quit" , 4))
            {
                break;
            }
            mySocket.write("Server Reply: ");
            mySocket.write(inBuff);
            mySocket.waitForBytesWritten();
            mySocket.flush();
        }
        mySocket.close();
    }
}

