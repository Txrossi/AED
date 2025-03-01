#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <simple_linked.h>

/* Linked list exercise: */

#define MAX_NAME_SIZE 50

typedef struct
{
    char nome[MAX_NAME_SIZE];
    uint8_t idade;
} pessoa_t;

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
        pessoa_t *aux_pessoa = (pessoa_t *)current_node->data;
        printf("Nome %s - Idade - %d \n", aux_pessoa->nome, aux_pessoa->idade);
        current_node = current_node->next;
    }
}

int main()
{
    LinkedList list = {0};

    initList(&list);

    pessoa_t p1 = {"Joao", 25};
    pessoa_t p2 = {"Maria", 30};
    pessoa_t p3 = {"Carlos", 35};
    pessoa_t p4 = {"Ana", 28};

    insert(&list, &p1, sizeof(pessoa_t));
    insert(&list, &p2, sizeof(pessoa_t));
    insert(&list, &p3, sizeof(pessoa_t));
    insert(&list, &p4, sizeof(pessoa_t));

    printNameList(&list);

    return 0;
}