#include <stdio.h>
#include <string.h>
#include "../include/tarefas.h"

int main() {
    Tarefa *minhasTarefas = NULL;
    int quantidade = 0, opcao, idBusca;
    char titulo[50], desc[100];

    // Carrega dados ao iniciar
    carregarDados(&minhasTarefas, &quantidade, "data/dados.bin");

    do
    {
        printf("\n=== GERENCIADOR DE TAREFAS ===\n");
        printf("1. Nova Tarefa\n");
        printf("2. Listar Tarefas\n");
        printf("3. Remover Tarefa\n");
        printf("4. Filtrar Tarefas\n");
        printf("5. Concluir Tarefa\n"); 
        printf("6. Sair e Salvar\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        getchar(); // Limpar buffer

        switch (opcao) 
        {
        case 1:
            printf("Titulo: ");
            fgets(titulo, 50, stdin);
            titulo[strcspn(titulo, "\n")] = 0; // Remove o \n 

            printf("Descricao: ");
            fgets(desc, 100, stdin);
            desc[strcspn(desc, "\n")] = 0;

            addTarefa(&minhasTarefas, &quantidade, titulo, desc);
            break;

            case 2:
            listarTarefa(minhasTarefas, quantidade);
            break;

              case 3:
            printf("Digite o ID da tarefa para remover: ");
            scanf("%d", &idBusca);
            removerTarefa(&minhasTarefas, &quantidade, idBusca);
            break;

            case 4:
            printf("\n--- FILTRO DE VISUALIZACAO ---\n");
                printf("1. Listar Tudo\n");
                printf("2. Apenas Pendentes\n");
                printf("3. Apenas Concluidas\n");
                printf("Opcao: ");
                
                int opcaoFiltro;
                scanf("%d", &opcaoFiltro);
                getchar(); // Limpar buffer

                if (opcaoFiltro == 1) {
                    listarTarefa(minhasTarefas, quantidade);
                } else if (opcaoFiltro == 2) {
                    filtrarTarefas(minhasTarefas, quantidade, 0); // 0 = Pendente
                } else if (opcaoFiltro == 3) {
                    filtrarTarefas(minhasTarefas, quantidade, 1); // 1 = Concluida
                } else {
                    printf("Opcao de filtro invalida.\n");
                }
                break;


            case 5:
            printf("Digite o ID da tarefa para concluir: ");
            scanf("%d", &idBusca);
            concluirTarefa(minhasTarefas, quantidade, idBusca);
            break;

            case 6:
            salvarDados(minhasTarefas, quantidade, "data/dados.bin");
            liberarMemoria(minhasTarefas);
            printf("Saindo e salvando dados...\n");
            break;

            default:
            printf("Opcao invalida!\n");
        }
    } while (opcao != 6);
    
    return 0;
}