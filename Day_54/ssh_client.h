#ifndef SHH_CLIENT_H
#define SHH_CLIENT_H

#include <iostream>
#include <sys/statvfs.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

#include <libssh/libssh.h>
#include <libssh/libsshpp.hpp>
#include <libssh/sftp.h>

int run_remote_cmd(ssh_session session)
{
    ssh_channel   channel;
    int           rc;
    char          buffer[256];
    int           nbytes;

    // step 1 start new channel
    channel = ssh_channel_new(session);
    // step 2 channel open new sub-session
    rc = ssh_channel_open_session(channel);
    // step 3 send remote command request
    rc = ssh_channel_request_exec(channel, "ls -l *.txt");

    // step 4 read remote response back
    nbytes = ssh_channel_read(channel,buffer,sizeof(buffer),0);

    while(nbytes > 0)
    {
        std::cout << buffer << std::endl;
        nbytes = ssh_channel_read(channel, buffer, sizeof(buffer) ,0);
    }

    // step 5 send channel EOD to remote
    ssh_channel_send_eof(channel);

    //step 6 close channel
    ssh_channel_close(channel);

    //step 7 free channel
    ssh_channel_free(channel);

    rc = SSH_OK;

    return rc;

}

/*
 * https://api.libssh.org/master/group_libssh_sftp.html
 * https://api.libssh.org/stable/libssh_tutor_guided_tour.html
 * https://api.libssh.org/stable/libssh_tutorial.html
 *
 * sudo apt-get install libssh-dev
 * int verbosity = SSH_LOG_PROTOCOL;
 * rc = verify_knownhost(mSession);
 */



#endif // SHH_CLIENT_H
