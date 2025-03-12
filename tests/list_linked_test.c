// src/test_simple_linked.c
#include "unity.h"
#include "../include/simple_linked.h"

LinkedList list;

void setUp(void) {
    initList(&list);
}

void tearDown(void) {
    // Clean up after tests if necessary
}

void test_initList(void) {
    TEST_ASSERT_NULL(list.head);
    TEST_ASSERT_EQUAL(0, list.count);
    for (int i = 0; i < MAX_NODES; i++) {
        TEST_ASSERT_EQUAL(0, list.used[i]);
    }
}

void test_insertNode(void) {
    int data1 = 10;
    int data2 = 20;

    TEST_ASSERT_EQUAL(1, insertNode(&list, &data1, sizeof(data1)));
    TEST_ASSERT_EQUAL(1, list.count);
    TEST_ASSERT_EQUAL(&data1, list.head->data);

    TEST_ASSERT_EQUAL(1, insertNode(&list, &data2, sizeof(data2)));
    TEST_ASSERT_EQUAL(2, list.count);
    TEST_ASSERT_EQUAL(&data2, list.head->data);
    TEST_ASSERT_EQUAL(&data1, list.head->next->data);
}

void test_deleteNode(void) {
    int data1 = 10;
    int data2 = 20;

    insertNode(&list, &data1, sizeof(data1));
    insertNode(&list, &data2, sizeof(data2));

    TEST_ASSERT_EQUAL(1, deleteNode(&list, &data1, sizeof(data1)));
    TEST_ASSERT_EQUAL(1, list.count);
    TEST_ASSERT_EQUAL(&data2, list.head->data);

    TEST_ASSERT_EQUAL(1, deleteNode(&list, &data2, sizeof(data2)));
    TEST_ASSERT_EQUAL(0, list.count);
    TEST_ASSERT_NULL(list.head);
}

void test_deleteNode_not_found(void) {
    int data1 = 10;
    int data2 = 20;
    int data3 = 30;

    insertNode(&list, &data1, sizeof(data1));
    insertNode(&list, &data2, sizeof(data2));

    TEST_ASSERT_EQUAL(-1, deleteNode(&list, &data3, sizeof(data3)));
    TEST_ASSERT_EQUAL(2, list.count);
    TEST_ASSERT_EQUAL(&data2, list.head->data);
    TEST_ASSERT_EQUAL(&data1, list.head->next->data);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_initList);
    RUN_TEST(test_insertNode);
    RUN_TEST(test_deleteNode);
    RUN_TEST(test_deleteNode_not_found);
    return UNITY_END();
}// src/test_simple_linked.c
