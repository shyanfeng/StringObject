#include <stdio.h>
#include "Extract1BitsValue.h"
#include "StringObject.h"
#include "String.h"
#include "Text.h"
#include "ErrorCode.h"
#include "CException.h"
#include "CustomTypeAssert.h"
#include "Extract.h"
#include "Extract1BitsValue.h"

/**
 *
 *	operandExtract1BitsValue
 *
 *	To catch ERR_EMPTY_ARGUMENT or ERR_NO_ARGUMENT. If it caught then it 
 *	will assign operand equal to 0 and return operand. Else it will catch 
 *	ERR_ILLEGAL_ARGUMENT and throw error.
 *	
 *	Input	:
 *		arguements
 *		
 *	Return	:
 *		operand
 *
 **/
int operandExtract1BitsValue(String *arguments){
	int operand;
	int e;
	
	Try{
		operand = extractValue(arguments);
	}Catch(e){ 
        if(e == ERR_NO_ARGUMENT || e == ERR_EMPTY_ARGUMENT){
			operand = 0;
			return operand;
		}else if(e == ERR_ILLEGAL_ARGUMENT){
			printf("Error operand2 Throw");
			Throw(e);
		}
	}
	
	operand = 0x01 & operand;
	
	return operand;
}