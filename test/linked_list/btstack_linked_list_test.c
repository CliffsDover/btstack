#include "CppUTest/TestHarness.h"
#include "CppUTest/CommandLineTestRunner.h"
#include "btstack_linked_list.h"

btstack_linked_list_t testList;
btstack_linked_item_t itemA;
btstack_linked_item_t itemB;
btstack_linked_item_t itemC;
btstack_linked_item_t itemD;

TEST_GROUP(LinkedList){
    void setup(void){
        testList = NULL;
        btstack_linked_list_add(&testList, &itemD);
        btstack_linked_list_add(&testList, &itemC);
        btstack_linked_list_add(&testList, &itemB);
        btstack_linked_list_add(&testList, &itemA);
    }
};

TEST(LinkedList, Iterator){
    btstack_linked_list_iterator_t it;
    btstack_linked_list_iterator_init(&it, &testList);
    btstack_linked_item_t * item;
    CHECK(btstack_linked_list_iterator_has_next(&it));
    item = btstack_linked_list_iterator_next(&it);
    CHECK_EQUAL(item, &itemA);
    CHECK(btstack_linked_list_iterator_has_next(&it));
    item = btstack_linked_list_iterator_next(&it);
    CHECK_EQUAL(item, &itemB);
    CHECK(btstack_linked_list_iterator_has_next(&it));
    item = btstack_linked_list_iterator_next(&it);
    CHECK_EQUAL(item, &itemC);
    CHECK(btstack_linked_list_iterator_has_next(&it));
    item = btstack_linked_list_iterator_next(&it);
    CHECK_EQUAL(item, &itemD);
    CHECK(!btstack_linked_list_iterator_has_next(&it));
}

TEST(LinkedList, RemoveFirstUsingIterator){
    btstack_linked_list_iterator_t it;
    btstack_linked_list_iterator_init(&it, &testList);
    btstack_linked_item_t * item;
    CHECK(btstack_linked_list_iterator_has_next(&it));
    item = btstack_linked_list_iterator_next(&it);
    CHECK_EQUAL(item, &itemA);
    btstack_linked_list_iterator_remove(&it);
    CHECK(btstack_linked_list_iterator_has_next(&it));
    item = btstack_linked_list_iterator_next(&it);
    CHECK_EQUAL(item, &itemB);
    CHECK(btstack_linked_list_iterator_has_next(&it));
    item = btstack_linked_list_iterator_next(&it);
    CHECK_EQUAL(item, &itemC);
    CHECK(btstack_linked_list_iterator_has_next(&it));
    item = btstack_linked_list_iterator_next(&it);
    CHECK_EQUAL(item, &itemD);
    CHECK(!btstack_linked_list_iterator_has_next(&it));
}

TEST(LinkedList, RemoveFirstUsingListRemove){
    btstack_linked_list_iterator_t it;
    btstack_linked_list_iterator_init(&it, &testList);
    btstack_linked_item_t * item;
    CHECK(btstack_linked_list_iterator_has_next(&it));
    item = btstack_linked_list_iterator_next(&it);
    CHECK_EQUAL(item, &itemA);
    btstack_linked_list_remove(&testList, &itemA);
    CHECK(btstack_linked_list_iterator_has_next(&it));
    item = btstack_linked_list_iterator_next(&it);
    CHECK_EQUAL(item, &itemB);
    CHECK(btstack_linked_list_iterator_has_next(&it));
    item = btstack_linked_list_iterator_next(&it);
    CHECK_EQUAL(item, &itemC);
    CHECK(btstack_linked_list_iterator_has_next(&it));
    item = btstack_linked_list_iterator_next(&it);
    CHECK_EQUAL(item, &itemD);
    CHECK(!btstack_linked_list_iterator_has_next(&it));
}

TEST(LinkedList, RemoveSecondUsingIterator){
    btstack_linked_list_iterator_t it;
    btstack_linked_list_iterator_init(&it, &testList);
    btstack_linked_item_t * item;
    CHECK(btstack_linked_list_iterator_has_next(&it));
    item = btstack_linked_list_iterator_next(&it);
    CHECK(btstack_linked_list_iterator_has_next(&it));
    item = btstack_linked_list_iterator_next(&it);
    CHECK_EQUAL(item, &itemB);
    btstack_linked_list_iterator_remove(&it);
    CHECK(btstack_linked_list_iterator_has_next(&it));
    item = btstack_linked_list_iterator_next(&it);
    CHECK_EQUAL(item, &itemC);
    CHECK(btstack_linked_list_iterator_has_next(&it));
    item = btstack_linked_list_iterator_next(&it);
    CHECK_EQUAL(item, &itemD);
    CHECK(!btstack_linked_list_iterator_has_next(&it));
}

TEST(LinkedList, RemoveSecondUsingListRemove){
    btstack_linked_list_iterator_t it;
    btstack_linked_list_iterator_init(&it, &testList);
    btstack_linked_item_t * item;
    CHECK(btstack_linked_list_iterator_has_next(&it));
    item = btstack_linked_list_iterator_next(&it);
    CHECK(btstack_linked_list_iterator_has_next(&it));
    item = btstack_linked_list_iterator_next(&it);
    CHECK_EQUAL(item, &itemB);
    btstack_linked_list_remove(&testList, &itemB);
    item = btstack_linked_list_iterator_next(&it);
    CHECK_EQUAL(item, &itemC);
    CHECK(btstack_linked_list_iterator_has_next(&it));
    item = btstack_linked_list_iterator_next(&it);
    CHECK_EQUAL(item, &itemD);
    CHECK(!btstack_linked_list_iterator_has_next(&it));
}

