#include<stdio.h>
#include<stdlib.h>
#include <string.h>

char buffer[100000], order[10000], line[10000][10000], tem[10000], te[100000];
int n1, n2, n3, temp;
int main()
{
    int reg[6] = {0,0,0,0,0,0};
    int num;
    int PC = 1;
    int jud = 1;
    scanf("%d\n",&num);
    for(int i = 1; i <= num; i++)
    {
        gets(line[i]);    
    }
    while(PC <= num)
    {
        sscanf(line[PC], "%s", order);
        if(strcmp(order, "let") == 0)
        {
            sscanf(line[PC], "let x%d %d", &n1, &temp);
            reg[n1] = temp;
            PC += 1;
        }
        if(strcmp(order, "add") == 0)
        {
            sscanf(line[PC], "add x%d x%d x%d", &n1, &n2, &n3);
            reg[n1] = reg[n2] + reg[n3];
            PC += 1;
        }
        if(strcmp(order, "sub") == 0)
        {
            sscanf(line[PC], "sub x%d x%d x%d", &n1, &n2, &n3);
            reg[n1] = reg[n2] - reg[n3];
            PC += 1;
        }
        if(strcmp(order, "mul") == 0)
        {
            sscanf(line[PC], "mul x%d x%d x%d", &n1, &n2, &n3);
            reg[n1] = reg[n2] * reg[n3];
            PC += 1;
        }
        if(strcmp(order, "div") == 0)
        {
            sscanf(line[PC], "div x%d x%d x%d", &n1, &n2, &n3);
            reg[n1] = reg[n2] / reg[n3];
            PC += 1;
        }
        if(strcmp(order, "print") == 0)
        {
            sscanf(line[PC], "print x%d", &n1);
            printf("x%d = %d\n", n1, reg[n1]);
            PC += 1;
        }
        if(strcmp(order, "bge") == 0)
        {
            sscanf(line[PC], "bge x%d x%d %d", &n1, &n2, &temp);
            if(reg[n1] >= reg[n2])
            {
                PC = temp;
            }
            else
            {
                PC += 1;
            }
        }

    }
    return 0;
}