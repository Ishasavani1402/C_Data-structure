#include <stdio.h>
void display(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}

void insertele(int arr[], int pos, int e, int size)
{
    int i;
    for (i = size - 1; i >= pos; i--)
    {
        arr[i + 1] = arr[i];
    }
        arr[pos] = e;
}

void deleteele(int arr[], int pos,int size)
{
    int i;
    for (i = pos; i < size-1; i++)
    {
        arr[i] = arr[i + 1];
    }
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int pos, e;
    int size = sizeof(arr)/sizeof(arr[0]);
    display(arr, size);
    printf("\n enter position ");
    scanf("%d", &pos);
    printf("\n enter ele");
    scanf("%d", &e);
    insertele(arr, pos,e,size);
    size++;
    printf("\n after insertion\n");
    display(arr, size);
    printf("\n enter element to be deleted");
    scanf("%d",&pos);
    deleteele(arr, pos,size);
    size--;
    printf("after deletion \n");
    display(arr,size);
}