#include <stdio.h>

#define TAMANHO 10
#define TAMANHO_NAVIO 3

int main() {
    int tabuleiro[TAMANHO][TAMANHO] = {0};  // Inicializa todas as posições com 0

    // Vetores que representam os navios
    int navio_horizontal[TAMANHO_NAVIO] = {3, 3, 3};
    int navio_vertical[TAMANHO_NAVIO] = {3, 3, 3};

    // Posição inicial do navio horizontal
    int linha_h = 2;
    int coluna_h = 4;

    // Posição inicial do navio vertical
    int linha_v = 5;
    int coluna_v = 1;

    // Posicionamento do navio horizontal (da esquerda para a direita)
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha_h][coluna_h + i] = navio_horizontal[i];
    }

    // Posicionamento do navio vertical (de cima para baixo)
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha_v + i][coluna_v] = navio_vertical[i];
    }

    // Impressão do tabuleiro
    printf("Tabuleiro:\n\n");

    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
