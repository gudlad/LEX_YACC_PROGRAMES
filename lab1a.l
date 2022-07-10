%{
#include<stdio.h>
int id=0,op=0,br=0,flag=0;
%}
%%
[0-9]+ 	{id++,printf("\nidentifier");ECHO;} //[a-zA-Z][a-zA-Z0-9]* {id++,printf("\nidentifier");ECHO;} 
[\+\*] 	{op++,printf("\noperator");ECHO;}
"("  	{if(br<0) 
		{printf("\ninvalid");
		exit(0);}
		else 
		br++;
	}
")" 	{br--;}
[.] 	{flag=1;}
\n 	{;}
%%
int main()
{
printf("enter the expression");
yylex();
printf("\nnum of identifiers: %d\n num of operators: %d\n",id,op);
if((op+1)==id&&(br==0)&&(flag==0))
printf("\nexpression is valid");
else
printf("\nexpression is invalid");
}

