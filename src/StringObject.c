#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "StringObject.h"

/*int stringIsEqualCaseInSensitve(String *string1, String *string2){

}
*/
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
		}
	}

	//return 1;


}

String *stringRemoveWordContaining(String *string, char containSet[]){
	
	int i = 0;
	int j = 0;
	String *string2 = stringNew(string->text);
	string2->start = 0;
	string2->length = 0;

	while(string->text->string[i] != 0){
		if(string->text->string[i] == containSet[j]){
			string->start++;
			string->length--;
			string2->length++;
		}else{
			break;
		}
	i++;
	j++;
	}
	return string2;

}

String *stringRemoveWordNotContaining(String *string, char *delimiters){
	
	int i = 0;
	int j = 0;
	String *string2 = stringNew(string->text);
	string2->start = 0;
	string2->length = 0;
	
	while(string->text->string[i] != 0){
		if(string->text->string[i] != delimiters[j]){
			string->start++;
			string->length--;
			string2->length++;
		}else{
			break;
		}
	i++;
	}
	return string2;
}

int stringLength(String *string){
	
	return string->length;

}

int stringRemoveChar(String *string){
	
	char a = string->text->string[string->start];
	char b = string->text->string[string->length];
	
	if(a != b){
	string->start++;
	string->length--;
	}
	
	return -1;
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

Text *textDel(Text *text){
	if(text->reference < 0x80000000 && text->reference > 0){
		--text->reference;
		if(text->reference == 0){
			free(text);
			return NULL;
		}
	}
	
	return text;

}

Text *textAssign(Text *text){
	if(text->reference != 0x80000000){
		text->reference++;
	}
	return text;
}

Text *textNew(char *charStr){
	Text *text = (Text *)malloc(strlen(charStr) + 4 + 1);
	strcpy(text->string, charStr);
	text->reference = 1;
	return text;
	
}

void textDump(Text *text){
	if(text == NULL){
		printf("(NULL)\n");
		return;
	}
	printf("text[%x]:%s\n", text->reference, text->string);
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
