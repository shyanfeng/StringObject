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
	int opcode;
	int e;
	
	Try{
		operand1 = extractValue(arguments);
	}Catch(e){ 
        printf("Error Throw");
		Throw(e);
	} 
	
	return opcode = operand1;
}

/*int a(String *arguments){
	int operand1;
	int operand2;
	int opcode;
	int BANKED = 1;
	int ACCESS = 0;
	int e;
	int error;
	
	Try{
		extractValue(arguments);
	}Catch(e){
		if(e == ERR_NO_ERROR){
			operand1 = extractValue(arguments);
			printf("aaa\n");
			printf("%x\n", operand1);
		//	operand1 = operand1 & 0x01;
			Try{
				extractAccessBanked(arguments);
			}Catch(error){
				if(error == ERR_NO_ERROR){
					operand2 =extractAccessBanked(arguments);
					printf("bbb\n");
					printf("%x\n", operand2);
					if(operand2 == 0){
						printf("ccc\n");
						operand2 = ACCESS;
						printf("%x\n", operand2);
					}else{
						printf("ddd\n");
						operand2 = BANKED;
					}
				}else{
					// operand2 = ACCESS;
				}
			}
		}else{
			printf("Error Throw");
			Throw(ERR_EMPTY_VALUE);
		}
	} 
	
	return opcode = operand2 + operand1;
}*/
