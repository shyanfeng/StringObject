#include "unity.h"
#include "mock_Evaluate.h"
#include "fsfd.h"
#include "CException.h"
#include "StringObject.h"
#include "String.h"
#include "Text.h"
#include "ErrorCode.h"

void setUp(void){}

void tearDown(void){}

void test_fsfd_operand1ExtractValue_ERR_EMPTY_VALUE_should_mock_and_throw_error(void){
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

void test_fsfd_operand1ExtractValue_should_mock_and_return_56(void){
	int value;
	
	Text *text = textNew("56");
	String *str = stringNew(text);
	
	extractValue_ExpectAndReturn(str, 0x56);
	value = operand1ExtractValue(str);

	TEST_ASSERT_EQUAL(value, 0x56);
}

void test_fsfd_operand2ExtractValue_ERR_EMPTY_VALUE_should_mock_and_throw_error(void){
	int value;
	int e;
	
	Text *text = textNew("");
	String *str = stringNew(text);
	
	extractValue_ExpectAndThrow(str, 3);
	
	Try{
		value = operand2ExtractValue(str);
	}Catch(e){
		TEST_ASSERT_EQUAL(ERR_EMPTY_VALUE, e);
		
	}
	
}

void test_fsfd_operand2ExtractValue_ERR_ILLEGAL_ARGUMENT_should_mock_and_throw_error(void){
	int value;
	int e;
	
	Text *text = textNew("");
	String *str = stringNew(text);
	
	extractValue_ExpectAndThrow(str, 2);
	
	Try{
		value = operand2ExtractValue(str);
	}Catch(e){
		TEST_ASSERT_EQUAL(ERR_ILLEGAL_ARGUMENT, e);
		
	}
	
}

void test_fsfd_operand2ExtractValue_ERR_NO_ARGUMENT_should_mock_and_throw_error(void){
	int value;
	int e;
	
	Text *text = textNew("");
	String *str = stringNew(text);
	
	extractValue_ExpectAndThrow(str, 4);
	
	Try{
		value = operand2ExtractValue(str);
	}Catch(e){
		TEST_ASSERT_EQUAL(ERR_NO_ARGUMENT, e);
		
	}
	
}

void test_fsfd_operand2ExtractValue_should_mock_and_return_71(void){
	int value;
	
	Text *text = textNew("71");
	String *str = stringNew(text);
	
	extractValue_ExpectAndReturn(str, 0x71);
	value = operand2ExtractValue(str);

	TEST_ASSERT_EQUAL(value, 0x71);
}

void test_fsfd_should_mock_and_move_to_operand2_0x00450071(void){
	int value;
	
	Text *text = textNew("71");
	String *str = stringNew(text);
	
	extractValue_ExpectAndReturn(str, 0x071);
	extractValue_ExpectAndReturn(str, 0x045);
	
	value = FSFD(str);
	
	TEST_ASSERT_EQUAL_HEX32(value, 0x00450071);
	
}

void test_fsfd_should_mock_and_move_to_operand2_0x02480154(void){
	int value;
	
	Text *text = textNew("71");
	String *str = stringNew(text);
	
	extractValue_ExpectAndReturn(str, 0x154);
	extractValue_ExpectAndReturn(str, 0x248);
	
	value = FSFD(str);
	
	TEST_ASSERT_EQUAL_HEX32(value, 0x02480154);
	
}

void test_fsfd_operand1_ERR_EMPTY_VALUE_should_mock_and_throw_error(void){
	int value;
	int e;
	
	Text *text = textNew("");
	String *str = stringNew(text);
	
	extractValue_ExpectAndThrow(str, 3);
	
	Try{
		value = FSFD(str);
	}Catch(e){
		TEST_ASSERT_EQUAL(ERR_EMPTY_VALUE, e);
		
	}
	
}

void test_fsfd_operand2_ERR_EMPTY_VALUE_should_mock_and_throw_error(void){
	int value;
	int e;
	
	Text *text = textNew("");
	String *str = stringNew(text);
	
	extractValue_ExpectAndThrow(str, 3);
	
	Try{
		value = FSFD(str);
	}Catch(e){
		TEST_ASSERT_EQUAL(ERR_EMPTY_VALUE, e);
		
	}
	
}

void test_fsfd_operand2_ERR_ILLEGAL_ARGUMENT_should_mock_and_throw_error(void){
	int value;
	int e;
	
	Text *text = textNew("");
	String *str = stringNew(text);
	
	extractValue_ExpectAndThrow(str, 2);
	
	Try{
		value = FSFD(str);
	}Catch(e){
		TEST_ASSERT_EQUAL(ERR_ILLEGAL_ARGUMENT, e);
		
	}
	
}

void test_fsfd_operand2_ERR_NO_ARGUMENT_should_mock_and_throw_error(void){
	int value;
	int e;
	
	Text *text = textNew("");
	String *str = stringNew(text);
	
	extractValue_ExpectAndThrow(str, 4);
	
	Try{
		value = FSFD(str);
	}Catch(e){
		TEST_ASSERT_EQUAL(ERR_NO_ARGUMENT, e);
		
	}
	
}
