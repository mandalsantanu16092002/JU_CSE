%{
    #include <stdio.h>
    #include <math.h>
    int op = 0,i;
    int a, b;

    int digi()
    {
        if(op==0) a=(int)atoi(yytext); 
        else
        {
            b=(int)atoi(yytext);
            
            switch(op)
            {
                case 1:a=a+b;
                    break;
                
                case 2:a=a-b;
                break;
                
                case 3:a=a*b;
                break;
                
                case 4:a=a/b;
                break;
                
                case 5:for(i=a;b>1;b--) a=a*i;
                break;

                case 6: a=a%b;
                break;
            }
            op=0;
        }
    }
%}
  
dig [0-9]+
add "+"
sub "-"
mul "*"
div "/"
pow "^"
mod "%"
ln \n
%%
  
{dig} {digi();} 
{add} {op=1;}
{sub} {op=2;}
{mul} {op=3;}
{div} {op=4;}
{pow} {op=5;}
{mod} {op=6;}
{ln} {printf("\n The Answer :%d\n\n",a);}

%%
  
int main(int argv,char *argc[])
{
    printf("Enter expression :");
    yylex();

    return 0;
}
