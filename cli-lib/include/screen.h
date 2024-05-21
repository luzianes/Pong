/**
 * screen.h
 * Created on Aug, 23th 2023
 * Author: Tiago Barros
 * Based on "From C to C++ course - 2002"
 * Reference: https://en.wikipedia.org/wiki/ANSI_escape_code
*/

// Evitam que o conteúdo do arquivo screen.h seja incluído mais de uma vez durante a compilação
#ifndef __SCREEN_H__
#define __SCREEN_H__

#include <stdio.h>

// Terminal control sequences - Enviam comandos ao terminal para controlar a aparência do texto e o cursor
#define ESC            "\033" // Código de escape ANSI
#define NORMALTEXT     "[0m" // Texto normal
#define BOLDTEXT       "[1m" // Texto em negrito
#define ITALICTEXT     "[3m" // Texto em itálico
#define BLINKTEXT      "[5m" // Texto piscando
#define REVERSETEXT    "[7m" // Texto reverso
#define HOMECURSOR     "[f" // Move o cursor para a posição inicial
#define SHOWCURSOR     "[?25h" // Mostra o cursor
#define HIDECURSOR     "[?25l" // Esconde o cursor
#define CLEARSCREEN    "[2J" // Limpa a tela

// BOX Drawing - Unix like terminals
// Desenham bordas e caixas no terminal
#define BOX_ENABLE     "(0" // Habilita caracteres de desenho de caixa
#define BOX_DISABLE    "(B" // Desabilita caracteres de desenho de caixa
#define BOX_VLINE      0x78 // Linha vertical
#define BOX_HLINE      0x71 // Linha horizontal
#define BOX_UPLEFT     0x6C // Canto superior esquerdo
#define BOX_UPRIGHT    0x6B // Canto superior direito
#define BOX_DWNLEFT    0x6D // Canto inferior esquerdo
#define BOX_DWNRIGHT   0x6A // Canto inferior direito
#define BOX_CROSS      0x6E // Cruzamento
#define BOX_TLEFT      0X74 // T à esquerda
#define BOX_TRIGHT     0X75 // T à direita
#define BOX_TUP        0X77 // T para cima
#define BOX_TDOWN      0X76 // T para baixo
#define BOX_DIAMOND    0x60  // Diamante
#define BOX_BLOCK      0x61 // Bloco
#define BOX_DOT        0x7E // Ponto

// screen constants
// Definem os limites da área de desenho da tela para o jogo
// limites horizontais e verticais - iniciais e finais
#define SCRSTARTX      3      // Initial and final screen positions for the game
#define SCRENDX        75     // It means the area that can be drawn
#define SCRSTARTY      1
#define SCRENDY        23

#define MINX           1      // min screen horizontal pos
#define MINY           1      // min screen vertical pos
#define MAXX           80     // max screen horizontal pos
#define MAXY           24     // max screen vertical pos

/**
 * Screen Colors type - Definem várias cores que podem ser usadas como cores de primeiro plano (texto) e fundo no terminal
*/
typedef enum {BLACK, RED, GREEN, BROWN, BLUE, MAGENTA, CYAN, LIGHTGRAY,
        DARKGRAY, LIGHTRED, LIGHTGREEN, YELLOW, LIGHTBLUE,
        LIGHTMAGENTA, LIGHTCYAN, WHITE} screenColor;



/**
 * Move the cursor to position (0,0)
*/
static inline void screenHomeCursor()
{
    printf("%s%s", ESC, HOMECURSOR);
}

/**
 * Show the cursor
*/
static inline void screenShowCursor()
{
    printf("%s%s", ESC, SHOWCURSOR);
}

/**
 * Hide the cursor
*/
static inline void screenHideCursor()
{
    printf("%s%s", ESC, HIDECURSOR);
}

/**
 * Clear the screen
*/
static inline void screenClear()
{
    screenHomeCursor();
    printf("%s%s", ESC, CLEARSCREEN);
}

/**
 * Update screen imediatelly
*/
static inline void screenUpdate() {
    fflush(stdout);
}

/**
 * Set screen mode to "normal"
*/
static inline void screenSetNormal()
{
    printf("%s%s", ESC, NORMALTEXT);
}

/**
 * Set screen mode to "bold"
*/
static inline void screenSetBold()
{
    printf("%s%s", ESC, BOLDTEXT);
}

/**
 * Set screen mode to "blink"
*/
static inline void screenSetBlink()
{
    printf("%s%s", ESC, BLINKTEXT);
}

/**
 * Set screen mode to "reverse"
*/
static inline void screenSetReverse()
{
    printf("%s%s", ESC, REVERSETEXT);
}

/**
 * Enable BOX characters in terminal
*/
static inline void screenBoxEnable()
{
    printf("%s%s", ESC, BOX_ENABLE);
}

/**
 * Disable BOX characters in terminal
*/
static inline void screenBoxDisable()
{
    printf("%s%s", ESC, BOX_DISABLE);
}

/**
 * Clear the screen, set cursor to home position
 * and optionally draw borders on it.
 *
 * @param drawBorders if not zero, draw borders on screen.
*/
void screenInit(int drawBorders); // Se drawBorders for diferente de zero, desenha bordas ao redor da tela.

/**
 * Clear the screen and restores to initial state.
*/
void screenDestroy();

/**
 * Move cursor to position (x,y)
 * @param x x position
 * @param y y position
 */

void screenGotoxy(int x, int y);

/**
 * Define text colors
 * @param fg foreground color, can assume values from BLACK to WHITE
 * @param bg background color, can assume values from BLACK to LIGHTGRAY
*/
void screenSetColor(screenColor fg, screenColor bg);

#endif /* __SCREEN_H__ */