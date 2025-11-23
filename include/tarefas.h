#ifndef TAREFAS_H
#define TAREFAS_H

// Definição da estrutura da Tarefa
typedef struct 
{
    int id;
    char titulo[50];
    char descricao[100];
    int concluida; // 0 = Pendente, 1 = Feita
} Tarefa;

// Protótipos das funções (o que o programa faz)
// Funções do Core
void addTarefa(Tarefa **lista, int *qtd, const char *titulo, const char *desc);
void removerTarefa(Tarefa **lista, int *qtd, int id);
void concluirTarefa(Tarefa *lista, int qtd, int id);
void liberarMemoria(Tarefa *lista);

// Funções de IO 
void salvarDados(Tarefa *lista, int qtd, const char *arquivo);
void carregarDados(Tarefa **lista, int *qtd, const char *arquivo);

// Funções de View 
void listarTarefa(Tarefa *lista, int qtd);
void filtrarTarefas(Tarefa *lista, int qtd, int status);
#endif
