#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node *next;
} Node;

typedef struct LinkedList
{
    int size;
    Node *head;
    Node *tail;
} LinkedList;

void list_init(LinkedList *l)
{
    l->head = NULL;
    l->tail = NULL;
    l->size = 0;
}

void list_insert(LinkedList *l, int value)
{
    if (l->tail != NULL)
    {
        Node *tmp = (Node *)malloc(sizeof(Node));
        tmp->next = NULL;
        tmp->value = value;
        l->tail->next = tmp;
        l->tail = tmp;
        l->size += 1;
    }
    else
    {
        l->head= (Node *)malloc(sizeof(Node));
        l->tail= (Node *)malloc(sizeof(Node));
        l->tail->value = value;
        l->tail->next = NULL;
        l->head = l->tail;
        l->size += 1;
    }
}

void list_clear(LinkedList *l)
{
    l->size = 0;
    while(l->head)
    {
        Node *tmp = l->head;
        l->head = l->head->next;
        free(tmp);   
    }
    l->tail = NULL;
}

Node *list_remove(LinkedList *l, Node *target)
{

    Node *tmp = l->head;
    while(tmp != target && tmp)
    {
        tmp= tmp->next;
    }
    if(!tmp)
    {
        return NULL;
    }
    if(l->size == 1)
    {
        l->size -= 1;
        l->head = NULL;
        l->tail = NULL;
        return NULL;
    }
    else if(tmp == l->tail)
    {
        l->size -= 1;
        Node *temp = l->head;
        while(temp->next != l->tail)
        {
            temp = temp->next;
        }
        l->tail = temp;
        l->tail->next = NULL;
        free(tmp);
        return NULL;
    }
    else if(tmp == l->head)
    {
        l->size -= 1;
        Node *temp = l->head;
        l->head = l->head->next;
        free(temp);
        free(tmp);
        return l->head->next;
    }
    else
    {
        l->size -= 1;
        Node *temp = l->head;
        while(temp->next != tmp)
        {
            temp = temp->next;
        }
        temp->next = tmp->next;
        free(tmp);
        return temp->next;
    }   
}

int main()
{
    LinkedList *l = (LinkedList *)malloc(sizeof(LinkedList));
    list_init(l);
    list_insert(l, 1);
    list_insert(l, 2);
    list_insert(l, 3);
    // list_remove(l,l->tail);
    list_remove(l,l->head);
    // printf("%d\n", a->value);
    // list_clear(l);
    while(l->head)
    {
        printf("%d\n", l->head->value);
        l->head = l->head->next;
    }

    printf("finish\n");

    return 0;
}
