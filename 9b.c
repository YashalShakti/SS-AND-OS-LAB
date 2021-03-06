/*C program to do the following: Using fork( ) create a child process. The child process prints its own
process-id and id of its parent and then exits. The parent process waits for its child to finish (by executing
the wait( )) and prints its own process-id and the id of its child process and then exits.*/

#include<stdio.h>
#include<sys/types.h>

void main(){
	pid_t pid;
	pid= fork();
	if(pid==0){
		printf("\nThis is child process and its ID is %d\n",getpid());
		printf("\nParent ID is %d\n",getppid());
		exit(0);
		}
	else{
		wait(NULL);
		printf("\nThis is parent process with ID %d\n",getpid());
		printf("\nChild ID is %d\n",pid);
		exit(0);
	}
} 


/*This is child process and its ID is 6097

Parent ID is 6096

This is parent process with ID 6096

Child ID is 6097
*/
