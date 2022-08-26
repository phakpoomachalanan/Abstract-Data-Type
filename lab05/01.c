#include <stdio.h>

typedef struct datetime{
  int date;
  int month;
  int year;
  int dayOfWeek;
  int hour;
  int minute;
  int second;
} datetime_t;

datetime_t createDate(int t) {
  //printf("%d",t);
  int year=1970, month=1,Isleap = 365, dayOfWeek=4, day=1, hour, minute, second,n,c;
  while (t-(Isleap*24*60*60) >= 0) {
    for (c=1;c<=(Isleap%7);c++) {
        if (dayOfWeek == 6) {
          dayOfWeek = 0;
        } else {
          dayOfWeek++;
        }}
    if (year%4 == 0) {
      if (year%100 != 0) {
          t -= 366*24*60*60;
          year++;
      } else {
        if (year%400 != 0) {
          t -= 365*24*60*60;
          year++;
        } else {
          t -= 366*24*60*60;
          year++;
        }
      }} else {
          t -= 365*24*60*60;
          year++;
        }
      
      if (year%4 == 0) {
      if (year%100 != 0) {
          Isleap = 366;
      } else {
        if (year%400 != 0) {
          Isleap = 365;
        } else {
          Isleap = 366;
        }
      }} else {
          Isleap = 365;
        }
        //printf("[%d %d]\n",year,Isleap);
      } 
  //printf("[%d]\n",dayOfWeek);
  for (n=1;n<12;n++) {
    //printf("{%d}",month);
    //printf("%d\n",t);
    switch (n){
      case 1:
        if (t-(31*24*60*60) >= 0) {
              t -= 31*24*60*60;month++;
        for (c=1;c<=(31%7);c++) {
        if (dayOfWeek == 6) {
          dayOfWeek = 0;
        } else {
          dayOfWeek++;
        }
      }}
        break;
      case 2:
        if (Isleap == 366) {
            if (t-(29*24*60*60) >= 0) {
              t -= 29*24*60*60;month++;
              for (c=1;c<=(29%7);c++) {
                if (dayOfWeek == 6) {
                  dayOfWeek = 0;
                } else {
                  dayOfWeek++;
        }
      }
          }} else {
            if (t-(28*24*60*60) >= 0) {
              t -= 28*24*60*60;month++;
              for (c=1;c<=(28%7);c++) {
        if (dayOfWeek == 6) {
          dayOfWeek = 0;
        } else {
          dayOfWeek++;
        }
      }}}
          break;
      case 3:
        if (t-(31*24*60*60) >= 0) {
              t -= 31*24*60*60;month++;
              for (c=1;c<=(31%7);c++) {
        if (dayOfWeek == 6) {
          dayOfWeek = 0;
        } else {
          dayOfWeek++;
        }
      }}
        break;
      case 4:
        if (t-(30*24*60*60) >= 0) {
              t -= 30*24*60*60;month++;
              for (c=1;c<=(30%7);c++) {
        if (dayOfWeek == 6) {
          dayOfWeek = 0;
        } else {
          dayOfWeek++;
        }
      }}
        break;
      case 5:
        if (t-(31*24*60*60) >= 0) {
              t -= 31*24*60*60;month++;
              for (c=1;c<=(31%7);c++) {
        if (dayOfWeek == 6) {
          dayOfWeek = 0;
        } else {
          dayOfWeek++;
        }
      }}
        break;
      case 6:
        if (t-(30*24*60*60) >= 0) {
              t -= 30*24*60*60;month++;
              for (c=1;c<=(30%7);c++) {
        if (dayOfWeek == 6) {
          dayOfWeek = 0;
        } else {
          dayOfWeek++;
        }
      }}
        break;
      case 7:
        if (t-(31*24*60*60) >= 0) {
              t -= 31*24*60*60;month++;
              for (c=1;c<=(31%7);c++) {
        if (dayOfWeek == 6) {
          dayOfWeek = 0;
        } else {
          dayOfWeek++;
        }
      }}
        break;
      case 8:
        if (t-(31*24*60*60) >= 0) {
              t -= 31*24*60*60;month++;
              for (c=1;c<=(31%7);c++) {
        if (dayOfWeek == 6) {
          dayOfWeek = 0;
        } else {
          dayOfWeek++;
        }
      }}
        break;
      case 9:
        if (t-(30*24*60*60) >= 0) {
              t -= 30*24*60*60;month++;
              for (c=1;c<=(30%7);c++) {
        if (dayOfWeek == 6) {
          dayOfWeek = 0;
        } else {
          dayOfWeek++;
        }
      }}
        break;
      case 10:
        if (t-(31*24*60*60) >= 0) {
              t -= 31*24*60*60;month++;
              for (c=1;c<=(31%7);c++) {
        if (dayOfWeek == 6) {
          dayOfWeek = 0;
        } else {
          dayOfWeek++;
        }
      }}
        break;
      case 11:
        if (t-(30*24*60*60) >= 0) {
              t -= 30*24*60*60;month++;
              for (c=1;c<=(30%7);c++) {
        if (dayOfWeek == 6) {
          dayOfWeek = 0;
        } else {
          dayOfWeek++;
        }
      }}
        break;
      case 12:
        if (t-(31*24*60*60) >= 0) {
              t -= 31*24*60*60;month++;
              for (c=1;c<=(31%7);c++) {
        if (dayOfWeek == 6) {
          dayOfWeek = 0;
        } else {
          dayOfWeek++;
        }
      }}
        break;
    }}
  while (t-(24*60*60)>=0) {
    t -= 24*60*60;
    day++;
    if (dayOfWeek == 6) {
      dayOfWeek = 0;
    } else {
      dayOfWeek++;
    }
  //printf("(%d)",dayOfWeek);
  }
  hour = (t/(60*60));
  t -= hour*60*60;
  minute = t/(60);
  t -= minute*60;
  second = t;
  datetime_t inputDate = {day,month,year,dayOfWeek,hour,minute,second};
  return inputDate;
}

int printDate(datetime_t inputDate) {
  switch (inputDate.dayOfWeek)
  {
  case 0:
    printf("Sun ");
    break;
  case 1:
    printf("Mon ");
    break;
  case 2:
    printf("Tue ");
    break;
  case 3:
    printf("Wed ");
    break;
  case 4:
    printf("Thu ");
    break;
  case 5:
    printf("Fri ");
    break;
  case 6:
    printf("Sat ");
    break;
  }
  printf("%d ",inputDate.date);
  switch (inputDate.month)
  {
  case 1:
    printf("JAN ");
    break;
  case 2:
    printf("FEB ");
    break;
  case 3:
    printf("MAR ");
    break;
  case 4:
    printf("APR ");
    break;
  case 5:
    printf("MAY ");
    break;
  case 6:
    printf("JUN ");
    break;
  case 7:
    printf("JUL ");
    break;
  case 8:
    printf("AUG ");
    break;
  case 9:
    printf("SEP ");
    break;
  case 10:
    printf("OCT ");
    break;
  case 11:
    printf("NOV ");
    break;
  case 12:
    printf("DEC ");
    break;
  }
  printf("%d ",inputDate.year);
  printf("%.2d",inputDate.hour);
  printf(":%.2d",inputDate.minute);
  printf(":%.2d",inputDate.second);
}

int main(void) {
  datetime_t inputDate;
  int timestamp;

  scanf("%d", &timestamp);
  inputDate = createDate(timestamp);
  printDate(inputDate);
  return 0;
}