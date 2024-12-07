#include <stdio.h>

int main() {
    const int CIDADES = 7;
    const int MESES = 6;
    float pluviometros[CIDADES][MESES];
    float mediaMensalCidades[CIDADES];
    float mediaMensalRegiao[MESES]; 

    printf("Digite os indices pluviometricos (em mm) das 7 cidades para os 6 meses:\n");
    for (int i = 0; i < CIDADES; i++) {
        printf("Cidade %d:\n", i + 1);
        for (int j = 0; j < MESES; j++) {
            printf("  Mes %d: ", j + 1);
            scanf("%f", &pluviometros[i][j]);
        }
    }

    for (int i = 0; i < CIDADES; i++) {
        float somaCidades = 0;
        for (int j = 0; j < MESES; j++) {
            somaCidades += pluviometros[i][j];
        }
        mediaMensalCidades[i] = somaCidades / MESES;
    }

    for (int j = 0; j < MESES; j++) {
        float somaMes = 0;
        for (int i = 0; i < CIDADES; i++) {
            somaMes += pluviometros[i][j];
        }
        mediaMensalRegiao[j] = somaMes / CIDADES;
    }

    printf("\nMedia mensal de pluviosidade por cidade:\n");
    for (int i = 0; i < CIDADES; i++) {
        printf("Cidade %d: %.2f mm\n", i + 1, mediaMensalCidades[i]);
    }

    printf("\nMedia de pluviosidade por mes na regiao:\n");
    for (int j = 0; j < MESES; j++) {
        printf("Mes %d: %.2f mm\n", j + 1, mediaMensalRegiao[j]);
    }

    return 0;
}

