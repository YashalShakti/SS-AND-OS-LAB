%{
	#include<stdio.h>
%}
%token N
%left '+' '-'
%left '*' '/'
%%
ex: e 
 e:e'/'e 
 |e'*'e 
 |e'+'e 
 |e'-'e 
 |'-'e 
 |'('e')' 
 |N
%%
yyerror(){
	printf("Error\n");
	exit(0);
}
main(){
	printf("Enter the expression\n");
	yyparse();
	printf("Valid\n");
	exit(0);
}
 
