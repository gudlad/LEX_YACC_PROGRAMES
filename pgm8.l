%{
#include<stdio.h>
int count=0;
FILE *file;
%}
%%
[a-zA-Z0-9]+     {count++;} 
.		 ;
%%

int main()
{
printf("input is taken from hello.txt");
file=fopen("hello.txt","r");
yyin=file;
yylex();
printf("The count is %d\n",count);
}
