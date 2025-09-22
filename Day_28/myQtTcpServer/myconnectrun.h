#ifndef MYCONNECTRUN_H
#define MYCONNECTRUN_H

#include"mytcpserver.h"
#include<QRunnable>

class myConnectRun : public QRunnable
{
public:
    qintptr socketdescriptor;
protected:
    void run() override;
};

#endif // MYCONNECTRUN_H
