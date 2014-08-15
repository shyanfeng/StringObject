#include <stdio.h>
#include "NS.h"
#include "StringObject.h"
#include "String.h"
#include "Text.h"
#include "ErrorCode.h"
#include "CException.h"
#include "CustomTypeAssert.h"
#include "Extract.h"
#include "ExtractValue.h"
#include "Extract1BitsValue.h"

/**
 *	NS
 *	
 *	To generate the opcode is based on the operand1 and operand2. The operand1
 *	is get the value and shifted to left 16 times and return. After that get the 
 *	operand1 and mask with 0xff and return. The operand2 is get the value and 
 *	shifted to left 8 times and return
 *
 *	Input 	:
 *		arguments
 *
 *	Return	:
 *		opcode
 **/
int NS(String *arguments){
	int operand1;
	int operand2;
	int opcode;
	
	operand1 = operand1ExtractValue(arguments);
	operand2 = operandExtract1BitsValue(arguments);
	
	return opcode = (0x0<<24) + (operand1<<16) + (operand2<<8) + (operand1 & 0xff);


}


