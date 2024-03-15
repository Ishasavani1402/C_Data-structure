#include <stdio.h>
#include <stdlib.h>

void inputarray(int sort[],int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        scanf("%d", &sort[i]);
    }
    for (i = 0; i < size; i++)
    {
        printf("%d ", sort[i]);
    }
}

void bubblesort(int sort[], int size)
{
    int i, j, issorted = 0;
    for (i = 0; i < size - 1; i++) // for num of passes
    {
        issorted = 1; //  assume this iteration will  be sorted

        for (j = 0; j < size - 1 - i; j++) // for num of comparision of each passes
        {

            if (sort[j] > sort[j + 1])
            {
                int temp = sort[j];
                sort[j] = sort[j + 1];
                sort[j + 1] = temp;
                issorted = 0;
            }
        }
        if (issorted == 1)
            break;
    }
}
int main()
{
    int sort[10];
    int size = sizeof(sort) / sizeof(sort[0]);
    int i;
    printf("\n enter array elemnt:");
    inputarray(sort,size);
    bubblesort(sort, size);
    printf("\nAfter sorting\n");
     for (i = 0; i < size; i++)
    {
        printf("%d ", sort[i]);
    }
    return 0;
}