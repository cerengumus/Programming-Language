%option noyywrap

%{
    #include "gpp_interpreter.h"
%}

digit [0-9]
number {digit}+(\.{digit}+)?
func "+"|"-"|"*"|"/"|"and"|"or"|"not"|"equal"|"list"|"concat"|"append"
%%

{number} {
                yylval.dval = strtod(yytext, NULL);
                printf("lex: NUMBER dval = %lf\n", yylval.dval);
                return NUMBER;
            }           
"quit"      { return QUIT; }

{func}      {
                yylval.sval = (char *) malloc(strlen(yytext)*sizeof(char));
                strcpy(yylval.sval, yytext);
                printf("lex: FUNC sval = %s\n", yylval.sval);
                return FUNC;
            }           
"("         {
                printf("lex: OP_OP\n");
                return OP_OP;
            }
")"         {
                printf("lex: OP_CP\n");
                return OP_CP;
            }
"\n"        {
                //printf("lex: RPAREN\n");
                return EOL;
            }
[ \t]       ; /* skip whitespace */

.           // yyerror("lex: invalid character");

%%
