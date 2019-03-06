%{
#include <stdio.h>
#include <stdlib.h>
#include "y.tab.h"  // generated via yacc -d
%}

%option noyywrap

%%

[0-9]+(\.[0-9]+)?([eE][0-9]+)?      {yylval.f = atof(yytext); return NUM;}

[(]                                 {return OPEN_PAREN;} 
[,-]                                 {return yytext[0];}
[)]                                 {return CLOSE_PAREN;}

"add"                               {return ADD;}
"sub"                               {return SUB;}
"mul"                               {return MUL;}
"div"                               {return DIV;}

"quit"                              {return QUIT;}

[\n]                                {return '\n';}
[ \t\f\v]                           { ; }

%%