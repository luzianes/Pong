#include <stdio.h>
#include "cli-lib/include/keyboard.h"
#include "cli-lib/include/screen.h"
#include "cli-lib/include/timer.h"

int main() {
    // Inicialização
    screenInit(1);
    keyboardInit();
    timerInit(50);

    // Loop principal do jogo
    while (1) {
        if (keyhit()) {
            int ch = readch();
            if (ch == 27) { // ESC para sair
                break;
            }
            printf("Key pressed: %d\n", ch);
        }

        if (timerTimeOver()) {
            // Atualize o estado do jogo
        }

        screenUpdate();
    }

    // Limpeza
    keyboardDestroy();
    screenDestroy();
    timerDestroy();

    return 0;
}
