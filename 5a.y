%{
	#include<stdio.h>
%}
%token N
%left '+' '-'
%left '*' '/'
%%
ex: e {printf("\nThe result is %d\n",$1);}
 e:e'/'e {$$=$1/$3;}
 |e'*'e {$$=$1*$3;}
 |e'+'e {$$=$1+$3;}
 |e'-'e {$$=$1-$3;}
 |'-'e {$$=-$2;}
 |'('e')' {$$=$2;}
 |N
%%
yyerror(){
	printf("Error\n");
	exit(0);
}
main(){
	printf("Enter the expression\n");
	yyparse();
	exit(0);
}
 
