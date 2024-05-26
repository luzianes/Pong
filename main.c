/**
 * main.c
 * Created on Mai, 21th 2024
 * Author: Lisa Matubara, Luziane Santos e Thaís Aguiar, com base no trabalho de Tiago Barros
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include "screen.h"
#include "keyboard.h"
#include "timer.h"

// REQUISITO 1 - STRUCT
// Define a struct Raquete com seus elementos (typedef cria um alias (raquete))
typedef struct Raquete {
    int x, y;     // posição (x, y) da raquete
    int largura;  // largura da raquete
    int altura;   // altura da raquete
    char simbolo; // símbolo que forma a raquete
} raquete;

// REQUISITO 1 - STRUCT
// Define a struct Obstaculo com seus elementos (typedef cria um alias (obstaculo))
typedef struct Obstaculo {
    int x, y;        // posição (x, y) do obstáculo
    int altura;      // altura do obstáculo
    int direcao;     // direção de movimento (1 para baixo, -1 para cima)
    char simbolo;    // símbolo que forma o obstáculo
} obstaculo;


// Define a posição inicial (x,y) da bola e seus incrementos (+1)
int x = 34, y = 12;
int incX = 1, incY = 1;

// Cria variável com o número de raquetes
int qtde_raquete = 2;

// Cria variáveis para acumular pontuação
int jogador1 = 0;
int jogador2 = 0;

// Define o tempo máximo em segundos (2 minutos)
#define TEMPO_MAXIMO 150

// Estrutura para armazenar o tempo de início
struct timeval tempoInicio;

// Função para exibir a tela inicial
void exibirTelaInicial() {
    screenClear();
    screenDrawBorders();
    screenSetColor(WHITE, DARKGRAY);
    screenGotoxy((MAXX / 2) - 11, MAXY / 2 - 4);
    printf("  ____    ____  _   _  ____  ");
    screenGotoxy((MAXX / 2) - 11, MAXY / 2 - 3);
    printf(" |  __ \\ / __ \\| \\ | |/ __ \\ ");
    screenGotoxy((MAXX / 2) - 11, MAXY / 2 - 2);
    printf(" | |__) | |  | |  \\| | | ___");
    screenGotoxy((MAXX / 2) - 11, MAXY / 2 - 1);
    printf(" |  ___/| |  | | . ` | ||__ | ");
    screenGotoxy((MAXX / 2) - 11, MAXY / 2);
    printf(" | |    | |__| | |\\  | |__| |");
    screenGotoxy((MAXX / 2) - 11, MAXY / 2 + 1);
    printf(" |_|     \\____/|_| \\_|\\____/ ");

    screenGotoxy((MAXX / 2) - 5, MAXY / 2 + 3);
    screenSetColor(YELLOW, DARKGRAY);
    printf("▶ Começar");
    screenUpdate();

    while (1) {
        int ch = readch();
        if (ch == 10) { // Enter
            break;
        }
    }
}

// REQUISITO 2 - PONTEIROS
// Função para exibir o menu de seleção de nível
int exibirMenuNiveis() {
    const char *niveis[] = {"Iniciante", "Intermediário", "Avançado", "Expert"};
    int opcao = 0;

    while (1) {
        screenClear();
        screenDrawBorders();
        for (int i = 0; i < 4; i++) {
            screenGotoxy((MAXX / 2) - 6, (MAXY / 2) - 2 + i);
            if (i == opcao) {
                screenSetColor(YELLOW, DARKGRAY);
                printf("▶ %s", niveis[i]);
                screenSetColor(WHITE, DARKGRAY); // Reseta a cor após imprimir a linha selecionada
            } else {
                screenSetColor(WHITE, DARKGRAY);
                printf("  %s", niveis[i]);
            }
        }

        screenUpdate();
        int ch = readch();
        if (ch == 10) { // Enter
            break;
        } else if (ch == 'A') {
            opcao = (opcao > 0) ? opcao - 1 : 3; // Move para cima
        } else if (ch == 'B') {
            opcao = (opcao < 3) ? opcao + 1 : 0; // Move para baixo
        }
    }
    return opcao;
}

// Função que movimenta a bola no terminal
void printBola(int nextX, int nextY) {
    screenSetColor(CYAN, DARKGRAY);
    screenGotoxy(x, y);
    printf(" ");
    x = nextX;
    y = nextY;
    screenGotoxy(x, y);
    printf("●");  // Usando a bolinha Unicode
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

// Função para imprimir o obstáculo na tela
void imprimir_obstaculo(obstaculo *optr) {
    screenSetColor(RED, DARKGRAY);
    for (int i = 0; i < optr->altura; i++) {
        screenGotoxy(optr->x, optr->y + i);
        printf("%c", optr->simbolo);
    }
}

// Função para apagar o obstáculo da tela
void apagar_obstaculo(obstaculo *optr) {
    for (int i = 0; i < optr->altura; i++) {
        screenGotoxy(optr->x, optr->y + i);
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

// Função para verificar se houve colisão com o obstáculo
int verificar_colisao_obstaculo(obstaculo *optr, int Ox, int Oy) {
    for (int i = 0; i < optr->altura; i++) {
        if (Ox == optr->x && Oy == optr->y + i) {
            return 1; // Houve colisão com o obstáculo
        }
    }
    return 0; // Não houve colisão com o obstáculo
}

// Função para desenhar a linha pontilhada no meio da tela
void desenharLinhaPontilhada() {
    screenSetColor(WHITE, DARKGRAY);
    for (int i = MINY + 1; i < MAXY; i++) {
        if (i % 2 == 0) {
            screenGotoxy((MAXX - MINX) / 2, i);
            printf("|");
        }
    }
}

// REQUISITO 2 - PONTEIROS
// REQUISITO 6 - ESCRITA ARQUIVO
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

// Função para exibir a pontuação dos jogadores
void exibirPontuacao() {
    screenSetColor(YELLOW, DARKGRAY);
    screenGotoxy((MAXX / 4) - 1, MAXY - 1);
    printf("%d", jogador1);
    screenGotoxy((3 * MAXX / 4) - 1, MAXY - 1);
    printf("%d", jogador2);
}

// Função para calcular o tempo restante e exibir no canto superior central
void exibirTimer() {
    struct timeval tempoAtual;
    gettimeofday(&tempoAtual, NULL);
    long tempoPassado = (tempoAtual.tv_sec - tempoInicio.tv_sec);
    long tempoRestante = TEMPO_MAXIMO - tempoPassado;

    if (tempoRestante < 0) {
        tempoRestante = 0;
    }

    screenSetColor(GREEN, DARKGRAY);
    screenGotoxy((MAXX / 2) - 3, MINY);  // Ajuste a posição para que o ":" fique alinhado com a linha pontilhada
    printf("%02ld:%02ld", tempoRestante / 60, tempoRestante % 60);
}

// Função para exibir a tela de resultados
void exibirResultado(const char *mensagem) {
    screenClear();
    screenSetColor(RED, DARKGRAY);
    screenGotoxy((MAXX / 2) - (strlen(mensagem) / 2), MAXY / 2);
    printf("%s", mensagem);
    screenUpdate();
    sleep(3); // Espera 3 segundos antes de encerrar
}

int main() {
    static int ch = 0;

    keyboardInit();

    // Exibe a tela inicial
    exibirTelaInicial();

    // Exibe o menu de níveis
    int nivel = exibirMenuNiveis();

    // Ajusta configurações baseadas no nível
    int alturaRaquete = 6;
    int velocidadeBola = 70;
    int obstaculoAtivo = 0;
    int pontuacaoMaxima = 5; // Padrão
    obstaculo obst;

    if (nivel == 1) { // Intermediário
        alturaRaquete = 4;
    } else if (nivel == 2) { // Avançado
        alturaRaquete = 4;
        velocidadeBola = 60;
    } else if (nivel == 3) { // Expert
        alturaRaquete = 4;
        velocidadeBola = 60;
        pontuacaoMaxima = 10; // Pontuação máxima para nível Expert
        obstaculoAtivo = 1;
        obst.x = (MAXX - MINX) / 2; // Posição inicial no meio da tela
        obst.y = 10;                // Posição inicial y
        obst.altura = 5;            // Altura do obstáculo para nível Expert
        obst.direcao = 1;           // Começa se movendo para baixo
        obst.simbolo = '#';         // Símbolo do obstáculo
    }

    // REQUISITO 3 - ALOCAÇÃO DE MEMÓRIA
    // Aloca memória para as raquetes
    raquete *rptr = (raquete *)malloc(qtde_raquete * sizeof(raquete));

    screenInit(1);
    desenharLinhaPontilhada();
    timerInit(velocidadeBola);

    gettimeofday(&tempoInicio, NULL); // Obtém o tempo de início

    printBola(x, y);

    // Inicia as raquetes com a posição (x,y), largura, altura e símbolo
    iniciar_raquete(&rptr[0], 4, 10, 1, alturaRaquete, '|');  // Raquete esquerda
    iniciar_raquete(&rptr[1], 76, 10, 1, alturaRaquete, '|'); // Raquete direita

    while (ch != 27) // Jogo ativo enquanto não teclar ESC
    {
        // Verifica a entrada do usuário (tecla clicada)
        if (keyhit()) {
            ch = readch();

            // Apaga a raquete atual
            apagar_raquete(&rptr[0]);
            apagar_raquete(&rptr[1]);

            // Movimenta a raquete esquerda com 'w' ou 'W' e 's' ou 'S'
            if ((ch == 'w' || ch == 'W') && rptr[0].y > MINY + 1) {
                rptr[0].y--;
            }
            if ((ch == 's' || ch == 'S') && rptr[0].y < MAXY - rptr[0].altura) {
                rptr[0].y++;
            }

            // Movimenta a raquete direita com 'o' ou 'O' e 'l' ou 'L'
            if ((ch == 'o' || ch == 'O')  && rptr[1].y > MINY + 1) { // Seta para cima (ASCII 65)
                rptr[1].y--;
            }
            if ((ch == 'l' || ch == 'L') && rptr[1].y < MAXY - rptr[1].altura) { // Seta para baixo (ASCII 66)
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
            int newY = y + incY;

            // Verifica se a bola atingiu as paredes laterais (pontuação do adversário)
            if (newX >= (MAXX - strlen("O") - 1)) {
                jogador1++; // Jogador 1 pontua
                newX = (MAXX - MINX) / 2; // Reinicializa a posição da bola
                newY = (MAXY - MINY) / 2;
                incX = -incX; // Inverte a direção da bola
            } else if (newX <= MINX + 1) {
                jogador2++; // Jogador 2 pontua
                newX = (MAXX - MINX) / 2; // Reinicializa a posição da bola
                newY = (MAXY - MINY) / 2;
                incX = -incX; // Inverte a direção da bola
            }

            if (newY >= MAXY - 1 || newY <= MINY + 1) {
                incY = -incY;
            }

            // Verifica se houve colisão com as raquetes
            for (int i = 0; i < qtde_raquete; i++) {
                if (verificar_colisao(&rptr[i], newX, newY)) {
                    incX = -incX;
                    break;
                }
            }

            // Verifica se houve colisão com o obstáculo
            if (obstaculoAtivo && verificar_colisao_obstaculo(&obst, newX, newY)) {
                incX = -incX;
            }

            // Atualiza a posição do obstáculo se ativo
            if (obstaculoAtivo) {
                apagar_obstaculo(&obst);
                obst.y += obst.direcao;
                if (obst.y <= MINY + 1 || obst.y + obst.altura >= MAXY) {
                    obst.direcao = -obst.direcao;
                }
                imprimir_obstaculo(&obst);
            }

            printBola(newX, newY);

            for (int i = 0; i < qtde_raquete; i++) {
                imprimir_raquete(&rptr[i]);
            }

            exibirPontuacao();
            exibirTimer();

            screenUpdate();

            // Verifica condições de vitória
            struct timeval tempoAtual;
            gettimeofday(&tempoAtual, NULL);
            long tempoPassado = (tempoAtual.tv_sec - tempoInicio.tv_sec);

            // Um buffer chamado mensagem é declarado com um tamanho de 50 caracteres
            // Dependendo da pontuação dos jogadores, a mensagem correta é formatada e armazenada em mensagem usando snprintf
            if (jogador1 >= pontuacaoMaxima || jogador2 >= pontuacaoMaxima || tempoPassado >= TEMPO_MAXIMO) {
                char mensagem[50];
                if (jogador1 > jogador2) {
                    snprintf(mensagem, sizeof(mensagem), "Jogador 1 ganhou!");
                } else if (jogador2 > jogador1) {
                    snprintf(mensagem, sizeof(mensagem), "Jogador 2 ganhou!");
                } else {
                    snprintf(mensagem, sizeof(mensagem), "Empate!");
                }

                exibirResultado(mensagem);
                break;
            }
        }
    }

    salvar_pontuacao(jogador1, jogador2); // Salva a pontuação ao final do jogo no arquivo pontuacao.txt (\build)

    free(rptr);

    keyboardDestroy();
    screenDestroy();
    timerDestroy();

    return 0;
}