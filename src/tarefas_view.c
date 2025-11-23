#include <stdio.h>
#include <string.h>
#include "../include/tarefas.h"



void listarTarefa(Tarefa *lista, int qtd) {
    if (qtd == 0)
    {
        printf("\nNenhuma tarefa cadastrada.\n");
        return;
    }
    printf("\n--- Lista de Tarefas ---\n");
    for (int i = 0; i < qtd; i++)
    {
        printf("[%c] ID: %d | %s -%s\n",
        lista[i].concluida ? 'X' : ' ',
        lista [i].id,
        lista[i].titulo,
        lista[i].descricao);
    }
}

void filtrarTarefas(Tarefa *lista, int qtd, int status) {
    int encontrou = 0;

    // Define o texto do cabeçalho baseado no status solicitado
    char *statusDesc = (status == 1) ? "CONCLUIDAS" : "PENDENTES";
    printf("\n--- Tarefas: %s ---\n", statusDesc);

    for (int i = 0; i < qtd; i++) {

        if(lista[i].concluida == status) {
            printf("[%c] ID: %d | %s - %s\n",
            lista[i].concluida ? 'X' : ' ',
            lista[i].id,
            lista[i].titulo,
            lista[i].descricao);
    encontrou = 1;
        }
    }

    if(!encontrou) {
        printf("Nenhuma tarefa encontrada com este status.\n");
    }
}

void buscarPorPalavra(Tarefa *lista, int qtd, const char *palavra) {
    printf("\n--- Buscando por: '%s' ---\n", palavra);
    int encontrou = 0;
    
    for (int i = 0; i < qtd; i++) {
        // strstr verifica se 'palavra' existe dentro do titulo OU descricao
        if (strstr(lista[i].titulo, palavra) != NULL || 
            strstr(lista[i].descricao, palavra) != NULL) {
            
            printf("[%c] ID: %d | %s - %s\n", 
                   lista[i].concluida ? 'X' : ' ', 
                   lista[i].id, 
                   lista[i].titulo, 
                   lista[i].descricao);
            encontrou = 1;
        }
    }
    
    if (!encontrou) printf("Nenhuma tarefa contendo '%s' encontrada.\n", palavra);
}

