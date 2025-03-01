#define MAX_NODES 100

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
    Node *head;
} LinkedList;

void initList(LinkedList *list);
int insert(LinkedList *list, void *data, size_t data_size);