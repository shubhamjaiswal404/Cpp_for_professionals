#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <signal.h>

/* Filename: msgq_send.c */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
//#include <string.h>

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
    int len;
    key_t key;

    system("touch msgq.txt");

    // step1 :ftok - convert a pathname and a project identifier to a System V IPC key
    if((key = ftok("msgq.txt" , 'B')) == -1)
    {
        std::cout << " ftok - error " << std::endl;
        exit(1);
    }

    //step2 : connect or cret queue if not exit
    if((msqid = msgget(key,PERMS | IPC_CREAT)) == -1)
    {
        std::cout << "msgget - eooro "<< std::endl;
        exit(1);
    }

    printf("message queue: ready to send message. \n");
    printf("Enter lines of text, ^D to quit:\n");
    buf.mtype = 1; /* we don't really care in this case */

    for(;;)
    {
        std::cin.getline(buf.mtext, sizeof(buf.mtext));
        len = strlen(buf.mtext);
        /* remove newline at end if it exits */
        if(buf.mtext[len -1] == '\n')
        {
            buf.mtext[len -1] = '\0';
        }
        if(msgsnd(msqid,&buf,len+1,0) == -1)
        {
            std::cout << "msgsnd -error" <<std::endl;
        }
    }

    strcpy(buf.mtext,"end");
    len = strlen(buf.mtext);
    if(msgsnd(msqid,&buf,len+1,0) == -1)
    {
        std::cout << "msgsnd = error "<< std::endl;
    }
    if(msgctl(msqid,IPC_RMID, NULL) == -1)
    {
        std::cout << "msgctl - error" << std::endl;
        exit(1);
    }
    printf("message queue : done sending message. \n ");

    return 0;
}






















