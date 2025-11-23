#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/tarefas.h"

void addTarefa(Tarefa **lista, int *qtd, const char *titulo, const char *desc) {
    // Aumenta o tamanho da lista dinamicamente
    Tarefa *temp = realloc(*lista,(*qtd + 1) * sizeof(Tarefa));

    if (temp == NULL)
    {
        printf("Erro: Memória insufuciente!\n");
        return;
    }

    *lista = temp;

    // Define os dados da nova tarefa
    (*lista)[*qtd].id = *qtd + 1;
    strcpy((*lista)[*qtd].titulo, titulo);
    strcpy((*lista)[*qtd].descricao, desc);
    (*lista)[*qtd].concluida = 0;

    (*qtd)++;
    printf("Tarefa adicionada com sucesso!\n");
}

void removerTarefa(Tarefa **lista, int *qtd, int id) {
    int index = -1;

    // 1. Descobrir a posição (índice) da tarefa pelo ID
    for(int i = 0; i < *qtd; i++) {
        if((*lista)[i].id == id) {
            index = i;
            break;
        }
    }

    if(index == -1) {
        printf("Erro: ID %d nao encontrado.\n", id);
        return;
    }

    // 2. Realizar o deslocamento
    for(int i = index; i < *qtd - 1; i++) {
        (*lista)[i] = (*lista)[i + 1];
    }

    // 3. Atualizar a contagem
    (*qtd) --;

    // 4. Realocar a memória
    if(*qtd > 0) {
        Tarefa *temp = realloc(*lista, (*qtd) * sizeof(Tarefa));
        if (temp != NULL) {
            *lista = temp;
        }
    } else {
        free(*lista);
        *lista = NULL;
    }

    printf("Tarefa ID %d removida com sucesso!\n", id);
}

void concluirTarefa(Tarefa *lista, int qtd, int id) {
    int encontrou = 0;

    for (int i = 0; i < qtd; i++)
    {
        if (lista[i].id == id)
        {
            lista[i].concluida = 1; // Marca como concluída (1)
            printf("Sucesso: A tarefa '%s' foi marcada como conclúida!\n", lista[i].titulo);
            encontrou = 1;
            break; // Para o loop pois já achou   
        }
    }

    if(!encontrou) {
        printf("Erro: Tarefa com ID %d nao encontrada.\n", id);
    }
}

void liberarMemoria(Tarefa *lista) {
    free(lista);
}