/* Filename : msq_recv.c */

#include <iostream>

/* Filename: msgq_send.c */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>


#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

/*
 *
 */

# define PERMS 0644         /*Ownership and permissions */
struct my_msgbuf {
    long mtype;
    char mtext[1024];

    my_msgbuf() : mtype(0) 
    {
        memset(mtext,'\0',sizeof(mtext)+1);
    }
};
using namespace std;

int main(int argc , char* argv[])
{
    struct my_msgbuf buf;
    int msqid;
    int toend;
    key_t key;

    system("touch msgq.txt");


    if((key = ftok("msgq.txt" , 'B')) == -1)
    {
        std::cout << " ftok - error " << std::endl;
        exit(1);
    }


    if((msqid = msgget(key,PERMS)) == -1) // connect to the queue
    {
        std::cout << "msgget - eooro "<< std::endl;
        exit(1);
    }

    printf("message queue: ready to receive message. \n");


    for(;;)
    {
        /* normally receiving never ends but just to make conclusion this program ends with string of end */

        if(msgrcv(msqid,&buf,sizeof(buf.mtext),0,0) == -1)
        {
            std::cout << "msgrcv" <<std::endl;
            exit(1);
        }
        printf("recvd: \"%s\"\n",buf.mtext);
        toend = strcmp(buf.mtext,"end");
        if(toend == 0)
        {
            break;
        }

    }


    printf("message queue : done receiving message. \n ");
    system("rm msgq.txt");

    return 0;
}
