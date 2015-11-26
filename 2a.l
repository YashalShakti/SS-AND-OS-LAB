%{
	#include<stdio.h>
	char id[10],op[10];
	int i=0,j=0,b=0;
%}
%%
"+"|"-"|"*"|"\\" {op[j++]=yytext[0];}
[0-9]+ {i++;printf("%s ",yytext);}
"(" {b++;}
")" {b--;}
. ;
\n return 0;
%%
main(){
	int k=0;
	printf("Enter the expression\n");
	yylex();
	if(b==0){
		printf("\nOper are \n");
		for(k=0;k<j;k++)
			printf("%c\t",op[k]);
		printf("\nThere are %d iden and %d op\n",i,j);
	}
	else
		printf("Not a valid expresssion\n");
	exit(0);
}
