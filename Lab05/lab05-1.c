#include<stdio.h>

typedef struct datetime {
    int date;
    int month;
    int year;
    int dayOfWeek;
    int hour;
    int minute;
    int second;
}
datetime_t;

datetime_t createDate(int time)
{
    datetime_t date;
    int sum = 0, minusOneYear;
    int monthSum = 0;
    int dayInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int leap = 0;

    for (int i=1970; i<(1970+time/31536000); i++)
    {
        if ((i%4==0 && i%100!=0) || i%400==0)
        {
            leap += 86400;
        }
    }

    date.year = 1970 + (time/31536000);
    time = time%31536000;

    if ((date.year%4==0 && date.year%100!=0) || date.year%400==0)
    {
        dayInMonth[2] += 1;
    }

    for (int i=0; i<=12; i++)
    {
        monthSum += 86400 * dayInMonth[i];
        if (monthSum > time-leap)
        {
            date.month = i;
            monthSum -= 86400 * dayInMonth[i];
            break;
        }
    }

    time -= monthSum + leap;
    date.date = 1 + (time/86400);

    time %= 86400;
    date.hour = time / 3600;

    time %= 3600;
    date.minute = time / 60;

    time %= 60;
    date.second = time;

    for (int i=1; i<date.month; i++)
    {
        sum += dayInMonth[i];
    }
  
    minusOneYear = date.year - 1;
    date.dayOfWeek = ((date.date + (date.year%1970) + minusOneYear/4 - minusOneYear/100 + minusOneYear/400 + sum + 2) % 7) ;

  return date;
}

void printDate(datetime_t date)
{
    char dayOfWeek[7][4] = {"SUN", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    char month[12][4] = {"JUN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC"};
    
    printf("%s %d %s %d %02d:%02d:%02d\n", dayOfWeek[date.dayOfWeek], date.date, month[date.month-1], date.year, date.hour, date.minute, date.second);
}

int main(void) {
    datetime_t inputDate;
    int timestamp;

    scanf("%d", &timestamp);
    inputDate = createDate(timestamp);
    printDate(inputDate);

    return 0;
}

// 31536000
// 63072000
// 68255999
// 68256000
// 94608000
// 94694400
// 1528374628
// 1597436869