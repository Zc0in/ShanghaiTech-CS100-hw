#include<stdio.h>

int main()
{
    float MoodLevel = 100.0;
    int num, begin_hour, begin_minute, end_hour, end_minute, temp_hour, temp_munite, interval_w, interval_b;
    printf("How many lectures today?\n");
    scanf("%d",&num);
    temp_hour = 8;
    temp_munite = 0;
    for(int i = 0; i < num; i++)
    {
        scanf("%d:%d-%d:%d", &begin_hour, &begin_minute, &end_hour, &end_minute);
        interval_b = 60 * (begin_hour - temp_hour) + (begin_minute - temp_munite);
        interval_w = 60 * (end_hour - begin_hour) + (end_minute - begin_minute);
        if(MoodLevel < 100.0)
        {
            MoodLevel += 0.5 * interval_b;
        }

        if(MoodLevel >= 100.0)
        {
            MoodLevel = 100.0;
        }

        if(interval_w > 60)
        {
            MoodLevel -= (24 + (interval_w - 60) * 0.8);
        }
        else if(interval_w <= 60)
        {
            MoodLevel -= interval_w * 0.4;
        }
        temp_hour = end_hour;
        temp_munite = end_minute;
        
        if(MoodLevel <= 0)
        {
            printf("Gezi Wang has been sent to hospital.\n");
            return 0;
        }
    }

    interval_b = 60 * (22 - temp_hour) + (0 - temp_munite);

    if(MoodLevel < 100.0)
    {
        MoodLevel += 0.5 * interval_b;
    }

    if(MoodLevel >= 100.0)
    {
        MoodLevel = 100.0;
    }

    if(MoodLevel > 0)
    {
        printf("His mood level is %.1f at the end of the day.\n", MoodLevel);
    }
    else if(MoodLevel <= 0)
    {
        printf("Gezi Wang has been sent to hospital.\n");
    }

    return 0;
}