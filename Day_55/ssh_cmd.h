#ifndef SSH_CMD_H
#define SSH_CMD_H

#include<iostream>
#include<sys/statvfs.h>
#include<stdio.h>
#include<unistd.h>
#include<errno.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>


#include<libssh/libssh.h>
#include<libssh/libsshpp.hpp>
#include<libssh/sftp.h>

int run_remote_cmd(ssh_session session, char *inCmd)
{
    ssh_channel channel;
    int rc;
    char rdBuffer[256];
    int nbytes;

    // step 1 start new channel
    channel = ssh_channel_new(session);

    // step 2 channel open new sub-session
    rc = ssh_channel_open_session(channel);
    
    // step 3 send remote command request
    rc = ssh_channel_request_exec(channel,inCmd);

    // step 4 read remote response back
    
    //memset(rdBuffer,'\0',sizeof(rdBuffer)+1);

    memset(rdBuffer,'\0',sizeof(rdBuffer));
    nbytes = ssh_channel_read(channel, rdBuffer,sizeof(rdBuffer),0);
    while(nbytes > 0)
    {
        printf("%s",rdBuffer);
        //memset(rdBuffer,'\0',sizeof(rdBuffer)+ 1);
        memset(rdBuffer,'\0',sizeof(rdBuffer));
        nbytes = ssh_channel_read(channel,rdBuffer,sizeof(rdBuffer),0);
    }

    // step 5 send channel EOF to remote
    ssh_channel_send_eof(channel);
    // step 6 close channel
    ssh_channel_close(channel);
    // step 7 free channel
    ssh_channel_free(channel);

    rc = SSH_OK;
    return rc;

}

/*
int verify_knownhost(ssh_session session)
{
    enum ssh_known_hosts_e state;
    unsigned char *hash = NULL;
    ssh_key srv_pubkey = NULL;
    size_t hlen;
    char buf[10];
    char *hexa;
    char *p;
    int cmp;
    int rc;

    rc = ssh_get_server_publickey(session,&srv_pubkey);
    if(rc < 0 )
    {
        return -1;
    }
}

*/






#endif // SSH_CMD_H
