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
	int e;
	
	Try{
		operand1 = extractValue(arguments);
		printf("%d\n", operand1);
	}Catch(e){
		if(e != ERR_EMPTY_VALUE){
			printf("aaa");
			//operand2 =extractAccessBanked(arguments);
		}else
			printf("Error Throw");
			Throw(ERR_EMPTY_VALUE);
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
