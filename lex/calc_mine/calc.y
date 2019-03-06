%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
extern int yylex();
extern int yy_scan_buffer();
void yyerror(char *msg);
%}

%union {
  float f;
}

%token QUIT

%token <f> NUM
%token <f> ADD SUB MUL DIV
%token <f> OPEN_PAREN CLOSE_PAREN

%type <f> E T F

%%

S : E '\n'            {printf("%f\n", $1);return 0;}
  | QUIT '\n'         {return -1;}
  ;

E : ADD OPEN_PAREN E ',' E CLOSE_PAREN     {$$ = $3 + $5;}
  | SUB OPEN_PAREN E ',' E CLOSE_PAREN     {$$ = $3 - $5;}
  | T           {$$ = $1;}
  ;

T : MUL OPEN_PAREN E ',' E CLOSE_PAREN     {$$ = $3 * $5;}
  | DIV OPEN_PAREN E ',' E CLOSE_PAREN     {$$ = $3 / $5;}
  | F           {$$ = $1;}
  ;

F : '-' F       {$$ = -$2;}
  | NUM         {$$ = $1;}
  ;

%%
void yyerror(char *msg) {
    fprintf(stderr, "%s\n", msg);
    exit(1);
}


void read_input(char* str)
{
  char x;
  int i=0;
  while(x = getchar())
  {   
    str[i]=x;
      if(x == '\n'||x == '\0')break;
      i++;
  }
  if(str[i-1]=='\n')str[i]='\0';
}

int main() {
    char expr[1000];
    int i;
    while(1)
    {
      printf(">>> ");  
      read_input(expr);
      yy_scan_buffer(expr,sizeof(expr));  
      if(yyparse()==-1)
      {
        break;
      }
    }
    printf("bye!!\n");
    return 0;
}