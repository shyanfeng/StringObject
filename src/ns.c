#include <stdio.h>
#include "NS.h"
#include "StringObject.h"
#include "String.h"
#include "Text.h"
#include "ErrorCode.h"
#include "CException.h"
#include "CustomTypeAssert.h"
#include "Evaluate.h"
#include "Helper.h"

STATIC int operand1ExtractValue(String *arguments){
	int operand1;
	int e;
	
	Try{
		operand1 = extractValue(arguments);
	}Catch(e){ 
        printf("Error operand1 Throw");
		Throw(e);
	}
	
	return operand1;
}

STATIC int operand2ExtractValue(String *arguments){
	int operand2;
	int e;
	
	Try{
		operand2 = extractValue(arguments);
	}Catch(e){ 
        if(e == ERR_NO_ARGUMENT || e == ERR_EMPTY_VALUE){
			operand2 = 0;
			return operand2;
		}else if(e == ERR_ILLEGAL_ARGUMENT){
			printf("Error operand2 Throw");
			Throw(e);
		}
	}
	
	operand2 = 0x01 & operand2;
	
	return operand2;
}

int NS(String *arguments){
	int operand1;
	int operand2;
	int opcode;
	
	operand1 = operand1ExtractValue(arguments);
	operand2 = operand2ExtractValue(arguments);
	
	return opcode = (0x0<<24) + (operand1<<16) + (operand2<<8) + (operand1 & 0xff);


}


