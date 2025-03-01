include_directories(${CMAKE_SOURCE_DIR}/src)

# Especifica os arquivos fonte com o caminho correto
set(SOURCES
    calc.c
)

# Cria a biblioteca estática com os arquivos fontes
add_library(projeto STATIC ${SOURCES})