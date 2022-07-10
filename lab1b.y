%{
#include<stdio.h>
#include<stdlib.h>
int yylex();
int yyerror();
%}
%token num
%left '+' '-' '*' '/'
%%
input:exp 	{printf("%d\n",$$);exit(0);}
exp:exp'+'exp 	{$$=$1+$3;}
|exp'-'exp 	{$$=$1-$3;}
|exp'*'exp 	{$$=$1*$3;}
|exp'/'exp 	{if($3==0)
			{
			printf("divide by zero");
			exit(0);
			}
		else
			$$=$1/$3;
		}
|'('exp')' 	{$$=$2;}
|num 		{$$=$1;}
;
%%
int main()
{
printf("enter the expresssion");
yyparse();
}
int yyerror()
{
printf("error");
exit(0);
}
