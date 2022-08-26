#include <stdio.h>
#include <string.h>

char plate[11], weekday[4], date[6], ans[100000], buffer[100000];
int last;

int judge(char p[11])
{
    int i;
    int m = 1;
    int n = 0;
    if(strlen(p) > 6 || strlen(p) < 5 || (int)(p[2]) == 47)
    {
        return 0;
    }
    for (i = 0; i < 6; i++)
    {
        if (p[i] == 'O' || p[i] == 'I')
        {
            return 0;
        }
    }
    if (p[5] != '\0')
    {
        if ((p[0] != 'D' && p[5] != 'F') || (p[0] == 'D' && p[5] == 'F'))
        {
            return 0;
        }
        else
        {
            if(p[0] == 'D' || p[0] == 'F')
            {
                for (i = 1; i < 6; i++)
                {
                    if ((int)(p[i]) >= 65)
                    {
                        return 0;
                    }
                }
            }
            if(p[5] == 'F' || p[5] == 'D')
            {
                for (i = 4; i >= 0; i--)
                {
                    if ((int)(p[i]) >= 65)
                    {
                        return 0;
                    }
                }
            }
            return 2;
        } 
    }
    else
    {
        for(i = 0; i < 5; i++)
        {
            if((int)(p[i]) < 65)
            {
                n += 1;
            }
        }
        if(n == 5)
        {
            return 1;
        }
      	n = 0;
      	if(p[0] >= 65 && p[4] >= 65)
        {
            for(i = 1; i < 4; i++)
            {
                if((int)(p[i]) < 65)
                {
                    n += 1;
                }
            }
            if(n == 3 && (p[1] != p[2] || p[1] != p[3]))
            {
                return 1;
            }
        }
        n = 0;
      	if(p[0] >= 65 && p[4] < 65)
        {
        	for(i = 1; i < 5; i++)
            {
                if((int)(p[i]) < 65)
                {
                    n += 1;
                }
            }
            if(n == 4 && (p[0] == 'T' || p[0] == 'X'))
            {
                return 2;
            }
            else if(n == 4 && (p[0] != 'T' && p[0] != 'X'))
            {
                return 1;
            }
        }
      	if(p[4] >= 65 && p[0] < 65)
        {
        	for(i = 0; i < 4; i++)
            {
                if((int)(p[i]) < 65)
                {
                    n += 1;
                }
            }
            if(n == 4)
            {
                return 1;
            }
        }
        for (i = 0; i < 3; i++)
        {
            if ((int)(p[i]) == (int)(p[i + 1]) && (int)(p[i]) == (int)(p[i + 2]))
            {
                m = 0;
                break;
            }
        }
        if(m == 1)
        {
            for (i = 0; i < 3; i++)
            {
                if ((int)(p[i]) >= 65 && (int)(p[i]) <= 90)
                {
                    if (i == 0 && (int)(p[i + 4]) >= 65 && (int)(p[i + 4]) <= 90)
                    {
                        for (int j = i + 1; j < 4; j++)
                        {
                            if ((int)(p[j]) >= 65 && (int)(p[j]) <= 90)
                            {
                                m = 0;
                            }
                        }
                        break;
                    }
                    for (int j = i + 2; j < 5; j++)
                    {
                        if ((int)(p[j]) >= 65 && (int)(p[j]) <= 90)
                        {
                            m = 0;
                            break;
                        }
                    }
                    if(m == 0)
                    {
                        break;
                    }
                }
                if(i == 2 && ((int)(p[3]) >= 65 && (int)(p[3]) <= 90) && ((int)(p[2]) < 65) && ((int)(p[4]) < 65))
                {
                    m = 0;
                }
            }
        }
        if (m == 0)
        {
            return 0;     
        }
        else
        {
            if(p[0] == 'T' || p[0] == 'X')
            {
                if ((int)(p[1]) >= 65)
                {
                    return 1;
                }
                else
                {
                    return 2;
                }
            }
            else
            {
                return 1;
            }
        }   
    }
    return 1;
}
int main()
{
    for (int i = 0; i < 3; i++)
    {
        gets(buffer);
        sscanf(buffer, "%s %s %s\n", plate, date, weekday);
        if (judge(plate) == 2)
        {
            strcat(ans, "This car is allowed to drive.\n");            
        }
        else if (judge(plate) == 0)
        {
            strcat(ans, "This number is invalid.\n");  
        }
        else if(judge(plate) == 1)
        {
            for (int i = 5; i >= 0; i--)
            {
                if ((int)(plate[i]) > 47 && (int)(plate[i]) < 58)
                {
                    last = (int)(plate[i]);
                    break;
                }
            }
            if (strcmp(weekday, "Sat") == 0 || strcmp(weekday, "Sun") == 0)
            {
                strcat(ans, "This car is allowed to drive.\n"); 
            }
            else if ((int)(date[4] % 2 == 0))
            {
                if (last % 2 == 0)
                {
                    strcat(ans, "This car is allowed to drive.\n");
                }
                else
                {
                    strcat(ans, "This car is not allowed to drive.\n");  
                }
            }
            else if((int)(date[4] % 2 != 0))
            {
                if (last % 2 == 1)
                {
                    strcat(ans, "This car is allowed to drive.\n"); 
                }
                else
                {
                    strcat(ans, "This car is not allowed to drive.\n"); 
                }
            }
        }
        
    }
    printf("%s", ans);
    return 0;
}