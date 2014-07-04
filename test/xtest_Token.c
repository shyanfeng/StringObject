#include "unity.h"
#include "Token.h"
#include "Text.h"
#include "StringObject.h"
#include "CharSet.h"
#include "CException.h"
#include "ErrorCode.h"
#include "CustomTypeAssert.h"

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
	
	TEST_ASSERT_EQUAL_STRING("Feng", iName->name->string);
}

void test_identifierNew_should_display_the_identifier_name_Ken(void){
	Text *text = textNew("Ken");
	Identifier *iName;
	iName = identifierNew(text);
	
	TEST_ASSERT_EQUAL_STRING("Ken", iName->name->string);
}

void test_identifierNew_should_display_the_identifier_name_Lee(void){
	Text *text = textNew("Lee");
	Identifier *iName;
	iName = identifierNew(text);
	
	TEST_ASSERT_EQUAL_STRING("Lee", iName->name->string);
}

void test_identifierNew_should_display_the_identifier_name_Yao(void){
	Text *text = textNew("Yao");
	Identifier *iName;
	iName = identifierNew(text);
	
	TEST_ASSERT_EQUAL_STRING("Yao", iName->name->string);
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

void test_operatorNewBySymbol_with_minus_symbol_should_return_token_type_if_the_symbol_is_in_table(void){
	int a;
	Operator *isSymbol;
	isSymbol = operatorNewBySymbol("-");
	
	a = strcmp("-", isSymbol->info->symbol);
	
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

void test_operatorNewByID_with_MOD_OP_id_should_return_token_type_if_the_id_is_in_table(void){
	int a;
	Operator *isId;
	isId = operatorNewByID(MOD_OP);
	
	TEST_ASSERT_EQUAL(MOD_OP, isId->info->id);
	TEST_ASSERT_EQUAL(OPERATOR_TOKEN, isId->type);
	
}

void test_getToken_number_123_should_return_NUMBER_TOKEN(void){
	
	Text *text = textNew("123");
	String *strToken = stringNew(text);
	Token *tokenGet;
	tokenGet = getToken(strToken);
	printf("%d", ((Number *)tokenGet)->value);
	
	TEST_ASSERT_NOT_NULL(tokenGet);
	TEST_ASSERT_EQUAL(NUMBER_TOKEN, tokenGet->type);
	TEST_ASSERT_EQUAL(123, ((Number *)tokenGet)->value);
	
}

void test_getToken_number_space_456_space_should_return_NUMBER_TOKEN(void){
	
	Text *text = textNew(" 456 ");
	String *strToken = stringNew(text);
	Token *tokenGet;
	tokenGet = getToken(strToken);
	printf("%d", ((Number *)tokenGet)->value);
	
	TEST_ASSERT_NOT_NULL(tokenGet);
	TEST_ASSERT_EQUAL(NUMBER_TOKEN, tokenGet->type);
	TEST_ASSERT_EQUAL(456, ((Number *)tokenGet)->value);
	
}

void test_getToken_number_231_space_567_should_return_NUMBER_TOKEN(void){
	
	Text *text = textNew("231 567");
	String *strToken = stringNew(text);
	Token *tokenGet;
	tokenGet = getToken(strToken);
	printf("%d", ((Number *)tokenGet)->value);
	
	TEST_ASSERT_NOT_NULL(tokenGet);
	TEST_ASSERT_EQUAL(NUMBER_TOKEN, tokenGet->type);
	TEST_ASSERT_EQUAL(231, ((Number *)tokenGet)->value);
	
}

void test_getToken_number_space_341_space_956_space_should_return_NUMBER_TOKEN(void){
	
	Text *text = textNew(" 341 956");
	String *strToken = stringNew(text);
	Token *tokenGet;
	tokenGet = getToken(strToken);
	printf("%d", ((Number *)tokenGet)->value);
	
	TEST_ASSERT_NOT_NULL(tokenGet);
	TEST_ASSERT_EQUAL(NUMBER_TOKEN, tokenGet->type);
	TEST_ASSERT_EQUAL(341, ((Number *)tokenGet)->value);
	
}

void test_getToken_number_space_341a_space_956_space_should_throw_error(void){
	int e;
	
	Text *text = textNew(" 341a 956");
	String *strToken = stringNew(text);
	Token *tokenGet;
	
	Try{
		tokenGet = getToken(strToken);
	}Catch(e){
		TEST_ASSERT_EQUAL(ERR_NUMBER_NOT_WELL_FORMED, e);
	}
	
}

void test_getToken_number_space_441b23b42b_space_231_space_should_throw_error(void){
	int e;
	
	Text *text = textNew(" 441b23b42b 231");
	String *strToken = stringNew(text);
	Token *tokenGet;
	
	Try{
		tokenGet = getToken(strToken);
	}Catch(e){
		TEST_ASSERT_EQUAL(ERR_NUMBER_NOT_WELL_FORMED, e);
	}
	
}

void test_getToken_operator_plus_should_return_OPERATOR_TOKEN(void){

	Text *text = textNew("+");
	String *strToken = stringNew(text);
	Token *tokenGet;
	tokenGet = getToken(strToken);
	printf("%s\n", ((Operator *)tokenGet)->info->symbol);
	
	TEST_ASSERT_EQUAL(OPERATOR_TOKEN, tokenGet->type);

}

void test_getToken_operator_and_should_return_OPERATOR_TOKEN(void){

	Text *text = textNew("&");
	String *strToken = stringNew(text);
	Token *tokenGet;
	tokenGet = getToken(strToken);
	printf("%s", ((Operator *)tokenGet)->info->symbol);
	
	TEST_ASSERT_EQUAL(OPERATOR_TOKEN, tokenGet->type);

}

void test_getToken_operator_space_and_and_should_return_OPERATOR_TOKEN(void){

	Text *text = textNew(" &&");
	String *strToken = stringNew(text);
	Token *tokenGet;
	tokenGet = getToken(strToken);
	printf("%s", ((Operator *)tokenGet)->info->symbol);
	
	TEST_ASSERT_EQUAL(OPERATOR_TOKEN, tokenGet->type);

}

void test_getToken_operator_space_or_or_should_return_OPERATOR_TOKEN(void){

	Text *text = textNew(" ||");
	String *strToken = stringNew(text);
	Token *tokenGet;
	tokenGet = getToken(strToken);
	printf("%s", ((Operator *)tokenGet)->info->symbol);
	
	TEST_ASSERT_EQUAL(OPERATOR_TOKEN, tokenGet->type);

}

void test_getToken_operator_and_with_plus_should_throw_error(void){
	int e;
	
	Text *text = textNew("@1");
	String *strToken = stringNew(text);
	Token *tokenGet;

	Try{
		tokenGet = getToken(strToken);
	}Catch(e){
		TEST_ASSERT_EQUAL(ERR_NUMBER_NOT_WELL_FORMED, e);
	}

}

void test_getToken_operator_space_and_and_space_123_should_return_OPERATOR_TOKEN(void){

	Text *text = textNew(" && 123");
	String *strToken = stringNew(text);
	Token *tokenGet;
	tokenGet = getToken(strToken);
	printf("%s", ((Operator *)tokenGet)->info->symbol);
	
	TEST_ASSERT_EQUAL(OPERATOR_TOKEN, tokenGet->type);

}

void test_getToken_operator_space_or_or_a_space_123_should_return_OPERATOR_TOKEN(void){
	int e;
	
	Text *text = textNew(" ||a 123");
	String *strToken = stringNew(text);
	Token *tokenGet;
	
	Try{
		tokenGet = getToken(strToken);
	}Catch(e){
		TEST_ASSERT_EQUAL(ERR_NUMBER_NOT_WELL_FORMED, e);
	}

}

void test_getToken_identifier_Night_should_return_IDENTIFIER_TOKEN(void){

	Text *text = textNew("Night");
	String *strToken = stringNew(text);
	Token *tokenGet;
	tokenGet = getToken(strToken);
	printf("%s", ((Identifier *)tokenGet)->name->string);
	
	TEST_ASSERT_EQUAL(IDENTIFIER_TOKEN, tokenGet->type);

}

void test_getToken_identifier_space_morning_should_return_IDENTIFIER_TOKEN(void){

	Text *text = textNew(" morning");
	String *strToken = stringNew(text);
	Token *tokenGet;
	tokenGet = getToken(strToken);
	printf("%s", ((Identifier *)tokenGet)->name->string);
	
	TEST_ASSERT_EQUAL(IDENTIFIER_TOKEN, tokenGet->type);

}

void test_getToken_identifier_space_afternoon_should_return_IDENTIFIER_TOKEN(void){

	Text *text = textNew(" afternoon 123");
	String *strToken = stringNew(text);
	Token *tokenGet;
	tokenGet = getToken(strToken);
	printf("%s", ((Identifier *)tokenGet)->name->string);
	
	TEST_ASSERT_EQUAL(IDENTIFIER_TOKEN, tokenGet->type);

}

void test_getToken_identifier_space_Math123_should_throw_error(void){
	int e;
	
	Text *text = textNew(" Math123");
	String *strToken = stringNew(text);
	Token *tokenGet;
	
	Try{
		tokenGet = getToken(strToken);
	}Catch(e){
		TEST_ASSERT_EQUAL(ERR_NUMBER_NOT_WELL_FORMED, e);
	}

}

void test_getToken_identifier_space_TDD_plus_123_should_throw_error(void){
	int e;
	
	Text *text = textNew(" TDD+123");
	String *strToken = stringNew(text);
	Token *tokenGet;
	
	Try{
		tokenGet = getToken(strToken);
	}Catch(e){
		TEST_ASSERT_EQUAL(ERR_NUMBER_NOT_WELL_FORMED, e);
	}

}

void test_getToken_space_or_or_space_896_space_name_should_return_NUMBER_TOKEN_and_IDENTIFIER_TOKEN_and_OPERATOR_TOKEN(void){

	Text *text = textNew(" || 896 name");
	String *strToken = stringNew(text);
	Token *tokenGet;

	tokenGet = getToken(strToken);
	stringDump(strToken);
	printf("%s\n", ((Operator *)tokenGet)->info->symbol);
	TEST_ASSERT_EQUAL(OPERATOR_TOKEN, tokenGet->type);
	
	tokenGet = getToken(strToken);
	stringDump(strToken);
	printf("%d\n", ((Number *)tokenGet)->value);
	TEST_ASSERT_EQUAL(NUMBER_TOKEN, tokenGet->type);
	TEST_ASSERT_EQUAL(896, ((Number *)tokenGet)->value);
	
	tokenGet = getToken(strToken);
	stringDump(strToken);
	printf("%s\n", ((Identifier *)tokenGet)->name->string);
	TEST_ASSERT_EQUAL(IDENTIFIER_TOKEN, tokenGet->type);
	TEST_ASSERT_EQUAL_STRING("name", ((Identifier *)tokenGet)->name->string);

}

void test_tokenDel_should_delete_identifier_and_return_NULL(void){

	Text *text = textNew("cisco 123 &&");
	String *strToken = stringNew(text);
	Token *tokenGet;
	
	tokenGet = getToken(strToken);
	printf("%s", ((Identifier *)tokenGet)->name->string);	
	tokenDel(tokenGet);
	stringDump(strToken);
	TEST_ASSERT_EQUAL(NULL, tokenGet->type);
	
}


