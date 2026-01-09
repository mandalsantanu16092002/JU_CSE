
%{
#include<stdio.h>
%}

alphanumeric [a-z0-9]
digit [0-9]
alpha [a-zA-Z]
delim @
capalpha [A-Z]

%%
{capalpha}{alphanumeric}*{delim}+    {printf("Correct Expression.\n");}
  
.* {printf("Incorrect Expression");}
%%
  
int yywrap(void){}
  
int main()
{   
    printf("Input Expression : ");
    yylex();
  
    return 0;
}