#ifndef StringObject_H
#define StringObject_H

#include "Types.h"

typedef struct Text{
	uint32 reference;
	char string[0];
}Text;

typedef struct String{
	uint32 reference;
	Text *text;
	uint32 start;
	uint32 length;
}String;

void stringDump(String *string);
void textDump(Text *text);
Text *textNew(char *charStr);
Text *textAssign(Text *text);
Text *textDel(Text *text);
String *stringNew(Text *text);
String *stringAssign(String *string);
String *stringDel(String *string);
void stringSkip(String *string, int numChar2Skip);

#endif // StringObject_H
