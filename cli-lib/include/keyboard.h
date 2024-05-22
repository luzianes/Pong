/**
 * keyboard.h
 * Created on Aug, 23th 2023
 * Author: Tiago Barros
 * Based on "From C to C++ course - 2002"
 * Declarações das funções para controle de entrada do teclado.
*/

#ifndef __KEYBOARD_H__
#define __KEYBOARD_H__

void keyboardInit(); // Inicializa a configuração do teclado para entrada não bloqueante

void keyboardDestroy(); // Restaura as configurações originais do teclado
    
int keyhit(); // Verifica se uma tecla foi pressionada

int readch(); // Lê o caractere pressionado

#endif /* __KEYBOARD_H__ */
