%%
"+" {printf("PLUS");}
[0-9]* {printf("Number");}
%%

void main(int argc,char** argv)
{
printf("Enter the idenfiers:");
yylex();
}
/*
int yywrap(void)
{
return 1;
}
*/                                                                           
