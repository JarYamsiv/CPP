#include <stdio.h>
#include "myscanner.h"

extern int yylex();
extern int yylineno();
extern char* yytext;

char* names[] = {NULL,"db_type","db_name","db_name","db_table_prefix","db_port"};

int main(void)
{
	int ntoken , vtoken;
	ntoken = yylex();

	while(ntoken)
	{
		printf("%d\n" , ntoken);
		if(yylex()!=COLON)
		{
		printf("syntax error at line %d, Expected a ':' but found %s\n",yylineno(),yytext);
		return 1;
		}
		vtoken = yylex();
		switch (ntoken)
		{
		case TYPE:
		case NAME:
		case TABLE_PREFIX:
			if (vtoken != IDENTIFIER)
			{
				printf("syntax error at line %d , expected an identifier but found %s\n",yylineno(),yytext);
				return 1;
			}
			printf("%s is set to %s\n", names[ntoken], yytext);
			break;
		case PORT:
			if(vtoken != INTEGER )
			{
				printf("syntax error at line %d , expected integer but found %s\n",yylineno(),yytext);
				return 1;
			}
			break;
		default:
			printf("syntax error at line %d\n",yylineno());
			return 1;
			break;
		}

		ntoken = yylex();
	}

	return 0;
}
