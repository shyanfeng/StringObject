#include "unity.h"
#include "StringObject.h"
#include "Text.h"

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