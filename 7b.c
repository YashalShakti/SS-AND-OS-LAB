/*C program that creates a child process to read commands from the standard input and execute them
(a minimal implementation of a shell – like program). You can assume that no arguments will be
passed to the commands to be executed.*/

#include<stdio.h>
#include<sys/types.h>

void main(){
	char a[100];
	while(1){
		printf("\nroot:-$");
		gets(a);
		if(a[0]=='0')
			break;
		system(a);
		}
	}
/*
yashal@yashal-shakti:~/SS-AND-OS-LAB$ ./a.out 

root:-$echo Demo
Demo

root:-$cat demo
sir mvit        dept of cse     
root:-$0
yashal@yashal-shakti:~/SS-AND-OS-LAB$ 
*/
