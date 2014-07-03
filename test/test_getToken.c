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