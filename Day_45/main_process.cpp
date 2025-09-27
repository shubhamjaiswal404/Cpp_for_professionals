#include<iostream>
#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>

/*
 * https://linuxhint.com/linux-exec-system-call/
 * execl("./sub_process","arg0" ,"arg1" , NULL);
*/

int main ( int argc , char* argv[])
{
	printf("--beginning of main_process , pid is : %d \n", getpid());

	if(fork() == 0)
	{
		::execl("./sub_process","arg0" ,"arg1" , NULL);
		exit(0);
	}
	else
	{
		pid_t cpid = wait(NULL);
		 printf(" child process %d ended and execute parent process  pid : %d \n",cpid, getpid());
	}

	printf("--ending of main_process,     pid is : %d \n", getpid());


/*
	printf("--beginning of main_process , pid is : %d \n", getpid());
	::execl("./sub_process","arg0" ,"arg1" , NULL);
	following line will not execute any more
	printf("--ending of main_process,     pid is : %d \n", getpid());
*/

	return 0;
}

