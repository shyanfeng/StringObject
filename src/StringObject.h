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

#endif // StringObject_H
