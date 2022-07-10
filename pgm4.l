/*** Definition section ***/

%{
/* C code to be copied verbatim */
#include <stdio.h>
int count=0;
%}

%%
    /*** Rules section ***/

    /* [0-9]+ matches a string of one or more digits */
[0-9]+  {
            /* yytext is a string containing the matched text. */
            printf("Saw an integer: %s\n", yytext);
            count++;
        }

.|\n    {   /* Ignore all other characters. */   }

%%
/*** C Code section ***/

int main(void)
{
    /* Call the lexer, then quit. */
    yylex();
    printf("the no of integers: %d",count);
    return 0;
}
