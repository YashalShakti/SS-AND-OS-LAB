%{
	#include<stdio.h>
	int count=0,flag=0;
%}
%%
"int"|"double" flag=1;
[a-z_]+[a-z0-9_]* {if(flag)count++;}
";" flag=0;
%%
main(){
	yyin=fopen("12.c","r");
	yylex();
	printf("There are %d identifiers\n",count); //18 in 12.c
	exit(0);
}
