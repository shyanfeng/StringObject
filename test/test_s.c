#include "unity.h"
#include "mock_Evaluate.h"
#include "s.h"
#include "CException.h"
#include "StringObject.h"
#include "String.h"
#include "Text.h"
#include "ErrorCode.h"

void setUp(void){}

void tearDown(void){}

void test_s_operand1ExtractValue_should_mock_and_throw_error(void){
	int value;
	int e;
	
	Text *text = textNew("135");
	String *str = stringNew(text);
	
	extractValue_ExpectAndThrow(str, 2);
	
	Try{
		value = operand1ExtractValue(str);
	}Catch(e){
		TEST_ASSERT_EQUAL(ERR_ILLEGAL_ARGUMENT, e);
	}
	
}

void test_s_operand1ExtractValue_ERR_EMPTY_VALUE_should_mock_and_return_0(void){
	int value;
	int e;
	
	Text *text = textNew("135");
	String *str = stringNew(text);
	
	extractValue_ExpectAndThrow(str, 3);
	value = operand1ExtractValue(str);
	
	TEST_ASSERT_EQUAL(value, 0);
	
}

void test_s_operand1ExtractValue_ERR_NO_ARGUMENT_should_mock_and_return_0(void){
	int value;
	int e;
	
	Text *text = textNew("135");
	String *str = stringNew(text);
	
	extractValue_ExpectAndThrow(str, 4);
	value = operand1ExtractValue(str);
	
	TEST_ASSERT_EQUAL(value, 0);
	
}

void test_s_operand1ExtractValue_should_mock_and_return_1(void){
	int value;
	int e;
	
	Text *text = textNew("135");
	String *str = stringNew(text);
	
	extractValue_ExpectAndReturn(str, 0x11);
	value = operand1ExtractValue(str);
	
	TEST_ASSERT_EQUAL_HEX8(value, 0x11);
	
}

void test_s_operand1_0x11_should_mock_and_return_1(void){
	int value;
	int e;
	
	Text *text = textNew("135");
	String *str = stringNew(text);
	
	extractValue_ExpectAndReturn(str, 0x11);
	value = S(str);
	
	TEST_ASSERT_EQUAL_HEX8(value, 0x1);
	
}

void test_s_operand1_0xff_should_mock_and_return_1(void){
	int value;
	int e;
	
	Text *text = textNew("135");
	String *str = stringNew(text);
	
	extractValue_ExpectAndReturn(str, 0xff);
	value = S(str);
	
	TEST_ASSERT_EQUAL_HEX8(value, 0x1);
	
}

void test_s_operand1_0xffe_should_mock_and_return_0(void){
	int value;
	int e;
	
	Text *text = textNew("135");
	String *str = stringNew(text);
	
	extractValue_ExpectAndReturn(str, 0xffe);
	value = S(str);
	
	TEST_ASSERT_EQUAL_HEX8(value, 0x0);
	
}