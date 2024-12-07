#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct voo {
    int numero;
    int data;
    int hora;
    int minuto;
    int aeroporto_saida;
    int aeroporto_chegada;
    int rota;
    float tempo_estimado;
    int passageiros;
    struct voo *prox;
} Voo;

Voo *criarVoo(int numero, int data, int hora, int minuto, int aeroporto_saida, int aeroporto_chegada, int rota, float tempo_estimado, int passageiros) {
    Voo *novoVoo = (Voo *)malloc(sizeof(Voo));
    if (novoVoo == NULL) {
        printf("Erro ao alocar memoria para o voo.\n");
        exit(1);
    }
    novoVoo->numero = numero;
    novoVoo->data = data;
    novoVoo->hora = hora;
    novoVoo->minuto = minuto;
    novoVoo->aeroporto_saida = aeroporto_saida;
    novoVoo->aeroporto_chegada = aeroporto_chegada;
    novoVoo->rota = rota;
    novoVoo->tempo_estimado = tempo_estimado;
    novoVoo->passageiros = passageiros;
    novoVoo->prox = NULL;
    return novoVoo;
}

void cadastrarVoo(Voo **lista) {
    int numero, data, hora, minuto, aeroporto_saida, aeroporto_chegada, rota, passageiros;
    float tempo_estimado;

    printf("\nDigite os dados do novo voo:\n");
    printf("Numero do voo: ");
    scanf("%d", &numero);
    printf("Data do voo (1-Seg, ..., 8-Diario): ");
    scanf("%d", &data);
    printf("Horario do voo (hora e minuto): ");
    scanf("%d %d", &hora, &minuto);
    printf("ID do aeroporto de saida: ");
    scanf("%d", &aeroporto_saida);
    printf("ID do aeroporto de chegada: ");
    scanf("%d", &aeroporto_chegada);
    printf("ID da rota: ");
    scanf("%d", &rota);
    printf("Tempo estimado de voo (em horas): ");
    scanf("%f", &tempo_estimado);
    printf("Numero de passageiros a bordo: ");
    scanf("%d", &passageiros);

    Voo *novoVoo = criarVoo(numero, data, hora, minuto, aeroporto_saida, aeroporto_chegada, rota, tempo_estimado, passageiros);

    if (*lista == NULL) {
        *lista = novoVoo;
    } else {
        Voo *temp = *lista;
        while (temp->prox != NULL) {
            temp = temp->prox;
        }
        temp->prox = novoVoo;
    }

    printf("Voo cadastrado com sucesso!\n");
}

void consultaVoo(Voo *lista) {
    if (lista == NULL) {
        printf("Nenhum voo cadastrado.\n");
        return;
    }

    int numero;
    printf("\nDigite o numero do voo para consulta: ");
    scanf("%d", &numero);

    Voo *temp = lista;
    while (temp != NULL) {
        if (temp->numero == numero) {
            printf("\nInformacoes do voo:\n");
            printf("Numero do Voo: %d\n", temp->numero);
            printf("Data do Voo: %d\n", temp->data);
            printf("Horario do Voo: %02d:%02d\n", temp->hora, temp->minuto);
            printf("Aeroporto de Saida: %d\n", temp->aeroporto_saida);
            printf("Aeroporto de Chegada: %d\n", temp->aeroporto_chegada);
            printf("Rota: %d\n", temp->rota);
            printf("Tempo Estimado de Voo: %.2f horas\n", temp->tempo_estimado);
            printf("Passageiros a Bordo: %d\n", temp->passageiros);
            return;
        }
        temp = temp->prox;
    }

    printf("Voo nao encontrado.\n");
}

void removeVoo(Voo **lista) {
    if (*lista == NULL) {
        printf("Nenhum voo cadastrado.\n");
        return;
    }

    int numero;
    printf("\nDigite o numero do voo para remover: ");
    scanf("%d", &numero);

    Voo *temp = *lista;
    Voo *anterior = NULL;

    while (temp != NULL) {
        if (temp->numero == numero) {
            if (anterior == NULL) {
                *lista = temp->prox;
            } else {
                anterior->prox = temp->prox;
            }
            free(temp);
            printf("Voo removido com sucesso!\n");
            return;
        }
        anterior = temp;
        temp = temp->prox;
    }

    printf("Voo nao encontrado.\n");
}

int main() {
    Voo *listaVoos = NULL;
    int opcao;

    do {
        printf("\n*** MENU VOEBEM ***\n");
        printf("1. Cadastrar voo\n");
        printf("2. Consultar voo\n");
        printf("3. Remover voo\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarVoo(&listaVoos);
                break;
            case 2:
                consultaVoo(listaVoos);
                break;
            case 3:
                removeVoo(&listaVoos);
                break;
            case 4:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 4);

    Voo *temp;
    while (listaVoos != NULL) {
        temp = listaVoos;
        listaVoos = listaVoos->prox;
        free(temp);
    }

    return 0;
}

