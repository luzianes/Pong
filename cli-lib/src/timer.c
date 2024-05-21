/**
 * timer.c
 * Created on Aug, 23th 2023
 * Author: Tiago Barros
 * Based on "From C to C++ course - 2002"
*/

// Implementação das funções de controle de temporização utilizando a biblioteca <sys/time.h>

#include "timer.h"
#include <sys/time.h>
#include <stdio.h>

// Variáveis estáticas para controle de tempo
static struct timeval timer, now; // Estruturas timeval para armazenar o tempo inicial e o tempo atual
static int delay = -1; // Variável que armazena o valor do atraso em milissegundos

// Inicializa o temporizador com o valor especificado em milissegundos
void timerInit(int valueMilliSec)
{
    delay = valueMilliSec; // Define o valor do atraso
    gettimeofday(&timer, NULL); // Captura o tempo atual e armazena em 'timer'
}

// Destroi o temporizador, desativando-o
void timerDestroy()
{
    delay = -1; // Define o valor do atraso como -1, indicando que o temporizador está desativado
}

// Atualiza o temporizador com um novo valor em milissegundos
void timerUpdateTimer(int valueMilliSec)
{
    delay = valueMilliSec; // Define o novo valor do atraso
    gettimeofday(&timer, NULL); // Captura o tempo atual e armazena em 'timer'
}

// Calcula a diferença de tempo em milissegundos entre 'now' e 'timer'
int getTimeDiff()
{
    gettimeofday(&now, NULL); // Captura o tempo atual e armazena em 'now'
    long diff = (((now.tv_sec - timer.tv_sec) * 1000000) + now.tv_usec - timer.tv_usec)/1000; // Calcula a diferença em milissegundos
    return (int) diff; // Retorna a diferença de tempo em milissegundos
}

// Verifica se o tempo do temporizador terminou
int timerTimeOver()
{
    int ret = 0;

    if (getTimeDiff() > delay) // Se o tempo decorrido for maior que o atraso configurado
    {
        ret = 1; // Define o retorno como 1 (tempo terminado)
        gettimeofday(&timer, NULL); // Reinicializa o temporizador
    }

    return ret; // Retorna 1 se o tempo terminou, 0 caso contrário
}

// Imprime o tempo decorrido desde a última inicialização ou atualização
void timerPrint()
{
    printf("Timer:  %d", getTimeDiff()); // Imprime a diferença de tempo em milissegundos
}