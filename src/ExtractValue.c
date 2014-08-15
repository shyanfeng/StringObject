#include <stdio.h>
#include "FA.h"
#include "StringObject.h"
#include "String.h"
#include "Text.h"
#include "ErrorCode.h"
#include "CException.h"
#include "CustomTypeAssert.h"
#include "Extract.h"

/**
 *
 *	operand1ExtractValue
 *
 *	Try to get the operand1 and return operand1. Catch e and throw error.
 *	
 *	Input	:
 *		arguements
 *		
 *	Return	:
 *		operand1
 *
 **/
int operand1ExtractValue(String *arguments){
	int operand1;
	ErrorCode e;
	
	Try{
		operand1 = extractValue(arguments);
	}Catch(e){ 
        printf("Error operand1 Throw");
		Throw(e);
	} 
	
	return operand1;
}