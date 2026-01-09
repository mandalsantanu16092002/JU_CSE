%{
    #include<stdio.h>
%}

%%
1([.0-1]*)(101) { printf("Correct.\n"); }
.* { printf("Incorrect.\n"); }
%%


int main(){
    printf("Enter Expression :");
    yylex();
    return 0;
}