#include "unity.h"
#include "StringObject.h"
#include "Text.h"

typedef struct FakeText{
	uint32 reference;
	char string[80];
}FakeText;

void setUp(void){}

void tearDown(void){}

void test_stringNew_dynamic(void){
	Text *new = textNew("Benson");
	textDump(new);
	String *string = stringNew(new);
	stringDump(string);
	
	TEST_ASSERT_EQUAL(0x01, string->reference);
	TEST_ASSERT_EQUAL(0x02, new->reference);
}

void test_stringAssign(void){
	Text *new = textNew("SonJa");
	textDump(new);
	String *string1 = stringNew(new);
	
	String *string2 = stringAssign(string1);
	stringDump(string1);
	stringDump(string2);
	
	TEST_ASSERT_EQUAL(0x02, string2->reference);
	TEST_ASSERT_EQUAL(0x02, string1->reference);
	TEST_ASSERT_EQUAL(0x02, new->reference);
}

void test_stringDel_from_2_to_1(void){
	Text *new = textNew("FattSoo");
	textDump(new);
	String *string1 = stringNew(new);
	stringDump(string1);
	String *string2 = stringAssign(string1);
	stringDump(string2);
	string1 = stringDel(string1);
	stringDump(string1);
	
	TEST_ASSERT_EQUAL(0x01, string1->reference);

}

void test_stringDel_from_1_to_NULL(void){
	Text *new = textNew("CheeLiang");
	textDump(new);
	String *string1 = stringNew(new);
	stringDump(string1);
	String *string2 = stringAssign(string1);
	stringDump(string2);
	string1 = stringDel(string1);
	stringDump(string1);
	printf("try to free\n");
	string2 = stringDel(string2);
	stringDump(string2);
	
	TEST_ASSERT_NULL(string2);
}

void test_stringSkip_should_skip_from_HELLO_to_LLO(void){
	String *str = stringNew(t"HELLO");
	stringSkip(str, 2);
	stringDump(str);
	
	TEST_ASSERT_EQUAL(2, str->start);
	TEST_ASSERT_EQUAL(3, str->length);
}

void test_stringTrimLeft_should_remove_the_2_spaces_on_left(void){
	String *str = stringNew(textNew("  HELLO"));
	stringTrimLeft(str);
	stringDump(str);
	
	TEST_ASSERT_EQUAL(2, str->start);
	TEST_ASSERT_EQUAL(7, str->length);

}

void test_stringTrimLeft_should_remove_the_2_spaces_and_tab_on_left(void){
	String *str = stringNew(textNew("  \tHELLO"));
	stringTrimLeft(str);
	stringDump(str);
	
	TEST_ASSERT_EQUAL(3, str->start);
	TEST_ASSERT_EQUAL(8, str->length);

}

void test_stringTrimRight_should_remove_the_2_spaces_on_right(void){
	String *str = stringNew(textNew("HELLO  "));
	stringTrimRight(str);
	stringDump(str);
	
	TEST_ASSERT_EQUAL(0, str->start);
	TEST_ASSERT_EQUAL(5, str->length);

}

void test_stringTrimRight_should_remove_the_2_spaces_and_tab_on_right(void){
	String *str = stringNew(textNew("HELLO  \t"));
	stringTrimRight(str);
	stringDump(str);
	
	TEST_ASSERT_EQUAL(0, str->start);
	TEST_ASSERT_EQUAL(5, str->length);

}

void test_stringTrim_should_remove_the_2_spaces_on_left_and_2_spaces_on_right(void){
	String *str = stringNew(textNew("  HELLO  "));
	stringTrim(str);
	stringDump(str);
	
	TEST_ASSERT_EQUAL(2, str->start);
	TEST_ASSERT_EQUAL(9, str->length);

}

void test_stringTrim_should_remove_the_2_spaces_and_tab_on_left_and_2_spaces_and_tab_on_right(void){
	String *str = stringNew(textNew("\t  HELLO  \t"));
	stringTrim(str);
	stringDump(str);
	
	TEST_ASSERT_EQUAL(3, str->start);
	TEST_ASSERT_EQUAL(11, str->length);

}

void test_stringRemoveChar_should_remove_s_from_samsung_and_become_amsung(void){

	String *str = stringNew(textNew("samsung"));
	stringDump(str);
	stringRemoveChar(str);
	stringDump(str);
	
	TEST_ASSERT_EQUAL('a', str->text->string[str->start]);
	TEST_ASSERT_EQUAL(6, str->length);

}

