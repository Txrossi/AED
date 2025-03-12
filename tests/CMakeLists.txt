# Add the Unity include directory
include_directories(${CMAKE_SOURCE_DIR}/unity)

# Lista os arquivos de teste
set(CALC
    ${CMAKE_SOURCE_DIR}/tests/test_calculadora.c
    ${CMAKE_SOURCE_DIR}/unity/unity.c  # Here we include Unity as part of the project
)

set(LIST
    ${CMAKE_SOURCE_DIR}/tests/list_linked_test.c
    ${CMAKE_SOURCE_DIR}/unity/unity.c  # Aqui incluímos o Unity como parte do projeto
)

# Creates the test executable and specifies that the test needs the main library
add_executable(test_calculadora ${CALC})
target_link_libraries(test_calculadora projeto)
add_test(calculator_test_name test_calculadora)

# Creates the test executable and specifies that the test needs the main library
add_executable(linked_test ${LIST})
target_link_libraries(linked_test projeto)
add_test(linked_list_test_name linked_test)