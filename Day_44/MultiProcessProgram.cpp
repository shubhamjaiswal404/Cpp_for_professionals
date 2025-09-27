#include<iostream>
#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>

/* system call
 * A system call is a machanism that provides the interface between a process  and the operating system 
 * it is a pragrammatic method in which a computer program request a service from the kernel of the OS
 * System call offers the services of the operarting system to the user programs  
 * System calls are the entry points for the kernel system 
 *
 * there five type of system calls :
 *
 * 1) Process Control
 * 2) File Management
 * 3) Device Management 
 * 4) Information Maintenance
 * 5) Communications
 *
 * ******************
 * Important System Calls Used in OS 
 *
 *
 * wait() 
 * In some system , aprocess needs to wait for another process to complete its execution this type of situation 
 * occurs when a parent process creates a child process , and the execution of the parent process remains 
 * suspended until its child process executes
 *
 * The suspension af the parent process automatically occur with a wait()system call 
 * When the child process ends execution , the controlmoves back to the parent process
 *
 * fork()
 * Processes use this system call to create processes that are a copy of themselves 
 * With the help of this system Call parent process creates a child process, and the execution
 * of the parent process will be suspended till the child process executes 
 *
 * exec()
 * This system call runs when an executable file in the context of an already running process
 * that replaces the older executable file . However , the original process identifier remains as 
 * a new process is not built , but stack , data , head , data etc are replaced by the new process.
 *
 * kill():
 * The kill() system call is used by OS to send a termination signal to a process that urges the process to exit.
 * However , a kill system call does nor necessarily mean killing the process and can have various meanings 
 * 
 *exit():
 *The exit() system call is used to terminate program execution . Specially in the multi-threaded environment,
 * this call defines that the thread execution is complete . the OS reclaims resources that were used by the process after the use of exit() system call 
 *
 * pid_t pid , cpid;
 * printf( " --beginning of program\n" );
 *
 *
 *
 */


int main()
{

/*
	if(fork()== 0)  // fork() system call 
        {
                // execute child process 
                printf("Executing Child Process id : %d  \n", getpid());
        }
        else
        {
                // execute parent process
         	printf("Executing Parent Process id : %d  \n", getpid());
        }
*/



	if(fork()== 0)	// fork() system call 
	{
		// execute child process 
		printf("Executing Child Process id : %d  \n", getpid());
		exit(0);
	}
	else
	{
		pid_t cpid = wait(NULL);
		// execute parent process 
		printf("Executing Parent Process id : %d child process id : %d  \n", getpid(),cpid);
	}
	
	return 0;
}






