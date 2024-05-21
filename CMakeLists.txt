#Define a versão mínima do CMake
cmake_minimum_required(VERSION 3.22.1)

#Define que o nome do projeto e a linguagem utilizada
project(pong C)

#Define o padrão da linguagem utilizada
set(CMAKE_C_STANDARD 99)

#Adiciona a pasta include da biblioteca cli-lib nos diretórios de inclusão
include_directories(cli-lib/include)

# Adiciona os arquivos necessários para criar o executável do projeto
add_executable(pong
        main.c
        cli-lib/src/keyboard.c
        cli-lib/src/screen.c
        cli-lib/src/timer.c
)