void test_stringRemoveChar_should_remove_ap_from_apple_and_become_ple(void){
	
	String *str = stringNew(textNew("apple"));
	stringDump(str);
	stringRemoveChar(str);
	stringRemoveChar(str);
	stringDump(str);
	
	TEST_ASSERT_EQUAL('p', str->text->string[str->start]);
	TEST_ASSERT_EQUAL(3, str->length);

}

void test_stringRemoveChar_should_return_negative_1_when_nothing_to_remove(void){
	char a;
	
	String *str = stringNew(textNew("abc"));
	stringDump(str);
	stringRemoveChar(str);
	stringRemoveChar(str);
	stringRemoveChar(str);
	a = stringRemoveChar(str);
	stringDump(str);
	
	TEST_ASSERT_EQUAL(-1, a);
	
}

void test_stringLength_should_return_length_of_string(void){
	char a;
	
	String *str = stringNew(textNew("Xiaomi3"));
	stringDump(str);
	a = stringLength(str);
	stringDump(str);

	TEST_ASSERT_EQUAL(7, a);

}

void test_stringRemoveWordNotContaining_should_remove_dragon_from_dregonball_and_become_ball(void){

	String *str = stringNew(textNew("dregonball"));
	stringDump(str);
	String *str2 = stringRemoveWordNotContaining(str, "ball");
	stringDump(str2);
	
	TEST_ASSERT_EQUAL('d', str2->text->string[str2->start]);
	TEST_ASSERT_EQUAL(0, str2->start);
	TEST_ASSERT_EQUAL(6, str2->length);
	TEST_ASSERT_EQUAL('b', str->text->string[str->start]);
	TEST_ASSERT_EQUAL(6, str->start);
	TEST_ASSERT_EQUAL(4, str->length);

}

void test_stringRemoveWordNotContaining_should_from_askinRobbi_become_aski(void){
	Text *name = t"BaskinRobbin";
	textDump(name);
	String *str = stringNew(name);
	stringDump(str);
	str->start++;
	str->length--;
	String *str2 = stringRemoveWordNotContaining(str, "onb");
	stringDump(str2);
	stringDump(str);
	
	TEST_ASSERT_EQUAL('a', str2->text->string[str2->start]);
	TEST_ASSERT_EQUAL(1, str2->start);
	TEST_ASSERT_EQUAL(4, str2->length);
	TEST_ASSERT_EQUAL('n', str->text->string[str->start]);
	TEST_ASSERT_EQUAL(5, str->start);
	TEST_ASSERT_EQUAL(6, str->length);
	
}

void test_stringRemoveWordNotContaining_static_should_remove_dog_and_become_Bull(void){
	
	Text *name = t"Bulldog";
	textDump(name);
	String *str = stringNew(name);
	stringDump(str);
	String *str2 = stringRemoveWordNotContaining(str, "gd");
	stringDump(str2);
	stringDump(str);
	
	TEST_ASSERT_EQUAL('d', str->text->string[str->start]);
	TEST_ASSERT_EQUAL(4, str->start);
	TEST_ASSERT_EQUAL(3, str->length);
	TEST_ASSERT_EQUAL('B', str2->text->string[str2->start]);
	TEST_ASSERT_EQUAL(0, str2->start);
	TEST_ASSERT_EQUAL(4, str2->length);

}

/*void test_stringRemoveWordContainings_should_remove_ku_from_goku_and_become_go(void){

	String *str = stringNew(textNew("goku"));
	stringDump(str);
	String *str2 = stringRemoveWordContaining(str, "go");
	stringDump(str2);

	TEST_ASSERT_EQUAL('g', str2->text->string[str2->start]);
	TEST_ASSERT_EQUAL(0, str2->start);
	TEST_ASSERT_EQUAL(2, str2->length);
	TEST_ASSERT_EQUAL('k', str->text->string[str->start]);
	TEST_ASSERT_EQUAL(2, str->start);
	TEST_ASSERT_EQUAL(2, str->length);

}*/

void test_stringRemoveWordContainings_should_remove_lo_from_halo_and_become_ha_with_ah(void){

	String *str = stringNew(textNew("123halo"));
	stringDump(str);
	String *str2 = stringRemoveWordContaining(str, "321");
	stringDump(str2);

	

}

