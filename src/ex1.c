#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <simple_linked.h>

/* Linked list exercise: */

// Implemente um sistema simples de gerenciamento de tarefas usando uma lista encadeada. O sistema deve permitir:

// Adicionar uma nova tarefa com um identificador (ID), uma descrição e um status (pendente ou concluído).
// Remover uma tarefa pelo ID.
// Marcar uma tarefa como concluída pelo ID.
// Listar todas as tarefas mostrando seu ID, descrição e status.

#define MAX_NAME_SIZE 50

typedef enum
{
    TASK_FINISHED = 0,
    TASK_PROGRESS,

} task_status_en;
typedef struct
{
    uint8_t id;
    task_status_en status;
    char description[100];

} tarefa_t;

/**
 * @brief Prints the names and ages of all people in the linked list.
 *
 * @param list A pointer to the linked list containing pessoa_t elements.
 */

void printNameList(LinkedList *list)
{
    Node *current_node = list->head;

    while (current_node != NULL)
    {
        tarefa_t *aux_pessoa = (tarefa_t *)current_node->data;
        printf("ID %d - Description - %s \n", aux_pessoa->id, aux_pessoa->description);
        current_node = current_node->next;
    }
}

int main()
{
    LinkedList list = {0};

    tarefa_t tarefa[10];

    memset(tarefa, 0x00, sizeof(tarefa)); // Initialize the array with zeros

    initList(&list);

    static int opcao;

    while (list.count < 10)
    { // Loop infinito até o usuário escolher sair
        printf("\nMenu:\n");
        printf("1 - Adicionar tarefa\n");
        printf("2 - Remover tarefa\n");
        printf("3 - Sair\n");
        printf("Escolha uma opcao: ");

        scanf("%d", &opcao);

        if (opcao == 1)
        {
            uint8_t idx = 0;

            //pegar ID automaticamente
            for(uint8_t i = 0; i < sizeof(tarefa) / sizeof(tarefa_t); i++)
            {
                if(tarefa[i].status == TASK_FINISHED)
                {
                    idx = i;
                    break;
                }
            }
            tarefa[idx].id = idx;

            printf("Digite a descrição da tarefa: ");
            scanf(" %[^\n]", tarefa[idx].description); // Le uma string com espacos

            printf("Tarefa adicionada! ID: %d, Descriçao: %s\n", tarefa[idx].id, tarefa[idx].description);

            if (insertNode(&list, &tarefa[idx], sizeof(tarefa[idx])) == 1)
            {
                tarefa[idx].status = TASK_PROGRESS;
            }
        }
        else if (opcao == 2)
        {
            uint8_t id;

            printf("Digite o ID da tarefa a ser removida: ");
            scanf("%hhd", &id);

            if (deleteNode(&list, &id, sizeof(tarefa->id)))
            {
                printf("Tarefa %hhd removida!\n", id);
                // colocar o status da tarefa como concluida
                for (uint8_t i = 0; i < sizeof(tarefa) / sizeof(tarefa_t); i++)
                {
                    tarefa[i].status = tarefa[i].id == id ? TASK_FINISHED : TASK_PROGRESS;
                }
            }
            else
            {
                printf("Elemento nao encontrado\n");
            }
        }
        else if (opcao == 3)
        {
            printf("Saindo...\n");
            break; // Sai do loop
        }
        else
        {
            printf("Opção inválida! Tente novamente.\n");
        }

        printf("-----------------------------\n");
        printNameList(&list);
        printf("-----------------------------\n");
    }

    return 0;
}
