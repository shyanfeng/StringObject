#include <stdio.h>
#include "Token.h"
#include "CharSet.h"
#include <malloc.h>
#include "ErrorCode.h"
#include "CException.h"
#include "CustomTypeAssert.h"

#define MAIN_OPERATOR_TABLE_SIZE	(sizeof(mainOperatorTable)/sizeof(OperatorInfo))
#define	ALTERNATIVE_OPERATOR_TABLE_SIZE	(sizeof(alternativeOperatorTable)/sizeof(OperatorInfo))

OperatorInfo mainOperatorTable[] = {
  {.symbol="~", .id=BITWISE_NOT_OP, .precedence=150, .affix=INFIX, .assoc=LEFT_TO_RIGHT},
  {.symbol="!", .id=LOGICAL_NOT_OP, .precedence=150, .affix=INFIX, .assoc=LEFT_TO_RIGHT},
  {.symbol="*", .id=MUL_OP, .precedence=100, .affix=INFIX, .assoc=LEFT_TO_RIGHT},
  {.symbol="/", .id=DIV_OP, .precedence=100, .affix=INFIX, .assoc=LEFT_TO_RIGHT},
  {.symbol="%", .id=MOD_OP, .precedence=100, .affix=INFIX, .assoc=LEFT_TO_RIGHT},
  {.symbol="+", .id=ADD_OP, .precedence=80, .affix=INFIX, .assoc=LEFT_TO_RIGHT},
  {.symbol="-", .id=SUB_OP, .precedence=80, .affix=INFIX, .assoc=LEFT_TO_RIGHT},
  {.symbol="&", .id=BITWISE_AND_OP, .precedence=60, .affix=INFIX, .assoc=LEFT_TO_RIGHT},
  {.symbol="^", .id=BITWISE_XOR_OP, .precedence=50, .affix=INFIX, .assoc=LEFT_TO_RIGHT},
  {.symbol="|", .id=BITWISE_OR_OP, .precedence=40, .affix=INFIX, .assoc=LEFT_TO_RIGHT},  
  {.symbol="&&", .id=LOGICAL_AND_OP, .precedence=30, .affix=INFIX, .assoc=LEFT_TO_RIGHT},
  {.symbol="||", .id=LOGICAL_OR_OP, .precedence=20, .affix=INFIX, .assoc=LEFT_TO_RIGHT},
  // All other symbols MUST have higher precedence than those below:
  {.symbol="(", .id=OPENING_BRACKET_OP, .precedence=10, .affix=PREFIX, .assoc=RIGHT_TO_LEFT},
  {.symbol=")", .id=CLOSING_BRACKET_OP, .precedence=9,  .affix=POSTFIX, .assoc=LEFT_TO_RIGHT}
};

OperatorInfo alternativeOperatorTable[] = {
  {.symbol="+", .id=PLUS_OP, .precedence=150, .affix=PREFIX, .assoc=RIGHT_TO_LEFT},
  {.symbol="-", .id=MINUS_OP, .precedence=150, .affix=PREFIX, .assoc=RIGHT_TO_LEFT}
};

/**
 * Create a Number token initialized to the value given.
 *
 * Input:
 *   value  is the value to initialized with
 */
Number *numberNew(int value) {
  Number *number = malloc(sizeof(value));
  
  number->type = NUMBER_TOKEN;
  number->value = value;
}

/**
 * Create an Operator token identified by symbol.
 *
 * Input:
 *   symbol is symbol in string of characters, i.e., "*"
 *          and "&&".
 */
Operator *operatorNewBySymbol(char *symbol) {
	
	Operator *isSymbol = malloc(sizeof(isSymbol));
	int i;
	isSymbol->type = OPERATOR_TOKEN;

	for(i = 0; i < 14; i++){
		if(strcmp(mainOperatorTable[i].symbol, symbol) == 0){
			isSymbol->info = &mainOperatorTable[i];
		}
	}
	
	return isSymbol;
}

/**
 * Create an Operator token identified by the ID.
 *
 * Input:
 *   symbol is symbol in string of characters, i.e., MUL_OP
 *          and CLOSING_BRACKET_OP.
 */
Operator *operatorNewByID(OperatorID id) {
	
	Operator *isId = malloc(sizeof(id));
	int i;
	isId->type = OPERATOR_TOKEN;

	for(i = 0; i < 14; i++){
		if(mainOperatorTable[i].id == id){
			isId->info = &mainOperatorTable[i];
		}
	}
	
	return isId;
}

/**
 * Create an Identifier token initialized with the name
 * given.
 *
 * Input:
 *   name is the name of the identifier.
 */
Identifier *identifierNew(Text *name) {
	
	Identifier *iName = malloc(sizeof(name));
	int compare;
	iName->type = IDENTIFIER_TOKEN;
	iName->name = name;
	iName->number = NULL;

	return iName;
}

/**
 * Return the one token from the String. The String is updated.
 * If the string is empty, NULL is return.
 *
 * Input:
 *   str  is the String object
 *
 * Possible returned token:
 *    Number, Operator, and Identifier tokens
 */
Token *getToken(String *str) {
	Token *tokenizer;
	stringTrimLeft(str);
	
	// Number token
	
	if(stringCharAtInSet(str, str->start, numberSet)){
		String *strNum = stringRemoveWordContaining(str, numberSet);
		
		if(isSpace(stringCharAt(str, 0)) || str->length == 0){
			goto returnToken;
		}else{
			free(strNum);
			Throw(ERR_NUMBER_NOT_WELL_FORMED);
		}
		returnToken:
		return (Token *)numberNew(stringToInteger(strNum));
	}
	
	/*
	 * Operator token
	*/
	if(stringCharAtInSet(str, str->start, operatorSet)){
		char getOperator[3];
		
		getOperator[0] = (char)stringRemoveChar(str);
		getOperator[1] = 0;
		
		if(stringCharAt(str, 0) == getOperator[0]){
			if(stringCharAt(str, 0) == '&'){
				getOperator[0] = '&';
				getOperator[1] = getOperator[0];
				getOperator[2] = 0;
			}else if(stringCharAt(str, 0) == '|'){
				getOperator[0] = '|';
				getOperator[1] = getOperator[0];
				getOperator[2] = 0;
			}else{
				Throw(ERR_NUMBER_NOT_WELL_FORMED);
			}
			
			str->start++;
			str->length--;
		}
		
		if(isSpace(stringCharAt(str, 0)) || str->length == 0){
			goto returnOperator;
		}else{
			Throw(ERR_NUMBER_NOT_WELL_FORMED);
		}
		
		returnOperator:
		return (Token *)operatorNewBySymbol(getOperator);
	}
	
	/*
	 * Identifier
	*/
	if(stringCharAtInSet(str, str->start, alphabetSet)){
		String *getIdentifier;
		getIdentifier = stringRemoveWordContaining(str, alphabetSet);
		
		if(isSpace(stringCharAt(str, 0)) || str->length == 0){
			goto returnIdentifier;
		}else{
			free(getIdentifier);
			Throw(ERR_NUMBER_NOT_WELL_FORMED);
		}
		
		returnIdentifier:
		return (Token *)identifierNew(stringSubstringInText(getIdentifier, getIdentifier->start, getIdentifier->length));
		
	}
	
}

void tokenDel(Token *token){
	
	


}

