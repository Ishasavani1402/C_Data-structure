#include <stdio.h>
#include <stdlib.h>

void insertionsort(int isort[], int size)
{
    int i, temp, j;
    for (i = 1; i <= size - 1; i++) // loop for all posible passes
    {
        temp = isort[i];
        j = i - 1;//  point to the last element of the previous pass
        while (isort[j] >=0 && isort[j] > temp)
        {
            isort[j + 1] = isort[j]; // shift the elements one position forward
            j--;
        }
        isort[j + 1] = temp; // insert the element in its correct place
    }
}
int main()
{
    int isort[10];
    int size = sizeof(isort) / sizeof(isort[0]);
    int i;
    for (i = 0; i < size; i++)
    {
        scanf("%d", &isort[i]);
    }
    printf("\n display");
    for (i = 0; i < size; i++)
    {
        printf("%d ", isort[i]);
    }
    insertionsort(isort, size);
    printf("\n after sorting:");
    for (i = 0; i < size; i++)
    {
        printf("%d ", isort[i]);
    }
}