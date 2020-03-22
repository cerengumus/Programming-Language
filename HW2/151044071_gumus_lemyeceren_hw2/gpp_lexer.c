#include <stdio.h>
#include <string.h>
#include "gpp_lexer.h"

#define MAXCHAR 1024

void parseString(char arr[MAXCHAR]);
void subString(char subStr[],char *ptr);
void subString_(char subStr[],char *ptr);
int checkIntValue(char arr[]);
int identifierCheck(char arr[]);
int checkKeywords(char ptr[]);
int checkOperators(char ptr[]);
int main(int argc, char const *argv[])
{
	FILE *f = fopen("gpp_lexer.lisp", "r");
	char str[1024];
  
	while (fgets(str, MAXCHAR, f) != NULL){
        //printf("%s", str);	
        
        parseString(str);
	}
	return 0;
}
void parseString(char arr[1024])
{
	char subStr[1024];
	char delim[] = " ";
	char *ptr = strtok(arr, delim);
	while(ptr != NULL)
	{
		if (ptr[strlen(ptr)-1] == '\n')
		{
			ptr[strlen(ptr)-1] = '\0';
		}
		//printf("--->>> %s\n",ptr );
		//printf("---------------------------\n");
		if(ptr[0] == ';'){
			//printf("%s <<<<>>>> ",ptr );
			printf("COMMENT\n");	
			break;
		}
		else if(checkKeywords(ptr)){
			
		}
		
		else if(checkOperators(ptr)){		
		}
		else if (checkIntValue(ptr))
		{
			//printf("%s <<<<>>>> ",ptr );
			printf("VALUE\n");
		}
		else if (identifierCheck(ptr))
		{
			//printf("%s <<<<>>>> ",ptr );
			printf("IDENTIFIER\n");
		}
		else{
			//printf("***** %c\n",ptr[strlen(ptr)-1] );
			if (ptr[0] == '(')
			{
				//printf("%c <<<<>>>> ",ptr[0] );
				printf("OP_OP\n");
				subString(subStr,ptr);
			}
			else if (ptr[strlen(ptr)-1] == ')')
			{
				//printf("//////////// %c <<<<>>>> ",ptr[strlen(ptr)-1] );
				subString_(subStr,ptr);
				printf("OP_CP\n");
				
			}	
			

			//printf(">>>>>>>>><<  %s\n",subStr );
		}
		ptr = strtok(NULL, delim);
	}
}
int checkIntValue(char arr[]){
	int i = 0;
	for (int i = 0; i < strlen(arr); ++i)
	{

		if( 48 <= (int)arr[i] &&  57>= (int)arr[i])
		{
			continue;
		}
		else{
			return 0;
		}
	}
	return 1;

}
void subString(char subStr[],char *ptr){

	int i = 0;
	int size = strlen(ptr);
   while (i < size -1) {
      subStr[i] = ptr[i+1];
      i++;    
   }
   subStr[i] = '\0';
 
   	if(checkKeywords(subStr)){		
	}
	else if(checkOperators(subStr)){		
	}
	else if (checkIntValue(subStr))
	{
		
		printf("VALUE\n");/* code */
	}
	else if (identifierCheck(subStr))
	{
		//printf("%s <<<<>>>> ",subStr );
		printf("IDENTIFIER\n");
	}
	else{

			if (subStr[0] == '(')
			{
				//printf("%c <<<<>>>> ",subStr[0] );
				printf("OP_OP\n");
				subString(ptr,subStr);				
				
			}
			
			else if (subStr[strlen(subStr)-1] == ')')
			{

				//printf("%c <<<<>>>> ",subStr[strlen(subStr)-1]);
				subString_(ptr,subStr);
				printf("OP_CP\n");
				
			}
			
			
		}
}

