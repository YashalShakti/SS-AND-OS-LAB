%token A B
%%
S : A S B |A B
%%
yyerror(){
	printf("Error\n");
	exit(0);
}
main(){
	printf("Enter the expr\n");
	yyparse();
	printf("Valid\n");
}
