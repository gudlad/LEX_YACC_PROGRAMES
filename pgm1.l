%option noyywrap
%{    
 #include<stdio.h>
%}
%%     
"+" {printf("PLUS");}
[0-9]* {printf("Number");}
%%
void main()
{
printf("Enter the idenfiers:");
yylex();
}
 
