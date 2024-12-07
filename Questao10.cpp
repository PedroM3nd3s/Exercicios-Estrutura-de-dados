#include <stdio.h>

int somatorio(int N) {
    if (N == 1) {
        return 1;
    }
    return N + somatorio(N - 1);
}

int main() {
    int N;

    printf("Digite o valor de N: ");
    scanf("%d", &N);
    
    int resultado = somatorio(N);
    printf("A somatoria dos numeros de 1 a %d e: %d\n", N, resultado);

    return 0;
}
