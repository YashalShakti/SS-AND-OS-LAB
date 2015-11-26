/*C program to create a file with 16 bytes of arbitrary data from the beginning and another 16 bytes of
arbitrary data from an offset of 48. Display the file contents to demonstrate how the hole in file is
handled.*/

#include<stdio.h>
#include<sys/types.h>

void main(){
	char b[] = "sir mvit        ";
	char b2[]= "dept of cse     ";
	
	FILE *fp;
	fp=fopen("demo","w");
	fprintf(fp,b);
	fseek(fp,48,0);
	fprintf(fp,b2);
	fclose(fp);
}

/*
od -c demo 
0000000   s   i   r       m   v   i   t                                
0000020  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0
*
0000060   d   e   p   t       o   f       c   s   e                    
0000100
*/
