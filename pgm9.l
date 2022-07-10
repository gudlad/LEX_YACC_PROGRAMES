%{
#include<stdio.h>
FILE *fp;
%}
%%
[0-9]+     {printf("Number of digits:%d",yyleng);} 
.		 ;
%%

int main(int argc,char* argv[]) // taking file name from command line
{
fp=fopen(argv[1],"r");
yyin=fp;
yylex();
return 0;
}
