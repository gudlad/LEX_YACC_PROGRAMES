%{
#include<stdio.h>
int br=0,op=0,id=0,flag=0;
%}

%%
[0-9]+                         {id++;printf("\nindentifier :");ECHO;}
[\+\*]+                        {op++;printf("\noperator :");ECHO;}
"("                            {
                               if(br<0)
                               {
                               printf("\nINVALID");
                               }
                               else
                               {
                               br++;
                               }
                               }
")"                            {br--;}
                             
";"                            {flag=1;}
.|\n                           {;}
%%

int main()
{
        printf("Enter the expression:");
        yylex();
        if((op+1)==id && br==0 && flag==0)
        {
                printf("\nExpression is Valid\n");
                printf("No of identifier = %d \nNo of Operators = %d \n",id,op);
        }
        else
                printf("\n Expression is InValid\n");
return 0;

}
