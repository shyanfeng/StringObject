#include "unity.h"
#include "mock_Extract.h"
#include "ExtractValue.h"
#include "CException.h"
#include "StringObject.h"
#include "String.h"
#include "Text.h"
#include "ErrorCode.h"

void setUp(void){}

void tearDown(void){}

void test_FA_operand1ExtractValue_ERR_EMPTY_ARGUMENT_should_mock_and_throw_error(void){
	int value;
	int e;
	
	Text *text = textNew("");
	String *str = stringNew(text);
	
	extractValue_ExpectAndThrow(str, 3);
	
	Try{
		value = operand1ExtractValue(str);
	}Catch(e){
		TEST_ASSERT_EQUAL(ERR_EMPTY_ARGUMENT, e);
		
	}
	
}

void test_FA_operand1ExtractValue_should_mock_and_return_35(void){
	int value;
	
	Text *text = textNew("35");
	String *str = stringNew(text);
	
	extractValue_ExpectAndReturn(str, 0x35);
	value = operand1ExtractValue(str);

	TEST_ASSERT_EQUAL(value, 0x35);
}