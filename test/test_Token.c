#include "unity.h"
#include "Token.h"
#include "Text.h"
#include "StringObject.h"
#include "CharSet.h"

void setUp(void) {}

void tearDown(void) {}

void test_numberNew_the_NUMBER_TOEKN_should_get_the_same_value_of_11_with_Number_type(void){
	
	Number *number;
	number = numberNew(11);
	
	TEST_ASSERT_EQUAL(11, number->value);
	TEST_ASSERT_EQUAL(NUMBER_TOKEN, number->type);
	
}

void test_numberNew_the_NUMBER_TOEKN_should_get_the_same_value_of_with_Number_type(void){
	
	Number *number;
	number = numberNew(478965);
	
	TEST_ASSERT_EQUAL(478965, number->value);
	TEST_ASSERT_EQUAL(NUMBER_TOKEN, number->type);
	
}

void test_numberNew_the_NUMBER_TOEKN_should_get_the_same_negative_value_with_Number_type(void){
	
	Number *number;
	number = numberNew(-23);
	
	TEST_ASSERT_EQUAL(-23, number->value);
	TEST_ASSERT_EQUAL(NUMBER_TOKEN, number->type);
	
}

void test_identifierNew_should_display_the_identifier_name_Feng(void){
	Text *text = textNew("Feng");
	Identifier *iName;
	iName = identifierNew(text);
	
	//strcmp("Feng", iName->name->string);

	//TEST_ASSERT_EQUAL(1, iName);
	TEST_ASSERT_EQUAL_STRING("Feng", iName->name->string);
}

void test_identifierNew_should_display_the_identifier_name_Ken(void){
	Text *text = textNew("Ken");
	Identifier *iName;
	iName = identifierNew(text);
	
	//strcmp("Feng", iName->name->string);

	//TEST_ASSERT_EQUAL(1, iName);
	TEST_ASSERT_EQUAL_STRING("Ken", iName->name->string);
}

void test_operatorNewBySymbol_with_not_symbol_should_return_token_type_if_the_symbol_is_in_table(void){
	int a;
	Operator *isSymbol;
	isSymbol = operatorNewBySymbol("!");
	
	a = strcmp("!", isSymbol->info->symbol);
	
	TEST_ASSERT_EQUAL(0, a);
	TEST_ASSERT_EQUAL(OPERATOR_TOKEN, isSymbol->type);
	
}

void test_operatorNewBySymbol_with_or_symbol_should_return_token_type_if_the_symbol_is_in_table(void){
	int a;
	Operator *isSymbol;
	isSymbol = operatorNewBySymbol("|");
	
	a = strcmp("|", isSymbol->info->symbol);
	
	TEST_ASSERT_EQUAL(0, a);
	TEST_ASSERT_EQUAL(OPERATOR_TOKEN, isSymbol->type);
	
}

void test_operatorNewByID_with_BITWISE_NOT_OP_id_should_return_token_type_if_the_id_is_in_table(void){
	int a;
	Operator *isId;
	isId = operatorNewByID(BITWISE_NOT_OP);
	
	TEST_ASSERT_EQUAL(BITWISE_NOT_OP, isId->info->id);
	TEST_ASSERT_EQUAL(OPERATOR_TOKEN, isId->type);
	
}

void test_operatorNewByID_with_DIV_OP_id_should_return_token_type_if_the_id_is_in_table(void){
	int a;
	Operator *isId;
	isId = operatorNewByID(DIV_OP);
	
	TEST_ASSERT_EQUAL(DIV_OP, isId->info->id);
	TEST_ASSERT_EQUAL(OPERATOR_TOKEN, isId->type);
	
}

void test_getToken(void){

	


}


