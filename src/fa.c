#include <stdio.h>
#include "fa.h"
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

int operand2ExtractAccessBanked(String *arguments, int value){
	int operand2;
    int BANKED = 1;
    int ACCESS = 0;
	int e;
    
	Try{
		operand2 = extractAccessBanked(arguments);
	}Catch(e){ 
		if(e == ERR_EMPTY_VALUE || e == ERR_NO_ARGUMENT){
			if((value >= 0x0 && value <= 0x80) || (value >= 0xff0 && value <= 0xfff)){
				operand2 = ACCESS;
			}else{
				operand2 = BANKED;
			}
		}else{
			printf("Error opearand2 Throw");
			Throw(e);
		}
	}
	
    if(operand2 == 0){
        operand2 = ACCESS;
    }else{
        operand2 = BANKED;
    }
    
    printf("%x", operand2);
	return operand2;
}

int FA(String *arguments){
	int operand1;
	int operand2;
	int opcode;
	int e;
	
	operand1 = operand1ExtractValue(arguments);
	operand2 = operand2ExtractAccessBanked(arguments, operand1);
	
	operand1 = operand1 & 0xff;
	
	return opcode = operand1 + operand2;
}

