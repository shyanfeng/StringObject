#include <stdio.h>
#include "fa.h"
#include "StringObject.h"
#include "String.h"
#include "Text.h"
#include "ErrorCode.h"
#include "CException.h"
#include "CustomTypeAssert.h"
#include "Evaluate.h"

int fa(String *arguments){
	int operand1;
	int operand2;
	int BANKED;
	int ACCESS;
	operand1 = extractValue(arguments);
	operand2 =extractAccessBanked(arguments);
	
	
	if(operand1>>8 > 1){
		operand2 = BANKED;
	}else if(operand1>>8 == 1){
		operand2 = ACCESS;
	}
}

