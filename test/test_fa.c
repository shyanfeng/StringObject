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

/*void test_fa_should_mock_and_return_132(void){
	int value;
	
	Text *text = textNew("132");
	String *str = stringNew(text);
	
	extractValue_ExpectAndReturn(str, 0x132);
	extractValue_ExpectAndThrow(str, 0);
	fa(str);
	
	extractValue_ExpectAndReturn(str, 0x132);
	value = fa(str);

	TEST_ASSERT_EQUAL(value, 0x132);
}*/
