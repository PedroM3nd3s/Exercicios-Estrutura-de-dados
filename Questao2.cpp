#include <iostream>
#include <stdio.h>

using namespace std;

#define TAMANHO 3

void inicializarTabuleiro(char tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = ' ';
        }
    }
}

void exibirTabuleiro(char tabuleiro[TAMANHO][TAMANHO]) {
    printf("\n");
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf(" %c ", tabuleiro[i][j]);
            if (j < TAMANHO - 1) printf("|");
        }
        printf("\n");
        if (i < TAMANHO - 1) {
            printf("---|---|---\n");
        }
    }
    printf("\n");
}

char verificarVencedor(char tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        if (tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2] && tabuleiro[i][0] != ' ') {
            return tabuleiro[i][0];
        }
    }

    for (int i = 0; i < TAMANHO; i++) {
        if (tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[1][i] == tabuleiro[2][i] && tabuleiro[0][i] != ' ') {
            return tabuleiro[0][i];
        }
    }

    if (tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2] && tabuleiro[0][0] != ' ') {
        return tabuleiro[0][0];
    }
    if (tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0] && tabuleiro[0][2] != ' ') {
        return tabuleiro[0][2];
    }

    return ' ';
}

bool tabuleiroCheio(char tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            if (tabuleiro[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

int main() {
    char tabuleiro[TAMANHO][TAMANHO];
    char jogadorAtual = 'X';
    bool jogoAtivo = true;

    inicializarTabuleiro(tabuleiro);

    printf("Jogo da Velha\n");
    printf("Jogador 1: X\nJogador 2: O\n");

    while (jogoAtivo) {
        exibirTabuleiro(tabuleiro);
        int linha, coluna;


        printf("Jogador %c, digite a linha e coluna (0 a 2): ", jogadorAtual);
        scanf("%d %d", &linha, &coluna);

        if (linha < 0 || linha >= TAMANHO || coluna < 0 || coluna >= TAMANHO || tabuleiro[linha][coluna] != ' ') {
            printf("Jogada invalida. Tente novamente.\n");
            continue;
        }

        tabuleiro[linha][coluna] = jogadorAtual;

        char vencedor = verificarVencedor(tabuleiro);
        if (vencedor != ' ') {
            exibirTabuleiro(tabuleiro);
            printf("Jogador %c venceu!\n", vencedor);
            jogoAtivo = false;
            continue;
        }

        if (tabuleiroCheio(tabuleiro)) {
            exibirTabuleiro(tabuleiro);
            printf("Empate!\n");
            jogoAtivo = false;
            continue;
        }

        jogadorAtual = (jogadorAtual == 'X') ? 'O' : 'X';
    }

    return 0;
}