TEST(LinkedList, RemoveThirdUsingIterator){
    btstack_linked_list_iterator_t it;
    btstack_linked_list_iterator_init(&it, &testList);
    btstack_linked_item_t * item;
    CHECK(btstack_linked_list_iterator_has_next(&it));
    item = btstack_linked_list_iterator_next(&it);
    CHECK(btstack_linked_list_iterator_has_next(&it));
    item = btstack_linked_list_iterator_next(&it);
    CHECK_EQUAL(item, &itemB);
    CHECK(btstack_linked_list_iterator_has_next(&it));
    item = btstack_linked_list_iterator_next(&it);
    CHECK_EQUAL(item, &itemC);
    btstack_linked_list_iterator_remove(&it);
    CHECK(btstack_linked_list_iterator_has_next(&it));
    item = btstack_linked_list_iterator_next(&it);
    CHECK_EQUAL(item, &itemD);
    CHECK(!btstack_linked_list_iterator_has_next(&it));
}

TEST(LinkedList, RemoveLastUsingIterator){
    btstack_linked_list_iterator_t it;
    btstack_linked_list_iterator_init(&it, &testList);
    btstack_linked_item_t * item;
    CHECK(btstack_linked_list_iterator_has_next(&it));
    item = btstack_linked_list_iterator_next(&it);
    CHECK(btstack_linked_list_iterator_has_next(&it));
    item = btstack_linked_list_iterator_next(&it);
    CHECK_EQUAL(item, &itemB);
    CHECK(btstack_linked_list_iterator_has_next(&it));
    item = btstack_linked_list_iterator_next(&it);
    CHECK_EQUAL(item, &itemC);
    CHECK(btstack_linked_list_iterator_has_next(&it));
    item = btstack_linked_list_iterator_next(&it);
    CHECK_EQUAL(item, &itemD);
    btstack_linked_list_iterator_remove(&it);
    CHECK(!btstack_linked_list_iterator_has_next(&it));
}

TEST(LinkedList, RemoveLastUsingListRemove){
    btstack_linked_list_iterator_t it;
    btstack_linked_list_iterator_init(&it, &testList);
    btstack_linked_item_t * item;
    CHECK(btstack_linked_list_iterator_has_next(&it));
    item = btstack_linked_list_iterator_next(&it);
    CHECK(btstack_linked_list_iterator_has_next(&it));
    item = btstack_linked_list_iterator_next(&it);
    CHECK_EQUAL(item, &itemB);
    CHECK(btstack_linked_list_iterator_has_next(&it));
    item = btstack_linked_list_iterator_next(&it);
    CHECK_EQUAL(item, &itemC);
    CHECK(btstack_linked_list_iterator_has_next(&it));
    item = btstack_linked_list_iterator_next(&it);
    CHECK_EQUAL(item, &itemD);
    btstack_linked_list_remove(&testList, &itemD);
    CHECK(!btstack_linked_list_iterator_has_next(&it));
}

TEST(LinkedList, RemoveSecondAndThirdUsingIterator){
    btstack_linked_list_iterator_t it;
    btstack_linked_list_iterator_init(&it, &testList);
    btstack_linked_item_t * item;
    CHECK(btstack_linked_list_iterator_has_next(&it));
    item = btstack_linked_list_iterator_next(&it);
    CHECK(btstack_linked_list_iterator_has_next(&it));
    item = btstack_linked_list_iterator_next(&it);
    CHECK_EQUAL(item, &itemB);
    btstack_linked_list_iterator_remove(&it);   // B
    CHECK(btstack_linked_list_iterator_has_next(&it));
    item = btstack_linked_list_iterator_next(&it);
    CHECK_EQUAL(item, &itemC);
    btstack_linked_list_iterator_remove(&it);   // C
    CHECK(btstack_linked_list_iterator_has_next(&it));
    item = btstack_linked_list_iterator_next(&it);
    CHECK_EQUAL(item, &itemD);
    CHECK(!btstack_linked_list_iterator_has_next(&it));
}

TEST(LinkedList, RemoveSecondAndThirdUsingListRemove){
    btstack_linked_list_iterator_t it;
    btstack_linked_list_iterator_init(&it, &testList);
    btstack_linked_item_t * item;
    CHECK(btstack_linked_list_iterator_has_next(&it));
    item = btstack_linked_list_iterator_next(&it);
    CHECK(btstack_linked_list_iterator_has_next(&it));
    item = btstack_linked_list_iterator_next(&it);
    CHECK_EQUAL(item, &itemB);
    btstack_linked_list_remove(&testList, &itemB);
    btstack_linked_list_remove(&testList, &itemC);
    CHECK(btstack_linked_list_iterator_has_next(&it));
    item = btstack_linked_list_iterator_next(&it);
    CHECK_EQUAL(item, &itemD);
    CHECK(!btstack_linked_list_iterator_has_next(&it));
}

int main (int argc, const char * argv[]){
    return CommandLineTestRunner::RunAllTests(argc, argv);
}