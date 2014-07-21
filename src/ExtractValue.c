#include <stdio.h>
#include "FA.h"
#include "StringObject.h"
#include "String.h"
#include "Text.h"
#include "ErrorCode.h"
#include "CException.h"
#include "CustomTypeAssert.h"
#include "Extract.h"

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