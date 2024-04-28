#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    void *data;
    struct node *next;
} Node;

Node *initializeNode()
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->next = NULL;
    return node;
}

Node initializeLinkedList()
{
    Node node = *(Node *)malloc(sizeof(Node));
    node.next = NULL;
    return node;
}

void insertAtFirst(void *data, Node *head)
{
    Node *node = initializeNode();
    node->data = data;
    node->next = head->next;
    head->next = node;
}

void insertAtLast(void *data, Node **curr)
{

    if ((*curr)->next == NULL)
    {
        insertAtFirst(data, *curr);
        return;
    }

    while ((*curr)->next != NULL)
    {
        *curr = (*curr)->next;
    }
    Node *node = initializeNode();
    node->data = data;
    node->next = (*curr)->next;
    (*curr)->next = node;
}

void insertAtPosition(void *data, int position, Node *head)
{
    if (position < 1)
    {
        printf("\nInvalid position\n");
        return;
    }
    if (position == 1)
    {
        insertAtFirst(data, &(*head));
        return;
    }

    Node **curr = &head;
    int i = 1;
    while ((*curr)->next != NULL && i < position)
    {
        *curr = (*curr)->next;
        i++;
    }

    if (i < position)
    {
        printf("No. of available Elements less than the position");
    }
    else
    {
        Node *node = initializeNode();

        node->data = data;
        node->next = (*curr)->next;
        (*curr)->next = node;
    }
}

void deleteFromFirst(Node *head)
{
    if (head->next != NULL)
    {
        Node *data = head->next;
        head->next = data->next;
        free(data);
    }
}

void deleteFromLast(Node *head)
{
    if (head->next == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    if (head->next->next == NULL)
    {
        deleteFromFirst(&(*head));
        return;
    }

    Node *curr = head;
    while (curr->next->next->next != NULL)
    {
        curr = curr->next;
    }

    Node *temp = curr->next->next;
    curr->next->next = NULL;
    free(temp);
}

void deleteFromPosition(int position, Node *head)
{
    if (head->next == NULL)
    {
        printf("No Elements exists");
        return;
    }
    if (position == 1)
    {
        deleteFromFirst(head);
        return;
    }
    Node **curr = &head;
    int i = 1;
    while (i < position && (*curr)->next->next != NULL)
    {
        *curr = (*curr)->next;
        i++;
    }
    if (i < position)
    {
        printf("No. of available Elements less than the position");
    }
    else
    {
        Node *node = (*curr)->next;
        (*curr)->next = (*curr)->next->next;
        free(node);
    }
}

void printList(Node *head)
{
    Node *node = NULL;
    node = head;
    if (node->next == NULL)
        return;

    while (node->next != NULL)
    {
        void *data = node->next->data;

        if (sizeof(data) == sizeof(int *) || sizeof(data) == sizeof(long *))
        {
            printf("%d->", data);
        }
        else if (sizeof(data) == sizeof(char *))
        {
            printf("%c->", *((char *)data));
        }
        else if (sizeof(data) == sizeof(float *) || sizeof(data) == sizeof(double *))
        {
            printf("%f->", *((float *)data));
        }
        else
        {
            printf("%s->", data);
        }

        node = node->next;
    }
    printf("\n");
}

void main()
{

    Node head = initializeLinkedList();
    Node *currentNode = NULL;
    currentNode = &head;

    insertAtFirst(1, &head);
    insertAtLast(3, &currentNode);
    insertAtFirst(5, &head);
    printList(&head);
    insertAtPosition('r', 3, &head);
    insertAtPosition(7, 3, &head);
    insertAtLast('b', &currentNode);
    printList(&head);

    deleteFromFirst(&head);
    deleteFromFirst(&head);
    deleteFromFirst(&head);

    printList(&head);
    deleteFromLast(&head);
    insertAtLast("Girdhari", &currentNode);
    insertAtLast(23, &currentNode);
    printList(&head);
    deleteFromPosition(1, &head);
    insertAtLast("My name is Bhagchand", &currentNode);
    printList(&head);
    return;
}