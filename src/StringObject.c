#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "StringObject.h"
#include "Text.h"

Text *stringSubstringInText(String *str, int relativePosition, int length){
	char *charStr = stringSubstringInChar(str, relativePosition, length);
	Text *text = textNew(charStr);
	free(charStr);
	
	return text;
}

int stringToInteger(String *str){
	int intValue;
	
	char *charStr = stringSubstringInChar(str, str->start, str->length);
	intValue = atoi(charStr);
	free(charStr);
	
	return intValue;
	
}

char *stringSubstringInChar(String *str, int relativePosition, int length){
	int i = 0;
	int j = relativePosition;
	char *toChar = malloc(sizeof(char) * (length + 1));
	
	if(length > str->length){
		return " ";
	}
	
	while(j <= (relativePosition + length - 1)){

		toChar[i] = str->text->string[j];
		printf("%c\n", toChar[i]);
		
		i++;
		j++;
	}
	toChar[i] = 0;
	return toChar;
}


int stringCharAtInSet(String *str, int relativeIndex, char set[]){
	int i = 0;
	
	while(set[i] != 0){
		if(str->text->string[str->start + relativeIndex] == set[i]){
			return 1;
		}else{
			i++;
		}
	}
	
	return 0;
}

/**
 * Return the character at the specified relative index
 * of the String
 *
 * Input:
 *	str				is the String object
 *	relativeIndex	is the relative index into the String.
					This value must be positive.
 * Return the character at the relative index if exists.
 * Otherwise return -1. If relativeIndex < 0, -1 is returned
 * as well
 */
 
 int stringCharAt(String *str, int relativeIndex){
	if(relativeIndex == -1){
		return -1;
	}
	
	if(relativeIndex < str->length){
		return str->text->string[str->start + relativeIndex];
	}else{
		return -1;
	}
 }

int stringIsEqualCaseInSensitve(String *string1, String *string2){

	int i;
	int length;
	
	if(string1->length != string2->length){
		return 0;
	}
	
	string1->length = string2->length;
	length = string1->length;
	
	for(i = 0; i < length; i++){
		string1->text->string[i] = tolower(string1->text->string[i]);
		string2->text->string[i] = tolower(string2->text->string[i]);
	}


	for(i = 0; i < length; i++){
		printf("%c\n", string1->text->string[i + string1->start]);
		printf("%c\n", string2->text->string[i + string2->start]);
		if(string1->text->string[i + string1->start] != string2->text->string[i + string2->start]){
			printf("DETECTED NOT SAME\n");
			return 0;
		}
	}

	return 1;

}

int stringIsEqual(String *string1, String *string2){
	
	int i;
	int length;
	
	if(string1->length != string2->length){
		return 0;
	}
	
	string1->length = string2->length;
	length = string1->length;

	for(i = 0; i < length; i++){
		printf("%c\n", string1->text->string[i + string1->start]);
		printf("%c\n", string2->text->string[i + string2->start]);
		if(string1->text->string[i + string1->start] != string2->text->string[i + string2->start]){
			printf("DETECTED NOT SAME\n");
			return 0;
		}
	}

	return 1;


}

String *stringRemoveWordContaining(String *string, char containSet[]){
	
	int i = string->start;
	int j = 0;
	int k = 0;
	int status;
	int conValue = 0;
	
	String *string2 = stringNew(string->text);
	string2->start = string->start;
	string2->length = 0;
	
	while(containSet[k] > string->length){
		conValue++;
		k++;
	}


	while(string->text->string[i] != 0){
		while(containSet[j] != 0){
			if(string->text->string[i] == containSet[j]){
				string2->length++;
				string->start++;
				string->length--;
				goto getValue;
			}else{
				status++;
			}
			j++;
		}
		
		if(status >= conValue){
			return string2;
		}
		
		getValue:
		j = 0;
		i++;
	}

	
	return string2;

}

String *stringRemoveWordNotContaining(String *string, char *delimiters){
	
	int i = string->start;
	int j = 0;
	String *string2 = stringNew(string->text);
	string2->start = 0;
	string2->length = 0;
	
	while(string->text->string[i] != 0){
		while(delimiters[j] != 0){
			if(string->text->string[i] == delimiters[j]){
				string2->start = string->start;
				string2->length = i - string->start;
				string->start = i;
				string->length = string->length - i;
				return string2;
			}else{
				j++;
			}
			/*if(string->text->string[i] == delimiters[j]){
				end = i;
			}
		
			if(string->text->string[i] == delimiters[j + 1]){
					start = i;
			}
			
			string->start = start;
			string->length = (end - start) + 1;
			string2->length = (string->start - string2->start);
			*/

		}
		j = 0;
			
	i++;
	}
	return string2;
}

int stringLength(String *string){
	
	return string->length;

}

int stringRemoveChar(String *string){
	
	char a = string->text->string[string->start];
	
	if(string->length != 0){
		string->start++;
		string->length--;
		return a;
	}else{
		return -1;
	}
}

void stringTrim(String *string){

	stringTrimLeft(string);
	stringTrimRight(string);

}

void stringTrimRight(String *string){
	int i = string->start + string->length - 1;
	char ch = string->text->string[i];
	
	while(isSpace(ch)){
		i--;
		ch = string->text->string[i];
		string->length--;
	}
	
}

void stringTrimLeft(String *string){
	int i = 0;
	char ch = string->text->string[0];
	
	while(isSpace(ch)){
		i++;
		ch = string->text->string[i];
		string->start++;
		string->length--;
	}
	
}

void stringSkip(String *string, int numChar2Skip){
	int starting = string->start + numChar2Skip;

	if(starting < string->length){
		string->start = starting;
		string->length = string->length - string->start;	
	}else{
		string->start = string->length;
	}
}

String *stringDel(String *string){
	string->reference--;
	if(string->reference == 0){
		printf("free\n");
		free(string);
		return NULL;
	}
	return string;
	
}

String *stringAssign(String *string){
		string->reference++;
		
	return string;
	
}

String *stringNew(Text *text){
	String *string = malloc(sizeof(String));
	string->text = textAssign(text);
	string->reference = 1;
	string->start = 0;
	string->length = strlen(text->string);
	
	return string;
	
}

void stringDump(String *string){
	uint32 index = 0, len = 0;
	char *fullString = "(NULL)\n";
	char *actualString = "(NULL)\n";
	
	if(string == NULL){
		printf("NULL\n");
		return;
	}
	
	if(string->text != NULL){
		int actualLength;
		fullString		= string->text->string;
		index			= string->start;
		if(index <= strlen(fullString)){
			actualString	= &fullString[index];
			actualLength	= strlen(actualString);
			len				= string->length;
			if(len > actualLength)
				len = actualLength;
		}else{
			actualString = "";
		}
	}
	
	printf("[%d] f_str[%d]:%s, start:%d, len:%d, str:%.*s\n",
		string->reference, string->text->reference, fullString, index, string->length, len, actualString);

}