void subString_(char subStr[],char *ptr){
	int i = 0;
	int size = strlen(ptr);
   while (i < size -1) {
      subStr[i] = ptr[i];
      i++;    
   }
   subStr[i] = '\0';
  
   	if(checkKeywords(subStr)){		
	}
   	else if (checkIntValue(subStr))
	{
		
		printf("VALUE\n");/* code */
	}
	else if (identifierCheck(subStr))
	{
		//printf("%s <<<<>>>> ",subStr );
		printf("IDENTIFIER\n");
	}
	else{

			
			if (subStr[0] == '(')
			{
				//printf("%c <<<<>>>> ",subStr[0] );
				printf("OP_OP\n");
				subString(ptr,subStr);				
				
			}
			
			else if (subStr[strlen(subStr)-1] == ')')
			{

				//printf("%c <<<<>>>> ",subStr[strlen(subStr)-1]);
				subString_(ptr,subStr);
				printf("OP_CP\n");
				
			}
			
		}

}
int checkKeywords(char ptr[]){
	
	if (strcmp(ptr,KW_IF) == 0)
	{
		printf("KW_IF\n");
	}
	else if (strcmp(ptr,KW_DEFFUN) == 0)
	{
		printf("KW_DEFFUN\n");
	}
	else if (strcmp(ptr,KW_AND) == 0)
	{
		printf("KW_AND\n");
	}
	else if (strcmp(ptr,KW_OR) == 0)
	{
		printf("KW_OR\n");
	}
	else if (strcmp(ptr,KW_EQUAL) == 0)
	{
		printf("KW_EQUAL\n");
	}
	else if (strcmp(ptr,KW_NOT) == 0)
	{
		printf("KW_NOT\n");
	}
	else if (strcmp(ptr,">") == 0)
	{
		printf("KW_LESS\n");
	}
	else if (strcmp(ptr,"<") == 0)
	{
		printf("KW_LESS\n");
	}
	else if (strcmp(ptr,">=") == 0)
	{
		printf("KW_LESS\n");
	}
	else if (strcmp(ptr,"<=") == 0)
	{
		printf("KW_LESS\n");
	}
	else if (strcmp(ptr,KW_NIL) == 0)
	{
		printf("KW_NIL\n");
	}
	else if (strcmp(ptr,KW_LIST) == 0)
	{
		printf("KW_LIST\n");
	}
	else if (strcmp(ptr,KW_NOT) == 0)
	{
		printf("KW_NOT\n");
	}
	else if (strcmp(ptr,KW_SET) == 0)
	{
		printf("KW_SET\n");
	}
	else if (strcmp(ptr,KW_CONCAT) == 0)
	{
		printf("KW_CONCAT\n");
	}
	else if (strcmp(ptr,KW_APPEND) == 0)
	{
		printf("KW_APPEND\n");
	}
	else if (strcmp(ptr,KW_FOR) == 0)
	{
		printf("KW_FOR\n");
	}
	else if (strcmp(ptr,KW_IF) == 0)
	{
		printf("KW_IF\n");
	}
	else if (strcmp(ptr,KW_EXIT) == 0)
	{
		printf("KW_EXIT\n");
	}
	else if (strcmp(ptr,KW_LOAD) == 0)
	{
		printf("KW_LOAD\n");
		printf("OP_OC\n");
		printf("IDENTIFIER\n");
		printf("OP_CC\n");
		
	}
	else if (strcmp(ptr,KW_DISP) == 0)
	{
		printf("KW_DISP\n");
	}
	else if (strcmp(ptr,KW_TRUE) == 0)
	{
		printf("KW_TRUE\n");
	}
	else if (strcmp(ptr,KW_FALSE) == 0)
	{
		printf("KW_FALSE\n");
	}
	else{
		return 0;
	}

	return 1;
}
int identifierCheck(char arr[]){
	int i = 0;
	for (int i = 0; i < strlen(arr); ++i)
	{

		if( 65 <= (int)arr[i] &&  90 >= (int)arr[i])
		{
			continue;
		}
		else if( 97 <= (int)arr[i] &&  122 >= (int)arr[i])
		{
			continue;
		}
		else{
			return 0;
		}
	}
	return 1;
}

int checkOperators(char ptr[]){
	if (strcmp(ptr,OP_PLUS) == 0)
	{
		printf("OP_PLUS\n");
	}
	else if (strcmp(ptr,OP_MINUS) == 0)
	{
		printf("OP_MINUS\n");
	}
	else if (strcmp(ptr,OP_DIV) == 0)
	{
		printf("OP_DIV\n");
	}
	else if (strcmp(ptr,OP_MULT) == 0)
	{
		printf("OP_MULT\n");
	}
	else if (strcmp(ptr,OP_OP) == 0)
	{
		printf("OP_OP\n");
	}
	else if (strcmp(ptr,OP_CP) == 0)
	{
		printf("OP_CP\n");
	}
	else if (strcmp(ptr,OP_OC) == 0)
	{
		printf("OP_OC\n");
	}
	else if (strcmp(ptr,OP_CC) == 0)
	{
		printf("OP_CC\n");
	}
	else{
		return 0;
	}

	return 1;	
}
