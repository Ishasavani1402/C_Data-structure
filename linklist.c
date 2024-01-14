#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *next; // struct node type pointer
};
 struct node *first = NULL,*second =NULL,*third=NULL,*four = NULL;
int displaylist(struct node *p)
{
    while (p != NULL)
    {
        printf("\n %d ", p->info);
        p = p->next;//update p on next node
    }
}

// insert element of first position

struct node *insertfirst(struct node *first, int info)
{
    struct node *p = (struct node *)malloc(sizeof(struct node)); // new node on heap daynamically..
    p->next = first;
    p->info = info;
    return p;
}

// insert in between

struct node *insertbetween(struct node *first, int info, int index)
{
    struct node *p = (struct node *)malloc(sizeof(struct node)); // new node on heap dayimaclly..
    struct node *ptr = first; // no change at first pointer.
    int i = 0;
    while (i != index - 1&&ptr!=NULL)
    {
        ptr = ptr->next;
        i++;
    }
    p->info = info;
    p->next = ptr->next;
    ptr->next = p;
    return first;
}

// insert in last
struct node *insertlast(struct node *first, int info)
{
    struct node *p = (struct node *)malloc(sizeof(struct node)); // new node on heap dayimaclly..
    struct node *ptr = first;//no change at pointer
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = p;
    p->info = info;
    p->next = NULL;
    return first;
}

// deletion in first
struct node *deletefirst(struct node *first)
{
    struct node *ptr = first;
    first = first->next;
    free(ptr);
    return first;
}

// delete in between
struct node *deletebetween(struct node *first, int index)
{
    struct node *ptr = first;
    struct node *q = first->next;
    int i = 0;
    while (i != index - 1&&ptr!=NULL)
    {
        ptr = ptr->next;
        q = q->next;
        i++;
    }
    ptr->next = q->next;    
    free(q);
    return first;
}

// delete at last
struct node *deletelast(struct node *first)
{
    struct node *ptr = first;
    struct node *q = first->next;
    int i = 0;
    while (q->next != NULL)
    {
        ptr = ptr->next;
        q = q->next;
    }
        ptr->next = NULL;
    free(q);
    return first;
}
int main()
{
    // int inde ;
    // create a new linked list(node)
   

    // allocation memoryvfor node
    first = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    four = (struct node *)malloc(sizeof(struct node));

    printf("\n Enter the element of first node: ");
    scanf("%d", &first->info);
    first->next = second;
    printf("\n Enter the element of second node:");
    scanf("%d", &second->info);
    second->next = third;
    printf("\n enter the element of third node:");
    scanf("%d", &third->info);
    third->next = four;
    printf("\n enter the element of four node:");
    scanf("%d", &four->info);
    four->next = NULL;

    printf("\nElements in Linked List are :");
    displaylist(first);

    // insert at first position
       first = insertfirst(first,90);
       printf("\n\n Elements after inserting 90 at beginning:");
       displaylist(first);

    // insert at bitween
       first = insertbetween(first,85,2);
       printf("\n\n Elements after inserting 85 :");
       displaylist(first);
    //    return 0;

    // insert at last
       first = insertlast(first,76);
       printf("\n\n Elements after appending 76 to end:");
       displaylist(first);

    // delete at first
      first = deletefirst(first);
      printf("\n after first node delete");
      displaylist(first);

    // delete at between
      first = deletebetween(first,2);
      printf("\n after 3 delete");
      displaylist(first);

    // delete at last
    first = deletelast(first);
    printf("\n after last element delete");
    displaylist(first);
    return 0;
}
