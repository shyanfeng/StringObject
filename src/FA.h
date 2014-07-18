#ifndef _FA_H_
#define _FA_H_

#include "Evaluate.h"
#include "Helper.h"

int FA(String *arguments);
STATIC int operand1ExtractValue(String *arguments);
STATIC int operand2ExtractAccessBanked(String *arguments, int value);

#endif // _FA_H_
