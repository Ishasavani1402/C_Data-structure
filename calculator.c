#include <stdio.h>
#include <stdlib.h>
int main()
{

    while (1)
    {
        int n1, n2;
        int result;
        printf("\n enter first number:");
        scanf("%d", &n1);
        printf("\n enter second number:");
        scanf("%d", &n2);
        printf("\n calculator operations:");
        printf("\n -----------------------");
        printf("\n 1-addition");
        printf("\n 2-substraction");
        printf("\n 3-multiplication");
        printf("\n 4-division:");
        printf("\n 5-exit:");
        printf("\n -------------------------");
        int choice;
        printf("\n enter your choice for operations:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            result = n1 + n2;
            printf("\n addition of %d and %d is:%d", n1, n2, result);
            break;

        case 2:
            result = n1 - n2;
            printf("\n substraction of %d and %d is %d:", n1, n2, result);
            break;

        case 3:
            result = n1 * n2;
            printf("\n multiplication of %d and %d is %d", n1, n2, result);
            break;

        case 4:
            if (n2 == 0)
            {
                printf("\n division not possibal!!");
            }
            else
            {
                float result1;
                result1 = n1 / n2;
                printf("\n division of %d and %d is %f", n1, n2, result1);
            }
            break;

        case 5:
            printf("\n thank you for using calculator!");
            exit(0);
            break;
        default:
            printf("\n invalid choice");
            break;
        }
    }
    return 0;
}
