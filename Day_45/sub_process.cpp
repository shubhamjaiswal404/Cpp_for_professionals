#include<iostream>
#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>

int main(int argc , char* argv[])
{
	printf("	beginning of sub_process, pid is : %d \n " , getpid() );
	if(argc >= 2)
	{
		printf("	This is arg0 : %s \n", argv[0]);
		printf("	This is arg1 : %s \n", argv[1]);
	}
	printf("	ending of sub_process , pid is : %d \n", getpid() );

	return 0;
}


