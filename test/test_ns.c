#include "unity.h"
#include "mock_Evaluate.h"
#include "ns.h"
#include "CException.h"
#include "StringObject.h"
#include "String.h"
#include "Text.h"
#include "ErrorCode.h"

void setUp(void){}

void tearDown(void){}

void test_NS_operand1ExtractValue_ERR_EMPTY_VALUE_should_throw_error(void){
	int value;
	int e;
	
	Text *text = textNew("135");
	String *str = stringNew(text);
	
	extractValue_ExpectAndThrow(str, 3);
	
	Try{
		value = operand1ExtractValue(str);
	}Catch(e){
		TEST_ASSERT_EQUAL(ERR_EMPTY_VALUE, e);
	}
	
}

void test_NS_operand1ExtractValue_0x32_should_mock_and_return_0x32(void){
	int value;
	int e;
	
	Text *text = textNew("135");
	String *str = stringNew(text);
	
	extractValue_ExpectAndReturn(str, 0x32);

	value = operand1ExtractValue(str);
	
	TEST_ASSERT_EQUAL(value, 0x32);
	
}

void test_NS_operand2ExtractValue_should_mock_and_throw_error(void){
	int value;
	int e;
	
	Text *text = textNew("135");
	String *str = stringNew(text);
	
	extractValue_ExpectAndThrow(str, 2);
	
	Try{
		value = operand2ExtractValue(str);
	}Catch(e){
		TEST_ASSERT_EQUAL(ERR_ILLEGAL_ARGUMENT, e);
	}
	
}

void test_NS_operand2ExtractValue_ERR_EMPTY_VALUE_should_mock_and_return_0(void){
	int value;
	int e;
	
	Text *text = textNew("135");
	String *str = stringNew(text);
	
	extractValue_ExpectAndThrow(str, 3);
	value = operand2ExtractValue(str);
	
	TEST_ASSERT_EQUAL(value, 0);
	
}

void test_NS_operand2ExtractValue_ERR_NO_ARGUMENT_should_mock_and_return_0(void){
	int value;
	int e;
	
	Text *text = textNew("135");
	String *str = stringNew(text);
	
	extractValue_ExpectAndThrow(str, 4);
	value = operand2ExtractValue(str);
	
	TEST_ASSERT_EQUAL(value, 0);
	
}

void test_NS_operand2ExtractValue_should_mock_and_return_1(void){
	int value;
	int e;
	
	Text *text = textNew("135");
	String *str = stringNew(text);
	
	extractValue_ExpectAndReturn(str, 0x31);
	value = operand2ExtractValue(str);
	
	TEST_ASSERT_EQUAL_HEX8(value, 1);
	
}

void test_NS_operand1_should_mock_and_return_0x00440144(void){
	int value;
	int e;
	
	Text *text = textNew("135");
	String *str = stringNew(text);
	
	extractValue_ExpectAndReturn(str, 0x44);
	extractValue_ExpectAndReturn(str, 1);
	
	value = NS(str);
	printf("%x", value);
	TEST_ASSERT_EQUAL_HEX32(value, 0x00440144);

}

void test_NS_operand1_should_mock_and_return_0x00670067(void){
	int value;
	int e;
	
	Text *text = textNew("135");
	String *str = stringNew(text);
	
	extractValue_ExpectAndReturn(str, 0x67);
	extractValue_ExpectAndReturn(str, 0);
	
	value = NS(str);
	printf("%x", value);
	TEST_ASSERT_EQUAL_HEX32(value, 0x00670067);

}

void test_NS_operand1_should_mock_and_return_0x02670067(void){
	int value;
	int e;
	
	Text *text = textNew("135");
	String *str = stringNew(text);
	
	extractValue_ExpectAndReturn(str, 0x267);
	extractValue_ExpectAndReturn(str, 0);
	
	value = NS(str);
	printf("%x", value);
	TEST_ASSERT_EQUAL_HEX32(value, 0x02670067);

}

void test_NS_operand1_ERR_EMPTY_VALUE_should_throw_error(void){
	int value;
	int e;
	
	Text *text = textNew("135");
	String *str = stringNew(text);
	
	extractValue_ExpectAndThrow(str, 3);
	
	Try{
		value = NS(str);
	}Catch(e){
		TEST_ASSERT_EQUAL(ERR_EMPTY_VALUE, e);
	}
	
}

void test_NS_operand2_should_mock_and_throw_error(void){
	int value;
	int e;
	
	Text *text = textNew("135");
	String *str = stringNew(text);
	
	extractValue_ExpectAndThrow(str, 2);
	
	Try{
		value = operand2ExtractValue(str);
	}Catch(e){
		TEST_ASSERT_EQUAL(ERR_ILLEGAL_ARGUMENT, e);
	}
	
}