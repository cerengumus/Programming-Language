

%{
#include "gpp_interpreter.h"
%}

%union
{
   double dval;
   char *sval;
}

%token <sval> FUNC 
%token <dval> NUMBER
%token OP_OP OP_CP EOL QUIT

%type <dval> expi

%%

program:/* empty */ {
                       printf("> ");
                    }
        | program expi EOL {
                             
                             printf("\n>");
                           }
        ;

expi:
        NUMBER {
                  printf("yacc: NUMBER\n");
                  $$ = $1;
               }
        | OP_OP FUNC expi OP_CP {
                                    
                                     $$ = calc($2, $3, 0);
                                    
                                  }
        | OP_OP FUNC expi expi OP_CP {
                                      
                                          $$ = calc($2, $3, $4);
                                         
                                       }
        | QUIT { exit(0);}

        | error {
                    printf("syntax error\n");
                    printf("> ");
                }

        ;
%%
