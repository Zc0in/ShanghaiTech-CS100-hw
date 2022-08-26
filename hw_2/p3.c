#include <stdio.h>
#include <stdlib.h>

int a[100000];

void FindSecondMaxAndMin(int* secondMax, int* secondMin)
{
    // YOUR CODE STARTS HERE
    int num, i, j, t;
    scanf("%d", &num);
    for(i = 0; i < num; i++)
    {
        scanf("%d", &a[i]);
    }
    for(i = 0; i < num; i++)
    {
        for(j = num - 1; j > i; j--)
        {
            if(a[j] <= a[j - 1])
            {
                t = a[j - 1];
                a[j - 1] = a[j];
                a[j] = t;
            }
        }
    }
    *secondMax = a[num - 2];
    *secondMin = a[1];
    // YOUR CODE ENDS HERE
}

int main()
{
    int secondMax, secondMin;
    FindSecondMaxAndMin(&secondMax, &secondMin);
    printf ("%d %d\n", secondMax, secondMin);
    return 0;
}
