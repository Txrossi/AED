// tests/test_calculadora.c
#include "unity.h"
#include "../include/calc.h"

void setUp(void) {
    // Configuração antes dos testes (opcional)
}

void tearDown(void) {
    // Limpeza após os testes (opcional)
}

void test_soma(void) {
    TEST_ASSERT_EQUAL(5, soma(2, 3));
    TEST_ASSERT_EQUAL(0, soma(-2, 2));
    TEST_ASSERT_EQUAL(-5, soma(-2, -3));
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_soma);
    return UNITY_END();
}