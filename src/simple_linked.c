#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "simple_linked.h"

#define OCCUPIED 1
#define FREE 0

/**
 * Inicializa a lista encadeada.
 */
void initList(LinkedList *list)
{
    list->head = NULL;
    list->count = 0;
    list->freeIndex = 0;
    memset(list->used, 0, sizeof(list->used));
}

/**
 * Verifica se a lista está cheia.
 */
static uint8_t isFull(LinkedList* list)
{
    return list->count >= MAX_NODES;
}

/**
 * Verifica se a lista está vazia.
 */
static uint8_t isEmpty(LinkedList* list)
{
    return list->count == 0;
}

/**
 * Aloca um nó dentro do array estático.
 */
static Node *allocateNode(LinkedList *list)
{
    if (isFull(list))
    {
        return NULL;
    }

    for (uint16_t i = list->freeIndex; i < MAX_NODES; i++)
    {
        if (list->used[i] == FREE)
        {
            list->used[i] = OCCUPIED;
            list->count++;
            list->freeIndex = i + 1;
            return &list->nodes[i];
        }
    }

    for (uint16_t i = 0; i < list->freeIndex; i++)
    {
        if (list->used[i] == FREE)
        {
            list->used[i] = OCCUPIED;
            list->count++;
            list->freeIndex = i + 1;
            return &list->nodes[i];
        }
    }

    return NULL;
}

/**
 * Insere um novo elemento na lista.
 */
list_err insertNode(LinkedList *list, void *data, size_t data_size)
{
    Node *newNode = allocateNode(list);

    if (newNode == NULL)
    {
        return LIST_ERR_FULL;
    }

    newNode->data = data;
    newNode->next = list->head;
    newNode->data_size = data_size;
    list->head = newNode;

    return LIST_ERR_OK; // Sucesso
}

/**
 * Remove um elemento da lista.
 */
list_err deleteNode(LinkedList *list, void *data, size_t data_size)
{
    Node *current_node = list->head;
    Node *previous_node = NULL;

    if (isEmpty(list))
    {
        return LIST_ERR_EMPTY;
    }

    for (uint16_t i = 0; i < MAX_NODES; i++)
    {
        if (list->used[i] == OCCUPIED)
        {
            if(memcmp(current_node->data, data, data_size) == 0)
            {
                if (previous_node == NULL)
                {
                    list->head = current_node->next;
                }
                else
                {
                    previous_node->next = current_node->next;
                }
                
                list->used[i] = FREE;
                memset(current_node->data, 0x00, data_size);
                list->count--;
                list->freeIndex = i;
                return LIST_ERR_OK;
            }
        previous_node = current_node;
        current_node = current_node->next;
        }
    }
    

    return -1;
}

