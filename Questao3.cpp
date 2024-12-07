#include <stdio.h>

int main() {
    const int ALUNOS = 5;    
    const int PROVAS = 4;    
    float notas[ALUNOS][PROVAS];
    float mediasAlunos[ALUNOS];
    float somaTurma = 0;

    printf("Digite as notas dos %d alunos (4 provas para cada):\n", ALUNOS);
    for (int i = 0; i < ALUNOS; i++) {
        printf("Aluno %d:\n", i + 1);
        float somaAluno = 0;
        for (int j = 0; j < PROVAS; j++) {
            printf("  Nota da prova %d: ", j + 1);
            scanf("%f", &notas[i][j]);
            somaAluno += notas[i][j];
        }
        mediasAlunos[i] = somaAluno / PROVAS;
        somaTurma += somaAluno;
    }


    printf("\nMedias dos alunos:\n");
    for (int i = 0; i < ALUNOS; i++) {
        printf("Aluno %d: Media = %.2f\n", i + 1, mediasAlunos[i]);
    }


    float mediaTurma = somaTurma / (ALUNOS * PROVAS);
    printf("\nMedia da turma: %.2f\n", mediaTurma);

    return 0;
}

