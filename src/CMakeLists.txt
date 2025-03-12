include_directories(${CMAKE_SOURCE_DIR}/src)

# Especifica os arquivos fonte com o caminho correto
set(SOURCES
    calc.c
    simple_linked.c
)

set(Exercicios
    ex1.c
)

# Cria a biblioteca estática com os arquivos fontes
add_library(projeto STATIC ${SOURCES})

add_executable(ex1 ${Exercicios})
target_link_libraries(ex1 projeto)