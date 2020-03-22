#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "gpp_interpreter.h"

int main(void)
{
  yyparse();
  return 0;
}

void yyerror(char *s)
{
  fprintf(stderr, "%s\n", s);
}

int resolveFunc(char *func)
{
  char *funcs[] = {   "+", "-", "*", "/","and","or","not","equal","concat","list","append",""};

  int i = 0;
  while (funcs[i][0] !='\0')
  {
    if (!strcmp(funcs[i], func))
      return i;
    i++;
  }
  yyerror("invalid function"); 
  return -1;
}

double calc(char *func, double op1, double op2)
{
	printf(">>>>>>>>>>>>>>> %s\n",func );
  double result = 0.0;
  int function = resolveFunc(func);


   if (function == ADD){
  	result = op1 + op2;
  	printf("%lf",result );
  }    
  else if (function == SUB)
      result = op1 - op2;
  else if (function == MULT)
      result = op1 * op2;
  else if (function == DIV)
      result = op1 / op2;
  
  else if (function == AND){
  	
  		if (op1 == 0.0 && op2 == 0.0)
  		{
  			result = op2;
  			printf("NIL");
  		}
  		if (op1 != 0.0 && op2 != 0.0)
  		{
  			result = op2;
  			printf("%lf",op2 );
  		}
  		if (op1 == 0.0)
  		{
  			result = op2;
  			printf("NIL");
  		}
  		if (op2 == 0.0)
  		{
  			result = op1;
  			printf("NIL");
  		}
  		result = 1;
  }
  else if (function == OR){
      	if (op1 == 0.0 && op2 == 0.0)
  		{
  			result = op2;
  			printf("NIL");
  		}
  		else if (op1 != 0.0 && op2 != 0.0)
  		{
  			result = op1;
  			printf("%lf",op1 );
  		}
  		else if (op1 != 0.0)
  		{
  			result = op1;
  			printf("%lf",op1 );
  		}
  		else if (op2 != 0.0)
  		{
  			result = op2;
  			printf("%lf",op2 );
  		}else{

  		}
  }
  else if (function == NOT){
      if (op1 != 0.0)
  		{
  			
  			printf("NIL");
  		}
  }
  else if (function == EQUAL){
      if (op2 == op1)
  		{	
  			printf("T");
  		}
  }
  else if (function == CONCAT){
     
      printf("\"%lf%lf\"\n",op1,op2 );
     
  }
  else if (function == LIST){
     
      printf("(%lf %lf)\n",op1,op2 );
  }
  else if (function == APPEND){

      printf("\"%lf%lf\"\n",op1,op2 );
  }
    

  return result;
}
