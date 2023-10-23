#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *weeks[7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
int month_day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

typedef struct
{
    int year;
    int month;
    int day;
    int week;
} date;

date *create_date()
{
    date *date1 = (date *)malloc(sizeof(date));
    if (date1 == NULL)
    {
        printf("内存分配失败。\n");
        exit(1);
    }
    printf("请输入[年 月 日]：");
    scanf("%d %d %d", &date1->year, &date1->month, &date1->day);
    return date1;
}

int is_leap(date *para)
{
    return (para->year % 400 == 0) || ((para->year % 4 == 0) && (para->year % 100 != 0));
}

date *sub_day_1(date *date1)
{
    date1->week = (date1->week - 1 + 7) % 7;
    date1->day--;

    if (date1->day == 0)
    {
        date1->month--;

        if (date1->month == 0)
        {
            date1->month = 12;
            date1->year--;
        }

        date1->day = (date1->month == 2 && is_leap(date1)) ? 29 : month_day[date1->month - 1];
    }

    return date1;
}

date *add_day_1(date *date1)
{
    date1->week = (date1->week + 1) % 7;
    date1->day++;

    if (date1->day > month_day[date1->month - 1])
    {
        date1->day = 1;
        date1->month++;

        if (date1->month > 12)
        {
            date1->month = 1;
            date1->year++;
        }
    }

    return date1;
}

void week(date *date1)
{
    date temp = {2023, 8, 7, 1};

    while (temp.year != date1->year || temp.month != date1->month || temp.day != date1->day)
    {
        if (temp.year > date1->year || (temp.year == date1->year && (temp.month > date1->month || (temp.month == date1->month && temp.day > date1->day))))
        {
            sub_day_1(&temp);
        }
        else
        {
            add_day_1(&temp);
        }
    }

    date1->week = temp.week;
    printf("%d年%d月%d日是星期%s\n", date1->year, date1->month, date1->day, weeks[date1->week]);
}

void day(date *date1)
{
    int i = 1;
    date temp = *date1;

    while (temp.day != 1 || temp.month != 1)
    {
        sub_day_1(&temp);
        i++;
    }

    printf("%d年%d月%d日是一年中的第%d天\n", date1->year, date1->month, date1->day, i);
}

void Calendar(date *para)
{
    int cal_max;
    if (is_leap(para))
    {
        month_day[1] = 29;
    }
    cal_max = month_day[para->month - 1];
    int number = 1;

    date temp = {2023, 10, 6, 5};
    date para_coppy = {para->year, para->month, 1};
    date *para_1 = &para_coppy;

    while (temp.year != para_1->year || temp.month != para_1->month || temp.day != para_1->day)
    {
        if (temp.year > para_1->year || (temp.year == para_1->year && (temp.month > para_1->month || (temp.month == para_1->month && temp.day > para_1->day))))
        {
            sub_day_1(&temp);
        }
        else
        {
            add_day_1(&temp);
        }
    }

    para_1->week = temp.week;

    int table[6][7];

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            if (i == 0 && j < para_1->week)
            {
                table[i][j] = 0;
            }
            else if (number <= cal_max)
            {
                table[i][j] = number;
                number++;
            }
            else
            {
                table[i][j] = 0;
            }
        }
    }

    printf("\t%d年%d月\n", para->year, para->month);
    for (int i = 0; i < 7; i++)
    {
        printf("%s\t", weeks[i]);
    }
    printf("\n");

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            if (table[i][j] == 0)
            {
                printf("\t");
            }
            else
            {
                printf("%d\t", table[i][j]);
            }
        }
        printf("\n");
    }
}

int main()
{
    date *d = create_date();
    if (is_leap(d))
    {
        printf("%d年%d月%d日是闰年\n", d->year, d->month, d->day);
    }
    else
    {
        printf("%d年%d月%d日不是闰年\n", d->year, d->month, d->day);
    }

    day(d);
    week(d);
    Calendar(d);

    free(d);
    return 0;
}
