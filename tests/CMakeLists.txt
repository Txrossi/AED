# Adiciona o diretório include do Unity
include_directories(${CMAKE_SOURCE_DIR}/unity)

# Lista os arquivos de teste
set(TEST_SOURCES
    ${CMAKE_SOURCE_DIR}/tests/test_calculadora.c
    ${CMAKE_SOURCE_DIR}/unity/unity.c  # Aqui incluímos o Unity como parte do projeto
)

# Cria o executável do teste
add_executable(test_calculadora ${TEST_SOURCES})

# Especifica que o teste precisa da biblioteca principal
target_link_libraries(test_calculadora projeto)