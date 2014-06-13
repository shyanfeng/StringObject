#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "StringObject.h"
#include "Text.h"

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