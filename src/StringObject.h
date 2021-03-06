#ifndef StringObject_H
#define StringObject_H

#include "Types.h"
#include "Text.h"
#define isSpace(ch) (ch == ' ' || ch == '\t')
#define t (Text *)"\x00\x00\x00\x80"


typedef struct String{
	uint32 reference;
	Text *text;
	uint32 start;
	uint32 length;
}String;

void stringDump(String *string);
String *stringNew(Text *text);
String *stringAssign(String *string);
String *stringDel(String *string);
void stringSkip(String *string, int numChar2Skip);
void stringTrimLeft(String *string);
void stringTrimRight(String *string);


int stringRemoveChar(String *string);
int stringLength(String *string);
String *stringRemoveWordNotContaining(String *string, char *delimiters);
String *stringRemoveWordContaining(String *string, char containSet[]);
int stringIsEqual(String *string1, String *string2);
int stringIsEqualCaseInSensitve(String *string1, String *string2);
int stringCharAt(String *str, int relativeIndex);
int stringCharAtInSet(String *str, int relativeIndex, char set[]);

char *stringSubstringInChar(String *str, int relativePosition, int length);
int stringToInteger(String *str);
Text *stringSubstringInText(String *str, int relativePosition, int length);


#endif // StringObject_H
