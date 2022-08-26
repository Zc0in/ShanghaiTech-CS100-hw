#include <stdio.h>
#include<math.h>

void DrawSquare(int size)
{
    // YOUR CODE STARTS HERE
    int i, j;
    for(i = 1; i <= size; i++)
    {
        printf("*");
    }
    printf("\n");
    for(i = 1; i <= size - 2; i++)
    {
        printf("*");
        for(j = 1; j <= size - 2; j++)
        {
            printf(" ");
        }
        printf("*\n");
    }
    for(i = 1; i <= size; i++)
    {
        printf("*");
    }
    printf("\n");
    // YOUR CODE ENDS HERE
}

void DrawDiamond(int size)
{    
    // YOUR CODE STARTS HERE
    int i, j, m, n;
    for(i = 1; i <= size - 1; i++)
    {
        printf(" ");
    }
    printf("*\n");
    m = -1;
    n = size - 1;
    for(i = 1; i <= 2 * size - 3; i++)
    {
        if(n - i >= 0)
        {
            for(j = 1; j <= n - i; j ++)
            {
                printf(" ");
            }
            printf("*");
            m += 2;
            for(j = 1; j <= m; j++)
            {
                printf(" ");
            }
        }
        else
        {
            for(j = 1; j <= i - n; j ++)
            {
                printf(" ");
            }
            printf("*");
            m -= 2;
            for(j = 1; j <= m; j++)
            {
                printf(" ");
            }
        }
        printf("*\n");
    }
    for(i = 1; i <= size - 1; i++)
    {
        printf(" ");
    }
    printf("*\n");
    // YOUR CODE ENDS HERE
}


void DrawHexagon(int size)
{
    // YOUR CODE STARTS HERE
    int i, j, m, n;
    for(i = 1; i <= size - 1; i++)
    {
        printf(" ");
    }
    for(i = 1; i <= size - 1; i++)
    {
        printf("*");
    }
    printf("*\n");
    m = size - 2;
    n = size - 1;
    for(i = 1; i <= 2 * size - 3; i++)
    {
        if(n - i >= 0)
        {
            for(j = 1; j <= n - i; j ++)
            {
                printf(" ");
            }
            printf("*");
            m += 2;
            for(j = 1; j <= m; j++)
            {
                printf(" ");
            }
        }
        else
        {
            for(j = 1; j <= i - n; j ++)
            {
                printf(" ");
            }
            printf("*");
            m -= 2;
            for(j = 1; j <= m; j++)
            {
                printf(" ");
            }
        }
        printf("*\n");
    }
    for(i = 1; i <= size - 1; i++)
    {
        printf(" ");
    }
    for(i = 1; i <= size - 1; i++)
    {
        printf("*");
    }
    printf("*\n");
    // YOUR CODE ENDS HERE
}


int main()
{
    int shape, size;
    scanf("%d %d", &shape, &size);
    
    // 1 for square, 2 for diamond, 3 for hexagon.
    switch(shape){
    case 1:
        DrawSquare(size);
        break;
    case 2:
        DrawDiamond(size);
        break;
    case 3:
        DrawHexagon(size);
        break;
    default:
        return -1;
    }
    return 0;
}

