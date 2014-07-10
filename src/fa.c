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
	int BANKED = 1;
	int ACCESS = 0;
	int e;
	int error;
	
	Try{
		operand1 = extractValue(arguments);
	}Catch(e){
		if(e == ERR_NO_ERROR){
			printf("aaa\n");
			operand1 = operand1 & 0x01;
			Try{
				operand2 =extractAccessBanked(arguments);
			}Catch(error){
				if(error == ERR_NO_ERROR){
					printf("bbb\n");
					if(operand1 == 0){
						printf("ccc\n");
						operand2 = ACCESS;
						printf("%d", operand2);
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
	
	return operand1;
}

/*int operand_2(String *arguments){
	int operand1;
	int operand2;
	int opcode;
	int BANKED = 1;
	int ACCESS = 0;
	int e;
	
	Try{
		operand1 = fa(arguments);
	}Catch(e){
		if(e != ERR_EMPTY_VALUE){
			operand2 =extractAccessBanked(arguments);
		}else
			Throw(ERR_EMPTY_VALUE);
	}
	
	return opcode = operand1;
}*/
