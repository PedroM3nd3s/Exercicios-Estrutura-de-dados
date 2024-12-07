#include <stdio.h>

int main() {
    const int LINHAS = 3;
    const int COLUNAS = 3;
    int matriz[LINHAS][COLUNAS];
    int maior, menor;

    printf("Digite os valores da matriz 3x3:\n");
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    maior = matriz[0][0];
    menor = matriz[0][0];

    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            if (matriz[i][j] > maior) {
                maior = matriz[i][j];
            }
            if (matriz[i][j] < menor) {
                menor = matriz[i][j];
            }
        }
    }
    printf("Maior elemento: %d\n", maior);
    printf("Menor elemento: %d\n", menor);

    return 0;
}
