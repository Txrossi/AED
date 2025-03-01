cmake_minimum_required(VERSION 3.10)

# Defina o nome do projeto e a linguagem (C)
project(MeuProjeto C)

# Defina o padrão da versão do C
set(CMAKE_C_STANDARD 11)

# Ativa todos os avisos do compilador
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")

# Adiciona o diretório "include" para que os arquivos .h sejam encontrados
include_directories(include)

# Adiciona os diretórios de origem do projeto
add_subdirectory(src)

# Adiciona o diretório de testes
add_subdirectory(tests)