char mj[14][3];
int flag[14];
int ans = 0;
int num[44];


int judge(int n)
{
    if (n >= 0 && n < 4)
    {
        for (int i = 0; i < 14; i++)
        {
            for (int j = i + 1; j < 14; j++)
            {
                for (int k = j + 1; k < 14; k++)
                {
                    if (strcmp(mj[i], mj[j]) == 0 && strcmp(mj[i], mj[k]) == 0 && flag[i] == 0 && flag[j] == 0 && flag[k] == 0)
                    {
                        flag[i] = 1;
                        flag[j] = 1;
                        flag[k] = 1;
                        int ans = judge(n + 1);
                        flag[i] = 0;
                        flag[j] = 0;
                        flag[k] = 0;
                        if (ans == 4)
                        {
                            return 4;
                        }
                    }
                    else if (strcmp(&mj[i][1], &mj[j][1]) == 0 && strcmp(&mj[i][1], &mj[k][1]) == 0 && flag[i] == 0 && flag[j] == 0 && flag[k] == 0)
                    {
                        if ((mj[j][0] - mj[i][0] == 1 && mj[k][0] - mj[j][0] == 1))
                        {
                            if(mj[i][1] != 'z')
                            {
                                flag[i] = 1;
                                flag[j] = 1;
                                flag[k] = 1;
                                int ans = judge(n + 1);
                                flag[i] = 0;
                                flag[j] = 0;
                                flag[k] = 0;
                                if (ans == 4)
                                {
                                    return 4;
                                }
                            }
                            
                        }
                    }
                    
                }
            }
        }
    }
    if (n == 4)
    {
        for (int i = 0; i < 14; i++)
        {
            for (int j = i + 1; j < 14; j++)
            {
                if (strcmp(mj[i], mj[j]) == 0 && flag[i] == 0 && flag[j] == 0)
                {
                    flag[i] = 1;
                    flag[j] = 1;
                    int ans = judge(n + 1);
                    flag[i] = 0;
                    flag[j] = 0;
                    if (ans == 4)
                    {
                        return 4;
                    }
                }
            }
        }
    }
    if (n == 5)
    {
        return 4;
    }
    if (n == 0)
    {
        return 0;
    }
    judge(n - 1);
}
int CheckWin(char *mahjongHand[])
{
    for (int i = 0; i < 14; i++)
    {
        strcpy(mj[i], mahjongHand[i]);
    }
    for (int i = 0; i < 14; i++)
    {
        for(int j = 13; j > i; j--)
        {
            if(strcmp(&mj[j][1], &mj[j - 1][1]) <= 0)
            {
                char t[4];
                strcpy(t, mj[j - 1]);
                strcpy(mj[j - 1], mj[j]);
                strcpy(mj[j], t);
            }
        }
    }
    for (int i = 0; i < 14; i++)
    {
        for(int j = 13; j > i; j--)
        {
            if(strcmp(&mj[j][0], &mj[j - 1][0]) <= 0 && strcmp(&mj[j][1], &mj[j - 1][1]) == 0)
            {
                char t[4];
                strcpy(t, mj[j - 1]);
                strcpy(mj[j - 1], mj[j]);
                strcpy(mj[j], t);
            }
        }
    }
    if (judge(0) == 4)
    {
        return 1;
    }
    return 0;
}

int count(int n)
{
    if (n == 5)
    {
        return 1;
    }
    if(n == 0)
    {
        for(int i = 1; i < 38; i++)
        {
            if(num[i] >= 2)
            {
                num[i] -= 2;
                int a = count(n + 1);
                num[i] += 2;
                if(a == 1)
                {
                    return 1;
                }
            }
        }
    }
    if (n >= 1 && n < 5)
    {
        for (int i = 1; i < 38; i++)
        {
            if (num[i] >= 3)
            {
                num[i] -= 3;
                int a = count(n + 1);
                num[i] += 3;
                if (a == 1)
                {
                    return 1;
                }
            }
            else if (i < 30 && num[i] >= 1 && num[i + 1] >= 1 && num[i + 2] >= 1)
            {
                num[i] -= 1;
                num[i + 1] -= 1;
                num[i + 2] -= 1;
                int a = count(n + 1);
                num[i] += 1;
                num[i + 1] += 1;
                num[i + 2] += 1;
                if (a == 1)
                {
                    return 1;
                }
            }
        }
    }
    
    if(n == -1)
    {
        return 0;
    }
    count(n - 1);
}

int CountWaitingTiles(char *currentTiles[])
{
    
    int ans = 0;
    int f = 0;

    memset(num, 0, sizeof(num));
    memset(flag, 0, sizeof(flag));
    for (int i = 0; i < 13; i++)
    {
        strcpy(mj[i], currentTiles[i]);
        if (mj[i][1] == 'p')
        {
            num[mj[i][0] - '0'] += 1;
        }
        if (mj[i][1] == 's')
        {
            num[10 + mj[i][0] - '0'] += 1;
        }
        if (mj[i][1] == 'm')
        {
            num[20 + mj[i][0] - '0'] += 1;
        }
        if (mj[i][1] == 'z')
        {
            num[30 + mj[i][0] - '0'] += 1;
        }
    }
    for(int i = 1; i < 44; i++)
    {
        if(num[i] < 4 && (i % 10 != 0) )
        {
            num[i] += 1;}

            f = 0;
            num[i] -= 1;
        }
    }
    return ans;
}