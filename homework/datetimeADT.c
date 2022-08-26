#include <stdio.h>

typedef struct datetime
{
    int date;
    int month;
    int year;
    int dayOfWeek;
    int hour;
    int minute;
    int second;

}datetime_t;

int isLeap(int year) {
    
    if (year % 400 == 0) {
        
        return 1;
    }

    else if (year % 4 == 0 && year % 100 != 0) {
       
       return 1;
    }
    return 0;
}

datetime_t createDate(int timestamp) {
    datetime_t hello;
    datetime_t *pHello = &hello;
    int daysInMonths[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int leap = 0;
    int year = 1970 + timestamp/(86400*365);
    
    //printf("%d\n",leap);
    //leaps since 1970
    int LEAPS = 0;
    for (int y = 1970; y <= year; y++)
    {
        if (isLeap(y))
            LEAPS++;
    }
    int month = 0;
    if (isLeap(year))
        daysInMonths[1]+=1;
    int stampRemain;
    stampRemain = timestamp-((year-1970)*(86400*365))-(86400*LEAPS);

    for (month = 0 ; stampRemain>0 ; month++)
    {
        stampRemain = stampRemain - daysInMonths[month]*86400;
    }
    month--;
    stampRemain = stampRemain + daysInMonths[month]*86400;
    if (timestamp==0)  
        month = 0;  
    //printf("%d\n",stampRemain);
    int days = stampRemain/86400;
    
    int hours = (stampRemain-(days*86400))/3600;
    
    int minutes = (stampRemain-(days*86400)-(hours*3600))/60;
    
    int seconds = stampRemain-(days*86400)-(hours*3600)-(minutes*60);
    
    int yearCode = (year%100 + (year%100 / 4)) % 7;
    int monthCode[] = {0,3,3,6,1,4,6,2,5,0,3,5};
    int centuryCode;
    if ((int)(year/100)==19)
        centuryCode = 0;
    if ((int)(year/100)==20)
        centuryCode = 6;
    if ((int)(year/100)==21)
        centuryCode = 4;
    if ((int)(year/100)==22)
        centuryCode = 2;
    if ((int)(year/100)==23)
        centuryCode = 0;
    if (isLeap(year))
        days+=1;
    int leapCode = 0;
    if (isLeap(year) && (month==0 || month==1))
        leapCode = 1;
    //printf("%d\n",leapCode);
    int dayOfWeek = 1 + ((yearCode + monthCode[month] + centuryCode + days - leapCode) % 7);
    
    
        
    pHello->date = days+1;
    pHello->month = month;
    pHello->year = year;
    pHello->dayOfWeek = dayOfWeek;
    pHello->hour = hours;
    pHello->minute = minutes;
    pHello->second = seconds;
    
    return hello;
    
}

void printDate(datetime_t hello) {
    char dateNames[7][3] = {"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};
    
    char monthNames[12][3] = {"JAN","FEB","MAR","APR","MAY","JUN","JUL","AUG","SEP","OCT","NOV","DEC"};
    
    printf("%.3s %d %.3s %d ",dateNames[hello.dayOfWeek],hello.date,monthNames[hello.month],hello.year);
    
    if (hello.hour<10)
        printf("0%d:",hello.hour);
    else
        printf("%d:",hello.hour);    
    if (hello.minute<10)
        printf("0%d:",hello.minute);
    else
        printf("%d:",hello.minute);  
    if (hello.second<10)
        printf("0%d",hello.second);
    else
        printf("%d",hello.second);  
}

int main(void) {
    datetime_t inputDate;
    int timestamp;

    scanf("%d",&timestamp);
    inputDate = createDate(timestamp);
    printDate(inputDate);
    return 0;
}