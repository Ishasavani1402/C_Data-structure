#include <stdio.h>
void displayarray(int qsort[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", qsort[i]);
    }
}

int partition(int qsort[], int low, int high)
{
    int pivot = qsort[low];
    int i = low + 1;
    int j = high;

    do
    {
        while (qsort[i] <= pivot)
        {
            i++;
            
        }
        while (qsort[j]>pivot)
        {
            j--;
        }
        
        
        if (i < j)
        {
            //swap i and j
            int temp = qsort[i];
            qsort[i] = qsort[j];
            qsort[j] = temp;
        }

    } while (i < j);
    // swap pivot and j
    int temp = qsort[low];
    qsort[low] = qsort[j];
    qsort[j] = temp;
    return j;
}
void quicksort(int qsort[], int low, int high)
{
    int partitionindex; // index of pivot after partition
    partitionindex = partition(qsort, low, high);
    if (low < high)
    {
        quicksort(qsort, low, partitionindex - 1);  // sort left subarrat
        quicksort(qsort, partitionindex + 1, high); // sort right subarray
    }
}
int main()
{
    int qsort[] = {3, 5, 2, 13, 12, 3, 2, 13, 45};
    int size = sizeof(qsort) / sizeof(qsort[0]);
    int low = 0, high = size - 1;
    printf("\n before sorting:");
    displayarray(qsort, size);
    printf("\n after sorting:");
    quicksort(qsort, low, high);
    displayarray(qsort, size);
    return 0;
}


