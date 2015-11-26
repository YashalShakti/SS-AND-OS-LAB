%{
	#include<stdio.h>
	int c,flag=0;
%}
%%
"/*" flag=1;
"*/" {flag=0;c++;}
.|\n {if(!flag)fprintf(yyout,"%s",yytext);}
%%
main(){
	yyin=fopen("in","r");
	yyout=fopen("out","w");
	yylex();
	printf("There are %d comments \n",c);
	exit(0);
}
