#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *prev, *next;
};

void display(struct node *p)
{
    // struct node *q;
    while (p != NULL)
    {
        
        printf("\n %d", p->info);
        p = p->next;
    }
    
}
void displayreverse(struct node*q)
{
    while (q != NULL)
    {
        printf("\n %d ", q->info);
        q = q->prev;
    }
}
// insert in first position
struct node *insertfirst(struct node *first, int info)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node)); // memory allocation for new node
    struct node *p = first;
    ptr->prev = NULL;
    ptr->next = first;
    ptr->info = info;
    return ptr;
}

// insert in between
struct node *insertbetween(struct node *first, int index, int info)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node)); // memory allocation for new node
    if (ptr == NULL)
    {
        printf("\n failed");
        return first;
    }
    struct node *p = first;
    ptr->info = info;
    //  ptr->prev =NULL;
    //  ptr->next = NULL;
    int i = 0;
    while (i != index - 1 && p != NULL)
    {
        p = p->next;
        i++;
    }
    ptr->prev = p;
    ptr->next = p->next;
    p->next = ptr;
    return first;
}

// insert last
struct node *insertlast(struct node *first, int info)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node)); // memory allocation for new node
    ptr->info = info;
    ptr->prev = NULL;
    if (ptr == NULL)
    {
        printf("\n failed");
        return first;
    }
    struct node *p = first;
    while (p->next != NULL)
    {
        p = p->next;
    }
    ptr->prev = p;
    ptr->next = NULL;
    p->next = ptr;
    return first;
}

// delete at first position
struct node *deletefirst(struct node *first)
{
    struct node *p = first;
    // struct nide* q = first->next;
    first = first->next;
    first->prev = NULL;
    free(p);
    return first;
}

// delete at between
struct node *deletebetween(struct node *first, int index)
{
    struct node *p = first;
    struct node *q = first->next;
    int i = 0;
    while (i != index - 1 && p != NULL)
    {
        p = p->next;
        q = q->next;
        i++;
    }
    p->next = q->next;
    if (q->next != NULL)
    {
        q->next->prev = p;
    }
    free(q);
    return first;
}

// delete last
struct node *deletelast(struct node *first)
{
    struct node *p = first;
    struct node *q = first->next;
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return first;
}

int main()
{
    struct node *first = NULL, *second = NULL, *third = NULL;

    // memory allocation
    first = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));

    
    printf("\n enter first node value:");
    scanf("%d", &first->info);
    first->prev = NULL;
    first->next = second;

    printf("\n enter second node value:");
    scanf("%d", &second->info);
    second->prev = first;
    second->next = third;

    printf("\n enter third node value:");
    scanf("%d", &third->info);
    third->prev = second;
    third->next = NULL;

    printf("\n display all element:");
    display(first);
    printf("\n reverse display");
    displayreverse(third);

    int ch, num, position;
    while (1)
    {
        printf("\n 1.insert at first position:");
        printf("\n 2. insert at between node");
        printf("\n 3.insert at last position:");
        printf("\n 4.delete at first position:");
        printf("\n 5.delete at between node:");
        printf("\n 6.delete at last position:");
        printf("\n 7.exit");
        printf("\n enter your choice:");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("\n enter the element to be inserted : ");
            scanf("%d", &num);
            first = insertfirst(first, num);
            display(first);
            break;
        case 2:
            printf("\n enter position for node:");
            scanf("%d", &position);
            printf("\n enter element:");
            scanf("%d", &num);
            first = insertbetween(first, position, num);
            display(first);
            break;

        case 3:
            printf("\n enter element:");
            scanf("%d", &num);
            first = insertlast(first, num);
            display(first);
            break;

        case 4:
            first = deletefirst(first);
            display(first);
            break;

        case 5:
            printf("\n enter position to delete element");
            scanf("%d", &position);
            first = deletebetween(first, position);
            display(first);
            break;

        case 6:
            first = deletelast(first);
            display(first);
            break;

        case 7:
            exit(0);
        }
    }
    return 0;
}