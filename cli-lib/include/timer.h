/**
 * timer.h
 * Created on Aug, 23th 2023
 * Author: Tiago Barros
 * Based on "From C to C++ course - 2002"
*/

// Declarações das funções de controle de temporização para o jogo.

// Inicializa o temporizador com um valor em milissegundos
void timerInit(int valueMilliSec);

// Destroi o temporizador, desativando-o
void timerDestroy();

// Atualiza o temporizador com um novo valor em milissegundos
void timerUpdateTimer(int valueMilliSec);

// Verifica se o tempo do temporizador terminou
int timerTimeOver();

// Imprime o tempo decorrido desde a última inicialização ou atualização
void timerPrint();
