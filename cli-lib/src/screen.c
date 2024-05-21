/**
 * screen.c
 * Created on Aug, 23th 2023
 * Author: Tiago Barros
 * Based on "From C to C++ course - 2002"
*/

#include "screen.h"

void screenDrawBorders() // Desenhar bordas ao redor da área de desenho
{
    char hbc = BOX_HLINE; // Caractere de linha horizontal
    char vbc = BOX_VLINE; // Caractere de linha vertical

    screenClear(); // Limpa a tela
    screenBoxEnable(); // Habilita o modo de desenho de caixa

    screenGotoxy(MINX, MINY); // Move o cursor para a posição (MINX, MINY)
    printf("%c", BOX_UPLEFT); // Desenha o canto superior esquerdo

    for (int i=MINX+1; i<MAXX; i++)
    {
        screenGotoxy(i, MINY);
        printf("%c", hbc); // Desenha a linha superior
    }
    screenGotoxy(MAXX, MINY);
    printf("%c", BOX_UPRIGHT); // Desenha o canto superior direito

    for (int i=MINY+1; i<MAXY; i++)
    {
        screenGotoxy(MINX, i);
        printf("%c", vbc); // Desenha as linhas verticais
        screenGotoxy(MAXX, i);
        printf("%c", vbc); // Desenha as linhas verticais
    }

    screenGotoxy(MINX, MAXY); // Desenha a linha inferior
    printf("%c", BOX_DWNLEFT); // Desenha o canto inferior esquerdo
    for (int i=MINX+1; i<MAXX; i++)
    {
        screenGotoxy(i, MAXY);
        printf("%c", hbc);
    }
    screenGotoxy(MAXX, MAXY);
    printf("%c", BOX_DWNRIGHT); // Desenha o canto inferior direito

    screenBoxDisable(); // Desabilita o modo de desenho de caixa

}

void screenInit(int drawBorders) // Inicializar a tela
{
    screenClear(); // Limpa a tela
    if (drawBorders) screenDrawBorders(); // Desenha as bordas se solicitado
    screenHomeCursor(); // Move o cursor para a posição inicial
    screenHideCursor(); // Esconde o cursor
}

void screenDestroy() // Restaurar o estado inicial da tela
{
    printf("%s[0;39;49m", ESC); // Reset colors
    screenSetNormal(); // Define o texto como normal
    screenClear(); // Limpa a tela
    screenHomeCursor(); // Move o cursor para a posição inicial
    screenShowCursor(); // Mostra o cursor
}

void screenGotoxy(int x, int y) // Move o cursor para a posição específica
{
    x = ( x<0 ? 0 : x>=MAXX ? MAXX-1 : x);
    y = ( y<0 ? 0 : y>MAXY ? MAXY : y);

    printf("%s[f%s[%dB%s[%dC", ESC, ESC, y, ESC, x);
}

void screenSetColor( screenColor fg, screenColor bg) // Definir as cores do texto e do fundo
{
    char atr[] = "[0;";

    if ( fg > LIGHTGRAY )
    {
        atr[1] = '1';
		fg -= 8;
    }

    printf("%s%s%d;%dm", ESC, atr, fg+30, bg+40);
}
