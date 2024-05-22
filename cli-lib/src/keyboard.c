/**
 * keyboard.c
 * Created on Aug, 23th 2023
 * Author: Tiago Barros
 * Based on "From C to C++ course - 2002"
 * Implementação das funções para controle de entrada do teclado utilizando <termios.h> para manipulação do terminal
*/

#include <termios.h>
#include <unistd.h>

#include "keyboard.h"

// Variáveis estáticas para armazenar configurações do terminal
static struct termios initialSettings, newSettings;
static int peekCharacter; // Armazena o próximo caractere lido (buffer)

// Inicializa a configuração do teclado para entrada não bloqueante
void keyboardInit()
{
    tcgetattr(0, &initialSettings);  // Obtém as configurações atuais do terminal
    newSettings = initialSettings;   // Copia as configurações atuais
    newSettings.c_lflag &= ~ICANON;  // Desativa o modo canônico (buffering de entrada)
    newSettings.c_lflag &= ~ECHO;    // Desativa a exibição dos caracteres digitados (eco das teclas digitadas)
    newSettings.c_lflag &= ~ISIG;    // Desativa sinais de interrupção (Ctrl+C, Ctrl+Z)
    newSettings.c_cc[VMIN] = 1;      // Mínimo de caracteres para leitura
    newSettings.c_cc[VTIME] = 0;     // Tempo de espera para leitura (desativado)
    tcsetattr(0, TCSANOW, &newSettings); // Aplica as novas configurações imediatamente
}

// Restaura as configurações originais do teclado
void keyboardDestroy()
{
    tcsetattr(0, TCSANOW, &initialSettings); // Restaura as configurações originais do terminal
}

// Verifica se uma tecla foi pressionada
int keyhit()
{
    unsigned char ch;
    int nread;

    if (peekCharacter != -1) return 1; // Se há um caractere armazenado, retorna verdadeiro
    
    newSettings.c_cc[VMIN]=0; // Muda o terminal para modo de leitura não bloqueante
    tcsetattr(0, TCSANOW, &newSettings);
    nread = read(0,&ch,1); // Tenta ler um caractere
    newSettings.c_cc[VMIN]=1; // Restaura o modo de leitura original
    tcsetattr(0, TCSANOW, &newSettings);
    
    if(nread == 1) 
    {
        peekCharacter = ch; // Armazena o caractere lido
        return 1; // Retorna verdadeiro se um caractere foi lido
    }
    
    return 0; // Retorna falso se nenhum caractere foi lido
}

// Lê o caractere pressionado
int readch()
{
    char ch;

    if (peekCharacter != -1)
    {
        ch = peekCharacter;          // Usa o caractere armazenado se disponível
        peekCharacter = -1;          // Reseta o buffer - se há uma tecla armazenada, retorna-a
        return ch;
    }
    read(0, &ch, 1);                 // Lê um caractere do terminal
    return ch;                       // Retorna o caractere lido
}
