#include <stdio.h>

// Funções Recursivas: Torre, Bispo e Rainha
// -------------------------------------------

// Função recursiva para a Torre — move em linha reta
void moverTorre(int casasRestantes) {
    if (casasRestantes == 0) return;  // Caso base: parar quando não houver casas
    printf("Direita\n");
    moverTorre(casasRestantes - 1);   // Chamada recursiva para mover mais uma casa
}

// Função recursiva para o Bispo — combina recursão com loops aninhados
void moverBispo(int movimentosVerticais, int movimentosHorizontais) {
    if (movimentosVerticais == 0) return; // Caso base: terminou o movimento vertical
    
    // Loop externo (movimento vertical)
    for (int i = 0; i < 1; i++) {
        // Loop interno (movimento horizontal)
        for (int j = 0; j < movimentosHorizontais; j++) {
            printf("Cima, Direita\n");
        }
    }
    moverBispo(movimentosVerticais - 1, movimentosHorizontais); // Recursão
}

// Função recursiva para a Rainha — move em linha reta, mas pode ser adaptada para qualquer direção
void moverRainha(int casasRestantes) {
    if (casasRestantes == 0) return; // Caso base
    printf("Esquerda\n");
    moverRainha(casasRestantes - 1); // Chamada recursiva
}

// -------------------------------------------
// Cavalo — usando loops complexos e controle de fluxo
// -------------------------------------------
void moverCavalo() {
    printf("\n=== Movimento do Cavalo ===\n");
    // Movimento: duas casas para cima e uma para a direita
    int cima = 2;
    int direita = 1;

    for (int i = 1, j = 0; i <= cima || j < direita; i++, j++) {
        // Movimento vertical
        if (i <= cima) {
            printf("Cima\n");
            if (i == cima && j < direita) continue; // Pula para o próximo estágio
        }

        // Movimento horizontal
        int contador = 0;
        while (contador < direita) {
            printf("Direita\n");
            contador++;
            break; // Interrompe o loop após o movimento lateral
        }
    }
}

// -------------------------------------------
// Função principal
// -------------------------------------------
int main() {
    // Torre — 5 casas para a direita
    printf("=== Movimento da Torre ===\n");
    moverTorre(5);

    // Bispo — 3 movimentos diagonais
    printf("\n=== Movimento do Bispo ===\n");
    moverBispo(3, 1);

    // Rainha — 8 casas para a esquerda
    printf("\n=== Movimento da Rainha ===\n");
    moverRainha(8);

    // Cavalo — movimento em L (2 para cima, 1 para a direita)
    moverCavalo();

    return 0;
}