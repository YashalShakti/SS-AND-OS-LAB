%{
	#include "y.tab.h"
%}
%%
[0-9]+ {return N;}
\n return 0;
. return yytext[0];

