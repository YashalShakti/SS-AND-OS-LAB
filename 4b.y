%{
	#include<stdio.h>
%}
%token N L
%%
s:L n | L
n:L N
|N L
|N
|L
%%
yyerror(){
	printf("Error\n");
	exit(0);
}
main(){
	printf("Enter the variable\n");
	yyparse();
	printf("Valid\n");
	exit(0);
}
 
