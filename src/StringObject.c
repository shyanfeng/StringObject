#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "StringObject.h"

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
			len = 0;
		}
	}
	
	printf("[%d] f_str[%d]:%s, start:%d, len:%d, str:%.*s\n",
		string->reference, string->text->reference, fullString, index, string->length, len, actualString);

}
