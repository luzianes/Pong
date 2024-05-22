
/**
 * main.c
 * Created on Mai, 21th 2024
 * Author: Lisa Matubara, Luziane Santos e Thaís Aguiar, com base no trabalho de Tiago Barros
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "screen.h"
#include "keyboard.h"
#include "timer.h"

// Define a struct Raquete com seus elementos (typedef cria um alias (raquete))
typedef struct Raquete {
    int x, y;     // posição (x, y) da raquete
    int largura;  // largura da raquete
    int altura;   // altura da raquete
    char simbolo; // símbolo que forma a raquete
} raquete;

// Define a posição inicial (x,y) da bola e seus incrementos (+1)
int x = 34, y = 12;
int incX = 1, incY = 1;

// Cria variável com o número de raquetes
int qtde_raquete = 2;

// Cria variáveis para acumular pontuação
int jogador1 = 0;
int jogador2 = 0;

// Função que movimenta a bola no terminal
void printBola(int nextX, int nextY) {
    screenSetColor(CYAN, DARKGRAY);
    screenGotoxy(x, y);
    printf(" ");
    x = nextX;
    y = nextY;
    screenGotoxy(x, y);
    printf("O");
}

// Inicializa a raquete com seus parâmetros
void iniciar_raquete(raquete *rptr, int x, int y, int largura, int altura, char simbolo) {
    rptr->x = x;
    rptr->y = y;
    rptr->largura = largura;
    rptr->altura = altura;
    rptr->simbolo = simbolo;
}

// Função para imprimir a raquete na tela
void imprimir_raquete(raquete *rptr) {
    screenSetColor(MAGENTA, DARKGRAY);
    for (int i = 0; i < rptr->altura; i++) {
        screenGotoxy(rptr->x, rptr->y + i);
        printf("%c", rptr->simbolo);
    }
}

// Função para apagar a raquete da tela
void apagar_raquete(raquete *rptr) {
    for (int i = 0; i < rptr->altura; i++) {
        screenGotoxy(rptr->x, rptr->y + i);
        printf(" ");
    }
}

// Função para verificar se houve colisão com a raquete
int verificar_colisao(raquete *rptr, int Ox, int Oy) {
    for (int i = 0; i < rptr->altura; i++) {
        for (int j = 0; j < rptr->largura; j++) {
            if (Ox == rptr->x + j && Oy == rptr->y + i) {
                return 1; // Houve colisão com a raquete
            }
        }
    }
    return 0; // Não houve colisão com a raquete
}

// Função para salvar a pontuação dos jogadores em um arquivo
void salvar_pontuacao(int jogador1, int jogador2) {
    FILE *file = fopen("pontuacao.txt", "w");
    if (file != NULL) {
        fprintf(file, "Jogador 1: %d\n", jogador1);
        fprintf(file, "Jogador 2: %d\n", jogador2);
        fclose(file);
    } else {
        printf("Erro ao abrir o arquivo de pontuação!\n");
    }
}

int main() {
    static int ch = 0;

    // Aloca memória para as raquetes
    raquete *rptr = (raquete *)malloc(qtde_raquete * sizeof(raquete));

    screenInit(1);
    keyboardInit();
    timerInit(50);

    printBola(x, y);

    // Inicia as raquetes com a posição (x,y), largura, altura e símbolo
    iniciar_raquete(&rptr[0], 4, 10, 1, 10, '|');  // Raquete esquerda
    iniciar_raquete(&rptr[1], 76, 10, 1, 10, '|'); // Raquete direita

    screenUpdate();

    while (ch != 27) // Jogo ativo enquanto não teclar ESC
    {
        // Verifica a entrada do usuário (tecla clicada) ---> IMPLEMENTAR MENU?
        if (keyhit()) {
            ch = readch();

            // Apaga a raquete atual
            apagar_raquete(&rptr[0]);
            apagar_raquete(&rptr[1]);

            // Movimenta a raquete esquerda com 's' e 'd'
            if (ch == 's' && rptr[0].y > MINY + 1) {
                rptr[0].y--;
            }
            if (ch == 'd' && rptr[0].y < MAXY - rptr[0].altura) {
                rptr[0].y++;
            }
            // Movimenta a raquete direita com 'k' e 'l'
            if (ch == 'k' && rptr[1].y > MINY + 1) {
                rptr[1].y--;
            }
            if (ch == 'l' && rptr[1].y < MAXY - rptr[1].altura) {
                rptr[1].y++;
            }

            // Imprime a nova posição da raquete
            imprimir_raquete(&rptr[0]);
            imprimir_raquete(&rptr[1]);

            screenUpdate();
        }

        if (timerTimeOver() == 1) {
            // Verifica se houve colisão com a moldura
            int newX = x + incX;
            if (newX >= (MAXX - strlen("O") - 1) || newX <= MINX + 1) incX = -incX;
            int newY = y + incY;
            if (newY >= MAXY - 1 || newY <= MINY + 1) incY = -incY;

            // Verifica se houve colisão com as raquetes
            for (int i = 0; i < qtde_raquete; i++) {
                if (verificar_colisao(&rptr[i], newX, newY)) {
                    incX = -incX;
                    // Aumenta a pontuação do jogador que conseguiu rebater a bola
                    if (i == 0) {
                        jogador1++;
                    } else {
                        jogador2++;
                    }
                    break;
                }
            }

            printBola(newX, newY);

            for (int i = 0; i < qtde_raquete; i++) {
                imprimir_raquete(&rptr[i]);
            }

            screenUpdate();
        }
    }

    salvar_pontuacao(jogador1, jogador2); // Salva a pontuação ao final do jogo no arquivo pontuacao.txt (\build)

    free(rptr);

    keyboardDestroy();
    screenDestroy();
    timerDestroy();

    return 0;
}

