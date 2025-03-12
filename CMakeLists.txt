cmake_minimum_required(VERSION 3.10)

set(CMAKE_C_COMPILER "C:\\msys64\\mingw64\\bin\\gcc.exe")
set(CMAKE_CXX_COMPILER "C:\\msys64\\mingw64\\bin\\g++.exe")

# Defina o nome do projeto e a linguagem (C)
project(AEDSProject C)

# Defina o padrão da versão do C
set(CMAKE_C_STANDARD 11)

# Ativa todos os avisos do compilador
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")

# Adiciona o diretório "include" para que os arquivos .h sejam encontrados
include_directories(include)

# Adiciona os diretórios de origem do projeto
add_subdirectory(src)

enable_testing()
# Adiciona o diretório de testes
add_subdirectory(tests)