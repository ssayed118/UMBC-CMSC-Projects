%{
/*the include file of our application
 is already included in y.tab.h in which
other required C include files are included.*/
#include "y.tab.h"
extern YYSTYPE yylval;
%}
%%
[0-9]+                  yylval.number=atoi(yytext); return NUMBER;
set			            return SET;
quit		            return QUIT;
add			            return ADD;
status		            return STATUS;
turn|TURN	            return TURN;
on|off		            yylval.string=strdup(yytext);return ONOFF;
[a-zA-Z0-9]+            yylval.string=strdup(yytext);return BUILDING;
\n                      /* ignore end of line */;
[ \t]+                  /* ignore whitespace */;
%%
