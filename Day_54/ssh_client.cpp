#include <iostream>
#include "ssh_client.h"

#include <unistd.h>
#include <libssh/libssh.h>


using namespace std;

int main(int argc , char* argv[])
{
    if(argc != 4)
    {
        std::cout << " Usage : ssh_client  <server> <port> <login_id> " << std::endl;
        exit(-1);
    }

    int mPort = std::stoi(argv[2]);
    int verbosity = SSH_LOG_NOLOG;
    int rc = 0;

    // step 1 start a new SSH session
    ssh_session mSession = ssh_new();
    if(mSession == NULL)
    {
        exit(-1);
    }

    //step 2 setup session options
    ssh_options_set(mSession, SSH_OPTIONS_HOST, argv[1]);
    ssh_options_set(mSession, SSH_OPTIONS_LOG_VERBOSITY, &verbosity);
    ssh_options_set(mSession, SSH_OPTIONS_PORT, &mPort);

    // step 3 session connect to remote
    rc = ssh_connect(mSession);
    if(rc != SSH_OK)
    {
        std::cout << "Error connecting to localhost : " << ssh_get_error(mSession) << std::endl;
        exit(-1);
    }

    // step 4 authenticate login/password
    char *pPass = getpass("Password : ");
    rc = ssh_userauth_password(mSession, argv[3] , pPass);
    if(rc != SSH_AUTH_SUCCESS)
    {
        std::cout << " Error authenticating with password : " << ssh_get_error(mSession) << std::endl;
        ssh_disconnect(mSession);
        ssh_free(mSession);
        exit(-1);
    }

    // step 5 exec command on remote
    rc = run_remote_cmd(mSession);

    // step 6 disconnect and free session
    ssh_disconnect(mSession);
    ssh_free(mSession);
    return rc ;

}
