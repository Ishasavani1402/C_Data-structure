#include <stdio.h>

int liniarsearch(int arr[], int size, int seach)
{
    int i;
    for (i = 0; i < size; i++)
    {
        if (arr[i] == seach)
        {
            printf("\n %d present of location %d", seach, i + 1);
            break;
        }
    }
    if (i == size)
    {
        printf("\n not found");
    }
}

int binarysearch(int arr[], int size, int seach)
{
    int low, mid, hight;
    low = 0;
    hight = size - 1;
    
    printf("\n hight=%d",hight);

    while (low <= hight)
    {
        mid = (low + hight) / 2;
        if (arr[mid] == seach)
        {
            return mid;
        }
        else if (arr[mid] < seach)
        {
            low = mid + 1;
        }
        else if (arr[mid] > seach)
        {
            hight = mid - 1;
        }
    }
    return -1;
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 55, 65};
    int size, seach, i;
    size = sizeof(arr) / sizeof(int); // find array of size

    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n enter element for search");
    scanf("%d", &seach);
    // liniar search
    liniarsearch(arr, size, seach);
    
    // binary search
    int b = binarysearch(arr,size,seach);
    printf("\n Element %d is at index %d", seach,b);
    return 0;
}