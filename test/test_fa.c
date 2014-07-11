#include "unity.h"
#include "mock_Evaluate.h"
#include "fa.h"
#include "CException.h"
#include "StringObject.h"
#include "String.h"
#include "Text.h"
#include "ErrorCode.h"

void setUp(void){}

void tearDown(void){}

void test_operand1ExtractValue_over_range_should_mock_and_throw_error(void){
	int value;
	int e;
	
	Text *text = textNew("");
	String *str = stringNew(text);
	
	extractValue_ExpectAndThrow(str, 3);
	
	Try{
		value = operand1ExtractValue(str);
	}Catch(e){
		TEST_ASSERT_EQUAL(ERR_EMPTY_VALUE, e);
		
	}
	
}

void test_operand1ExtractValue_should_mock_and_return_35(void){
	int value;
	
	Text *text = textNew("35");
	String *str = stringNew(text);
	
	extractValue_ExpectAndReturn(str, 0x35);
	value = operand1ExtractValue(str);

	TEST_ASSERT_EQUAL(value, 0x35);
}

void test_operand2ExtractAccessBanked_should_throw_error(void){
	int value;
	int e;
	
	Text *text = textNew("135");
	String *str = stringNew(text);
	
	extractAccessBanked_ExpectAndThrow(str, 2);

	Try{
		value = operand2ExtractAccessBanked(str);
	}Catch(e){
		TEST_ASSERT_EQUAL(ERR_ILLEGAL_ARGUMENT, e);
		
	}
}
