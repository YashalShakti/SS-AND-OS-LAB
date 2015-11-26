%{
	#include<stdio.h>
	int i=0;
%}
%token A B
%%
S:a B
a:A a {i++;}
| ;
%%
yyerror(){
	printf("Error : Grammar not matched\n");
	exit(0);
}
void main(){
	printf("Enter the pattern\n");
	yyparse();
	if(i>=10)
		printf("Valid\n");
	else
		printf("Invalid\n");
	exit(0);
}

