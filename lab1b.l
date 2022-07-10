%{
#include "y.tab.h"
int yylval;
int br=0;
%}
%%
[0-9]+ 		{yylval=atoi(yytext);return num;}
[\+\-\*\/] 	{return yytext[0];}
[(] 		{br++; return yytext[0];}
[)] 		{br--; 
			if(br<0)
			{	
			printf("\n Invalid Arithmatic Expression"); 
			exit(0);
			}
			else
			{
			return yytext[0];
			}
     	 	}
. 		{printf("\n Invalid Arithmatic Expression");
		exit(0);
		}
\n             {return 0;}
%%
