#include <stdio.h>
#include "fsfd.h"
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
        printf("Error operand1 Throw");
		Throw(e);
	} 
	
    printf("%x\n", operand1);
	return operand1;
}

int operand2ExtractValue(String *arguments){
	int operand2;
	int e;
	
	Try{
		operand2 = extractValue(arguments);
	}Catch(e){ 
        if(e == ERR_EMPTY_VALUE || e == ERR_NO_ARGUMENT || ERR_ILLEGAL_ARGUMENT){
			printf("Error operand2 Throw");
			Throw(e);
		}
	}
	
    printf("%x\n", operand2);
	return operand2;
}

int FSFD(String *arguments){
	int operand1;
	int operand2;
	int opcode;
	
	operand1 = operand1ExtractValue(arguments);
	operand2 = operand2ExtractValue(arguments);
	
	return opcode = (0x0<<24) + (operand2<<16) + (0x0<<8) + (operand1);
}

