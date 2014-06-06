#include "unity.h"
#include "StringObject.h"

#define t (Text *)"\x00\x00\x00\x80"

typedef struct FakeText{
	uint32 reference;
	char string[80];
}FakeText;

void setUp(void){}

void tearDown(void){}

void test_stringDump_explore(void){
	FakeText fakeText = {
					.reference = 10,
					.string = "hello world!"
				};
	String str = {
					.reference = 20,
					.text = (Text *)&fakeText,
					.start = 2,
					.length = 100
				};
	stringDump(&str);
}

void test_textDump_explore(void){
	FakeText fakeText = {	.reference = 3,
							.string = "dummy"
						};
	textDump((Text *)&fakeText);

}

void test_textNew(void){
	Text *name;

	name = textNew("Ken Ken");
	textDump(name);
	
	TEST_ASSERT_EQUAL(0x01, name->reference);
}

void test_textAssign(void){
	Text *name1 = t"Yap Mun";
	Text *name2;
	Text *name3;
	printf("---name1---\n");
	textDump(name1);
	name2 = textNew("Ken Ken");
	printf("---name2---\n");
	textDump(name2);
	name3 = textAssign(name2);
	printf("---name3---\n");
	textDump(name3);
	
	TEST_ASSERT_EQUAL(0x80000000, name1->reference);
	TEST_ASSERT_EQUAL(0x02, name2->reference);
	TEST_ASSERT_EQUAL(0x02, name3->reference);
	TEST_ASSERT_EQUAL(name2->reference, name3->reference);
}

void test_textDel_dynamic_from_2_to_1(void){
	Text *name1 = t"Wing Jen";
	Text *name2;
	Text *name3;
	printf("---name1---\n");
	textDump(name1);
	name2 = textNew("Chong");
	printf("---name2---\n");
	textDump(name2);
	name3 = textAssign(name2);
	printf("---name3---\n");
	textDump(name3);
	name2 = textDel(name2);
	textDump(name2);
	textDump(name3);

	TEST_ASSERT_EQUAL(0x01 , name3->reference);

}

void test_textDel_name1_statistic_will_not_delete(void){
	Text *name1 = t"Wing Jen";
	Text *name2;
	Text *name3;
	printf("---name1---\n");
	textDump(name1);
	name2 = textNew("Chong");
	printf("---name2---\n");
	textDump(name2);
	name3 = textAssign(name2);
	printf("---name3---\n");
	textDump(name3);
	name2 = textDel(name2);
	textDump(name2);
	textDump(name3);
	name3 = textDel(name3);
	textDump(name3);
	printf("----------\n");
	name1 = textDel(name1);
	textDump(name1);
	
	TEST_ASSERT_EQUAL(0x80000000, name1->reference);
	TEST_ASSERT_NULL(name3);

}

void test_stringNew(void){
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

void test_stringRemoveWordNotContaining_should_remove_dragon_from_dragonball_and_become_ball(void){

	String *str = stringNew(textNew("dragonball"));
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

void test_stringRemoveWordContainings_should_remove_ku_from_goku_and_become_go(void){

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

}

void test_stringIsEqual_have_same_characters_should_return_1(void){
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
	
	TEST_ASSERT_EQUAL(1, a);
	TEST_ASSERT_EQUAL(4, str->length);
}

/*void test_stringIsEqual_dont_have_the_same_characters_should_return_0(void){
	char a;
	
	String *str = stringNew(textNew("library"));
	stringDump(str);
	String *str2 = stringNew(textNew("canteen"));
	stringDump(str2);
	a = stringIsEqual(str, str2);
	
	TEST_ASSERT_EQUAL(0, a);
}*/

/*void test_stringIsEqualCaseInSensitve(void){

}*/
