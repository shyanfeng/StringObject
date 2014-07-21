#include "unity.h"
#include "mock_Extract.h"
#include "Extract1BitsAccessBanked.h"
#include "CException.h"
#include "StringObject.h"
#include "String.h"
#include "Text.h"
#include "ErrorCode.h"
#include "ExtractValue.h"

void setUp(void){}

void tearDown(void){}

void test_FA_extract1bitsACCESSBANKED_should_throw_error(void){
	int value;
	int e;
	
	Text *text = textNew("135");
	String *str = stringNew(text);
	
	extractACCESSBANKED_ExpectAndThrow(str, 2);

	Try{
		value = extract1bitsACCESSBANKED(str, 0x123);
	}Catch(e){
		TEST_ASSERT_EQUAL(ERR_ILLEGAL_ARGUMENT, e);
		
	}
}

void test_FA_extract1bitsACCESSBANKED_with_0_should_store_ACCESS(void){
	int value;
	int e;
	
	Text *text = textNew("135");
	String *str = stringNew(text);
	
	extractACCESSBANKED_ExpectAndReturn(str, 0);
	value = extract1bitsACCESSBANKED(str, 0x256);
	
	TEST_ASSERT_EQUAL(value, 0);
	
}

void test_FA_extract1bitsACCESSBANKED_with_1_should_store_BANKED(void){
	int value;
	int e;
	
	Text *text = textNew("135");
	String *str = stringNew(text);
	
	extractACCESSBANKED_ExpectAndReturn(str, 1);
	value = extract1bitsACCESSBANKED(str, 0x567);
	
	TEST_ASSERT_EQUAL(value, 1);
	
}

void test_FA_extract1bitsACCESSBANKED_with_ERR_EMPTY_ARGUMENT_between_0_and_80_should_store_ACCESS(void){
	int value;
	int e;
	
	Text *text = textNew("135");
	String *str = stringNew(text);
	
	extractACCESSBANKED_ExpectAndThrow(str, 3);
	value = extract1bitsACCESSBANKED(str, 0x12);
	
	TEST_ASSERT_EQUAL(value, 0);
	
}

void test_FA_extract1bitsACCESSBANKED_with_ERR_NO_ARGUMENT_should_store_ACCESS(void){
	int value;
	int e;
	
	Text *text = textNew("135");
	String *str = stringNew(text);
	
	extractACCESSBANKED_ExpectAndThrow(str, 4);
	value = extract1bitsACCESSBANKED(str, 0x79);
	
	TEST_ASSERT_EQUAL(value, 0);
	
}

void test_FA_extract1bitsACCESSBANKED_with_ERR_EMPTY_ARGUMENT_between_ff0_and_fff_should_store_ACCESS(void){
	int value;
	int e;
	
	Text *text = textNew("135");
	String *str = stringNew(text);
	
	extractACCESSBANKED_ExpectAndThrow(str, 3);
	value = extract1bitsACCESSBANKED(str, 0xff2);
	
	TEST_ASSERT_EQUAL(value, 0);
	
}

void test_FA_extract1bitsACCESSBANKED_with_ERR_NO_ARGUMENT_between_ff0_and_fff_should_store_ACCESS(void){
	int value;
	int e;
	
	Text *text = textNew("135");
	String *str = stringNew(text);
	
	extractACCESSBANKED_ExpectAndThrow(str, 4);
	value = extract1bitsACCESSBANKED(str, 0x79);
	
	TEST_ASSERT_EQUAL(value, 0);
	
}

void test_FA_extract1bitsACCESSBANKED_with_ERR_EMPTY_ARGUMENT_0x233_should_store_BANKED(void){
	int value;
	int e;
	
	Text *text = textNew("135");
	String *str = stringNew(text);
	
	extractACCESSBANKED_ExpectAndThrow(str, 3);
	value = extract1bitsACCESSBANKED(str, 0x233);
	
	TEST_ASSERT_EQUAL(value, 1);
	
}

void test_FA_extract1bitsACCESSBANKED_with_ERR_NO_ARGUMENT_0x753_should_store_BANKED(void){
	int value;
	int e;
	
	Text *text = textNew("135");
	String *str = stringNew(text);
	
	extractACCESSBANKED_ExpectAndThrow(str, 4);
	value = extract1bitsACCESSBANKED(str, 0x753);
	
	TEST_ASSERT_EQUAL(value, 1);
	
}