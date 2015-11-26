%{
	#include<stdio.h>
%}
%%
"and"|"or" {printf("Compound\n");exit(0);}
\n return 0;
. ;
%%
main(){
	printf("Enter the sentence\n");
	yylex();
	printf("Simple\n");
	exit(0);
}

