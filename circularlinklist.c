#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct node
{
    int info;
    struct node *next;
};
struct node *first = NULL, *second = NULL, *third = NULL; // create a new node

int displaylist(struct node *p, struct node *first)
{
    do
    {
        printf("\n %d", p->info);
        p = p->next;
    } while (p != first);
}

// insert in first position

struct node *insertfirst(struct node *first, int info)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node)); // memory allocation for new mode on heap
    ptr->info = info;
    struct node *p = first;
    if (first == NULL)
    {
        ptr->next = ptr;
        return ptr;
    }
    while (p->next != first)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = first;
    return ptr;
}

// insert between
struct node *insertbetween(struct node *first, int info, int index)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node)); // memory allocate for new node
    struct node *p = first;
    ptr->info = info;
    int i = 0;
    while (i != index - 1 && p != NULL)
    {
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    p->next = ptr;
    return first;
}

// insert last
struct node *insertlast(struct node *first, int info)

{
    struct node *ptr = (struct node *)malloc(sizeof(struct node)); // memory allocation for new node.
    struct node *p = first;
    ptr->info = info;
    while (p->next != first)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = first;
    return first;
}

// delete in first
struct node *deletefirst(struct node *first)
{

    struct node *p = first;
    struct node *q = first->next;
    while (q->next != first)
    {
        q = q->next;
    }

    q->next = first->next;
    first = first->next;
    free(p);
    return first;
}

// delete in between
struct node *deletebetween(struct node *first, int index)
{
    struct node *p = first;
    struct node *q = first->next;
    int i = 0;
    while (i != index - 1 && p != first)
    {
        p = p->next;
        q = q->next;
        i++;
    }
    p->next = q->next;
    q->next = first;
    free(q);
    return first;
}

// delete in last
struct node *deletelast(struct node *first)
{
    struct node *p = first;
    struct node *q = first->next;
    while (q->next != first)
    {
        p = p->next;
        q = q->next;
    }
    p->next = first;
    free(q);
    return first;
}

int main()
{

    first = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));

    printf("\n enter first node value:");
    scanf("%d", &first->info);
    first->next = second;

    printf("\n enter second node value:");
    scanf("%d", &second->info);
    second->next = third;

    printf("\n enter third node value:");
    scanf("%d", &third->info);
    third->next = first;

    printf("\n display list");
    displaylist(first, first);

    // insert at first
    first = insertfirst(first, 90);
    printf("\n after insert 90 at first position");
    displaylist(first, first);

    // insert in between
    first = insertbetween(first, 88, 2);
    printf("\n after insert 88 at 2nd position:");
    displaylist(first, first);

    // insert in last
    first = insertlast(first, 900);
    printf("\n after insert 900 in last position:");
    displaylist(first, first);

    // delete at first
    first = deletefirst(first);
    printf("\n after deleting the element from the beginning of the list:");
    displaylist(first, first);

    // delete in between
    first = deletebetween(first, 2);
    printf("\n after deleting the element at 2nd position:");
    displaylist(first, first);

    // delete in last
    first = deletelast(first);
    printf("\n after deleting the element from the end of the list:");
    displaylist(first, first);

    return 0;
}