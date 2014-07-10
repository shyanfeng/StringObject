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

/*void test_fa_should_mock_and_return_123(void){
	int value;
	
	Text *text = textNew("123");
	String *str = stringNew(text);
	
	extractValue_ExpectAndThrow(str, 0);
	
	value = fa(str);
	extractValue_ExpectAndReturn(str, 123);

	TEST_ASSERT_EQUAL(123, value);
}*/

/*void test_fa_should_mock_and_return_456(void){
	int value;
	
	Text *text = textNew("456");
	String *str = stringNew(text);
	
	extractValue_ExpectAndThrow(str, 0);
	
	value = fa(str);
	extractValue_ExpectAndReturn(str, 456);

	TEST_ASSERT_EQUAL(456, value);
}*/

void test_fa_over_range_should_mock_and_throw_error(void){
	int value;
	int e;
	
	Text *text = textNew("");
	String *str = stringNew(text);
	
	extractValue_ExpectAndThrow(str, 1);
	
	Try{
		value = fa(str);
	}Catch(e){
		TEST_ASSERT_EQUAL(ERR_EMPTY_VALUE, e);
		
	}
	
}

void test_fa_should_store_value_132_into_ACCESS(void){
	int value;
	
	Text *text = textNew("132");
	String *str = stringNew(text);
	
	extractValue_ExpectAndThrow(str, 0);
	extractAccessBanked_ExpectAndThrow(str, 0);
	value = fa(str);
	
	extractValue_ExpectAndReturn(str, 132);
	extractAccessBanked_ExpectAndReturn(str, 0);
	value = fa(str);

	//TEST_ASSERT_EQUAL(123, value);
}
