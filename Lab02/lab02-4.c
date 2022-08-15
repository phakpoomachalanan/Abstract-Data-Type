#include<stdio.h>

int main(void)
{
    int startDate;
    int sum = 0, minusOneYear;
    int year, month;
    int dayInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    printf("Enter year: ");
    scanf("%d", &year);

    printf("Enter month: ");
    scanf("%d", &month);

    printf("====================\n");
    
    switch(month)
    {
        case 1:
            printf("January ");
            break;

        case 2:
            printf("Febuary ");
            break;
        
        case 3:
            printf("March ");
            break;
        
        case 4:
            printf("April ");
            break;

        case 5:
            printf("May ");
            break;

        case 6:
            printf("June ");
            break;

        case 7:
            printf("July ");
            break;

        case 8:
            printf("August ");
            break;
        
        case 9:
            printf("September ");
            break;

        case 10:
            printf("October ");
            break;

        case 11:
            printf("November ");
            break;
        
        case 12:
            printf("December ");
            break;
    }
    printf("%d\n", year);

    printf("Sun Mon Tue Wed Thu Fri Sat\n");

    if ((year%4==0 && year%100!=0) || year%400==0)
    {
        dayInMonth[2] += 1;
    }

    for (int i=1; i<month; i++)
    {
        sum += dayInMonth[i];
    }
    
    minusOneYear = year - 1;
    startDate = ((year + minusOneYear/4 - minusOneYear/100 + minusOneYear/400 + sum) % 7);
 
    for (int i=0; i<startDate; i++)
    {
        printf("    ");
    }

    int j;
    for (int date=1, j=0;date<=dayInMonth[month]; date++, j++)
    {
        printf("%3d ", date);
        if ((date+startDate)%7 == 0)
        {
            printf("\n");
        }
    }
    if ((dayInMonth[month]+startDate)%7!=0)
    {
        printf("\n");
    }

    return 0;
}