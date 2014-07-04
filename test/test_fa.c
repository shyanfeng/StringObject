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

void test_fa_should_mock_and_return_123(void){
	int value;
	
	Text *text = textNew("123");
	String *str = stringNew(text);
	
	extractValue_ExpectAndReturn(str, 123);
	
	value = fa(str);
	
	TEST_ASSERT_EQUAL(123, value);
}

/*void test_fa_over_range_should_mock_and_throw_error(void){
	int value;
	int e;
	
	Text *text = textNew("333");
	String *str = stringNew(text);
	
	extractValue_ExpectAndReturn(str, 333);
	
	Try{
		value = fa(str);
	}Catch(e){
		TEST_ASSERT_EQUAL(ERR_OPERAND, e);
	}
	
}*/
