#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <simple_linked.h>

#define OCCUPIED 1
#define FREE 0

/**
 * Inicializa a lista encadeada.
 */
void initList(LinkedList *list)
{
    list->head = NULL;
    list->count = 0;
    memset(list->used, 0, sizeof(list->used));
}

/**
 * Aloca um nó dentro do array estático.
 */
static Node *allocateNode(LinkedList *list)
{
    if (list->count >= MAX_NODES)
    {
        return NULL;
    }
    else
    {
        for (uint16_t i = 0; i < MAX_NODES; i++)
        {
            if (list->used[i] == FREE)
            {
                list->used[i] = OCCUPIED;
                list->count++;
                return &list->nodes[i];
            }
        }
        return NULL;
    }
}

/**
 * Insere um novo elemento na lista.
 */
int insertNode(LinkedList *list, void *data, size_t data_size)
{
    Node *newNode = allocateNode(list);

    if (newNode == NULL)
    {
        return 0;
    }

    newNode->data = data;
    newNode->next = list->head;
    newNode->data_size = data_size;
    list->head = newNode;

    return 1; // Sucesso
}


/**
 * Insere um novo elemento na lista.
 */
int deleteNode(LinkedList *list, void *data, size_t data_size)
{
    Node *current_node = list->head;

    while(current_node != NULL)
    {
        if(memcmp(current_node->data,data, data_size) == 0)
        {
            Node *temp_node = current_node->next;
            memset(current_node->data, 0x00, data_size);
            current_node = temp_node;
            break;
        }
        current_node = current_node->next;
    }
    return -1;
}
