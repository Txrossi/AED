#define MAX_NODES 100



typedef enum 
{
    LIST_ERR_EMPTY = -3,
    LIST_ERR_FULL = -2,
    LIST_ERR_UNDEFINED = -1,
    LIST_ERR_OK = 1
}list_err;

typedef struct Node
{
    void *data;
    size_t data_size;
    struct Node *next;
} Node;

typedef struct
{
    Node nodes[MAX_NODES];   // Array fixo de nós
    uint8_t used[MAX_NODES]; // Marca os nós usados
    uint16_t count;
    uint8_t freeIndex;  // Próximo índice livre no buffer
    Node *head;
} LinkedList;

void initList(LinkedList *list);
list_err insertNode(LinkedList *list, void *data, size_t data_size);
list_err deleteNode(LinkedList *list, void *data, size_t data_size);