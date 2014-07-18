#include "unity.h"
#include "mock_Evaluate.h"
#include "FA.h"
#include "CException.h"
#include "StringObject.h"
#include "String.h"
#include "Text.h"
#include "ErrorCode.h"

void setUp(void){}

void tearDown(void){}

void test_FA_operand1ExtractValue_ERR_EMPTY_VALUE_should_mock_and_throw_error(void){
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

void test_FA_operand1ExtractValue_should_mock_and_return_35(void){
	int value;
	
	Text *text = textNew("35");
	String *str = stringNew(text);
	
	extractValue_ExpectAndReturn(str, 0x35);
	value = operand1ExtractValue(str);

	TEST_ASSERT_EQUAL(value, 0x35);
}

void test_FA_operand2ExtractAccessBanked_should_throw_error(void){
	int value;
	int e;
	
	Text *text = textNew("135");
	String *str = stringNew(text);
	
	extractAccessBanked_ExpectAndThrow(str, 2);

	Try{
		value = operand2ExtractAccessBanked(str, 0x123);
	}Catch(e){
		TEST_ASSERT_EQUAL(ERR_ILLEGAL_ARGUMENT, e);
		
	}
}

void test_FA_operand2ExtractAccessBanked_with_0_should_store_ACCESS(void){
	int value;
	int e;
	
	Text *text = textNew("135");
	String *str = stringNew(text);
	
	extractAccessBanked_ExpectAndReturn(str, 0);
	value = operand2ExtractAccessBanked(str, 0x256);
	
	TEST_ASSERT_EQUAL(value, 0);
	
}

void test_FA_operand2ExtractAccessBanked_with_1_should_store_BANKED(void){
	int value;
	int e;
	
	Text *text = textNew("135");
	String *str = stringNew(text);
	
	extractAccessBanked_ExpectAndReturn(str, 1);
	value = operand2ExtractAccessBanked(str, 0x567);
	
	TEST_ASSERT_EQUAL(value, 1);
	
}

void test_FA_operand2ExtractAccessBanked_with_ERR_EMPTY_VALUE_between_0_and_80_should_store_ACCESS(void){
	int value;
	int e;
	
	Text *text = textNew("135");
	String *str = stringNew(text);
	
	extractAccessBanked_ExpectAndThrow(str, 3);
	value = operand2ExtractAccessBanked(str, 0x12);
	
	TEST_ASSERT_EQUAL(value, 0);
	
}

void test_FA_operand2ExtractAccessBanked_with_ERR_NO_ARGUMENT_should_store_ACCESS(void){
	int value;
	int e;
	
	Text *text = textNew("135");
	String *str = stringNew(text);
	
	extractAccessBanked_ExpectAndThrow(str, 4);
	value = operand2ExtractAccessBanked(str, 0x79);
	
	TEST_ASSERT_EQUAL(value, 0);
	
}

void test_FA_operand2ExtractAccessBanked_with_ERR_EMPTY_VALUE_between_ff0_and_fff_should_store_ACCESS(void){
	int value;
	int e;
	
	Text *text = textNew("135");
	String *str = stringNew(text);
	
	extractAccessBanked_ExpectAndThrow(str, 3);
	value = operand2ExtractAccessBanked(str, 0xff2);
	
	TEST_ASSERT_EQUAL(value, 0);
	
}

void test_FA_operand2ExtractAccessBanked_with_ERR_NO_ARGUMENT_between_ff0_and_fff_should_store_ACCESS(void){
	int value;
	int e;
	
	Text *text = textNew("135");
	String *str = stringNew(text);
	
	extractAccessBanked_ExpectAndThrow(str, 4);
	value = operand2ExtractAccessBanked(str, 0x79);
	
	TEST_ASSERT_EQUAL(value, 0);
	
}

void test_FA_operand2ExtractAccessBanked_with_ERR_EMPTY_VALUE_0x233_should_store_BANKED(void){
	int value;
	int e;
	
	Text *text = textNew("135");
	String *str = stringNew(text);
	
	extractAccessBanked_ExpectAndThrow(str, 3);
	value = operand2ExtractAccessBanked(str, 0x233);
	
	TEST_ASSERT_EQUAL(value, 1);
	
}

void test_FA_operand2ExtractAccessBanked_with_ERR_NO_ARGUMENT_0x753_should_store_BANKED(void){
	int value;
	int e;
	
	Text *text = textNew("135");
	String *str = stringNew(text);
	
	extractAccessBanked_ExpectAndThrow(str, 4);
	value = operand2ExtractAccessBanked(str, 0x753);
	
	TEST_ASSERT_EQUAL(value, 1);
	
}

void test_FA_should_return_0x35_and_store_in_ACCESS(void){
	int value;
	int e;
	
	Text *text = textNew("135");
	String *str = stringNew(text);
	
	extractValue_ExpectAndReturn(str, 0x35);
	extractAccessBanked_ExpectAndReturn(str, 0);
	
	value = FA(str);

	TEST_ASSERT_EQUAL_HEX16(value, 0x035);
}

void test_FA_should_return_0x34_and_store_in_BANKED(void){
	int value;
	int e;
	
	Text *text = textNew("135");
	String *str = stringNew(text);
	
	extractValue_ExpectAndReturn(str, 0x134);
	extractAccessBanked_ExpectAndReturn(str, 1);
	
	value = FA(str);

	TEST_ASSERT_EQUAL_HEX16(value, 0x134);
}

void test_FA_with_ERR_EMPTY_VALUE_0x40_should_return_0x40_and_store_in_ACCESS(void){
	int value;
	int e;
	
	Text *text = textNew("135");
	String *str = stringNew(text);
	
	extractValue_ExpectAndReturn(str, 0x40);
	extractAccessBanked_ExpectAndThrow(str, 3);
	
	value = FA(str);

	TEST_ASSERT_EQUAL_HEX16(value, 0x40);
}

void test_FA_with_ERR_NO_ARGUMENT_0xff6_should_return_0xf6_and_store_in_ACCESS(void){
	int value;
	int e;
	
	Text *text = textNew("135");
	String *str = stringNew(text);
	
	extractValue_ExpectAndReturn(str, 0xff6);
	extractAccessBanked_ExpectAndThrow(str, 4);
	
	value = FA(str);

	TEST_ASSERT_EQUAL_HEX16(value, 0xf6);
}

void test_FA_operand1_empty_value_should_mock_and_throw_error(void){
	int value;
	int e;
	
	Text *text = textNew("135");
	String *str = stringNew(text);
	
	extractValue_ExpectAndThrow(str, 3);
	
	Try{
		value = FA(str);
	}Catch(e){
		TEST_ASSERT_EQUAL(ERR_EMPTY_VALUE, e);
		
	}
}

void test_FA_operand2_ERR_ILLEGAL_ARGUMENT_should_mock_and_throw_error(void){
	int value;
	int e;
	
	Text *text = textNew("135");
	String *str = stringNew(text);
	
	extractValue_ExpectAndReturn(str, 0x35);
	extractAccessBanked_ExpectAndThrow(str, 2);
	
	Try{
		value = FA(str);
	}Catch(e){
		TEST_ASSERT_EQUAL(ERR_ILLEGAL_ARGUMENT, e);
		
	}
}
