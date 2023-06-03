#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    char name[20];
    int value;
    struct node *next;
} Node;

Node *new_item(char *name, int value)
{

    Node *newp;
    if ((newp = (Node *)malloc(sizeof(Node))) == NULL)
    {

        fprintf(stderr, "new_item: error en malloc\n");
        exit(1);
    }
    strcpy(newp->name, name);
    newp->value = value;
    newp->next = NULL;
    return newp;
}

Node *add_front(Node *listp, Node *newp)
{

    newp->next = listp;
    return newp;
}

Node *add_end(Node *listp, Node *newp)
{

    Node *p;
    if (listp == NULL)
        return newp;

    for (p = listp; p->next != NULL; p = p->next)
        ;
    p->next = newp;
    return listp;
}

int main()
{

    return 0;
}
