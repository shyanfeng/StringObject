#include <stdio.h>
#include "Extract1BitsAccessBanked.h"
#include "StringObject.h"
#include "String.h"
#include "Text.h"
#include "ErrorCode.h"
#include "CException.h"
#include "CustomTypeAssert.h"
#include "Extract.h"

int extract1bitsACCESSBANKED(String *arguments, int value){
	int operand2;
    int BANKED = 1;
    int ACCESS = 0;
	ErrorCode e;
    
	Try{
		operand2 = extractACCESSBANKED(arguments);
	}Catch(e){ 
		if(e == ERR_EMPTY_ARGUMENT || e == ERR_NO_ARGUMENT){
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
    
	return operand2;
}