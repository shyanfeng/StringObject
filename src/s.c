#include <stdio.h>
#include "s.h"
#include "StringObject.h"
#include "String.h"
#include "Text.h"
#include "ErrorCode.h"
#include "CException.h"
#include "CustomTypeAssert.h"
#include "Evaluate.h"

int operand1ExtractValue(String *arguments){
	int operand1;
	int e;
	
	Try{
		operand1 = extractValue(arguments);
	}Catch(e){ 
		if(e == ERR_NO_ARGUMENT || e == ERR_EMPTY_VALUE){
			operand1 = 0;
		}else if(e == ERR_ILLEGAL_ARGUMENT){
			printf("Error operand1 Throw");
			Throw(e);
		}
	}
	
	return operand1;
}

int S(String *arguments){
	int operand1;
	int opcode;
	
	operand1 = operand1ExtractValue(arguments);
	operand1 = 0x01 & operand1;
	
	return opcode = operand1;
}
