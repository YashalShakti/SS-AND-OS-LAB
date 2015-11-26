%{
	#include<stdio.h>
	int w,c,l,s;
%}
%%
"\n" l++;
[ \t]+ s++;
[^ \t\n]+ {w++;c+=yyleng;}
%%
main(){
	yyin=fopen("in","r");
	yylex();
	printf("There are %d words , %d characters, %d spaces and %d lines in the file ",w,c,s,l);
	exit(0);
}