void test_stringIsEqual_dont_have_same_characters_should_return_0(void){
	char a;
	
	String *str = stringNew(textNew("pikolo"));
	stringDump(str);
	String *str2 = stringNew(textNew("koli"));
	stringDump(str2);
	str->start += 2;
	str->length -= 2;
	a = stringIsEqual(str, str2);
	stringDump(str);
	stringDump(str2);
	
	TEST_ASSERT_EQUAL(0, a);
	TEST_ASSERT_EQUAL(4, str->length);
}

void test_stringIsEqual_have_the_same_characters_should_return_1(void){
	char a;
	
	String *str = stringNew(textNew("library"));
	stringDump(str);
	String *str2 = stringNew(textNew("mylibrary"));
	stringDump(str2);
	str2->start += 2;
	str2->length -= 2;
	a = stringIsEqual(str, str2);
	stringDump(str);
	stringDump(str2);
	
	TEST_ASSERT_EQUAL(1, a);
	TEST_ASSERT_EQUAL(7, str->length);
}

void test_stringIsEqual_dynamic_should_return_1(void){
	char a;
	

	String *str = stringNew(textNew("pineapple"));
	stringDump(str);
	String *str2 = stringNew(textNew("pineapple"));
	stringDump(str2);
	a = stringIsEqual(str, str2);
	stringDump(str);
	stringDump(str2);
	
	TEST_ASSERT_EQUAL(1, a);
	TEST_ASSERT_EQUAL(9, str->length);
}

void test_stringIsEqual_static_should_return_1(void){
	char a;
	
	Text *name = t"apple";
	textDump(name);
	String *string = stringNew(name);
	stringDump(string);
	Text *name2 = t"apple";
	textDump(name2);
	String *string2 = stringNew(name2);
	stringDump(string2);
	a = stringIsEqual(string, string2);
	stringDump(string);
	stringDump(string2);
	
	TEST_ASSERT_EQUAL(1, a);
	TEST_ASSERT_EQUAL(5, string->length);
}

void test_stringIsEqualCaseInSensitve_have_same_characters_of_str_and_str2_should_become_lower_case_and_return_1(void){
	char a;
	
	String *str = stringNew(textNew("CanTEEn"));
	stringDump(str);
	String *str2 = stringNew(textNew("cAnTeEN"));
	stringDump(str2);
	a = stringIsEqualCaseInSensitve(str, str2);
	stringDump(str);
	stringDump(str2);
	
	TEST_ASSERT_EQUAL(1, a);
	TEST_ASSERT_EQUAL(7, str->length);
	
}

void test_stringIsEqualCaseInSensitve_dont_have_same_characters_of_str_and_str2_should_return_1(void){
	char a;
	
	String *str = stringNew(textNew("rEDbRicks"));
	stringDump(str);
	String *str2 = stringNew(textNew("CafeTeriA"));
	stringDump(str2);
	a = stringIsEqualCaseInSensitve(str, str2);
	stringDump(str);
	stringDump(str2);
	
	TEST_ASSERT_EQUAL(0, a);
	
}

void test_stringChatAt_in_range_should_return_l_from_hello(void){
	char a;
	
	String *str = stringNew(textNew("Hello"));
	str->start = 1;
	a = stringCharAt(str, 2);

	TEST_ASSERT_EQUAL('l', a);

}

void test_stringChatAt_not_in_range_should_return_negative_1(void){
	char a;
	
	String *str = stringNew(textNew("Hello"));
	str->start = 1;
	a = stringCharAt(str, 5);

	TEST_ASSERT_EQUAL(-1, a);

}

void test_stringChatAt_is_negative_1_should_return_negative_1(void){
	char a;
	
	String *str = stringNew(textNew("Hello"));
	str->start = 1;
	a = stringCharAt(str, -1);

	TEST_ASSERT_EQUAL(-1, a);

}

void test_stringCharAtInSet_should_return_0_when_InSet_does_not_match_any_character_with_str(void){
	char a;
	
	String *str = stringNew(textNew("abcdefgh"));
	str->start = 2;
	a = stringCharAtInSet(str, 2, "gyjfjk");
	
	TEST_ASSERT_EQUAL(0, a);

}

void test_stringCharAtInSet_should_return_1_when_InSet_match_an_character_with_str(void){
	char a;
	
	String *str = stringNew(textNew("abcdefgh"));
	str->start = 2;
	a = stringCharAtInSet(str, 2, "polze");
	
	TEST_ASSERT_EQUAL(1, a);

}


