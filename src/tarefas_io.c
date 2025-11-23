#include <stdio.h>
#include <stdlib.h>
#include "../include/tarefas.h"

// Persistência em Arquivo Binário (Mais eficiente que texto)
void salvarDados(Tarefa *lista, int qtd, const char *arquivo) {
    FILE *f = fopen(arquivo, "wb"); // wb = write binary
    if (f == NULL)
    {
        printf("Erro ao abrir arquivo para salvar.\n");
        return;
    }
    fwrite(&qtd, sizeof(int), 1, f); // Salva a quantidade primeiro
    fwrite(lista, sizeof(Tarefa), qtd, f); // Salva o array inteiro
    fclose(f);
    printf("Dados salvos em %s\n", arquivo);
}

void carregarDados(Tarefa **lista, int *qtd, const char *arquivo) {
    FILE *f = fopen(arquivo, "rb");
    if (f == NULL) return; // Arquivo não existe ainda

    fread(qtd, sizeof(int), 1, f);

    *lista = malloc((*qtd) * sizeof(Tarefa));
    fread(*lista, sizeof(Tarefa), *qtd, f);

    fclose(f);
    printf("%d tarefas carregadas do disco.\n", *qtd);
}
