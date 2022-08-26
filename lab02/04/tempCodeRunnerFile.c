#include <stdio.h>


int count_day(int year, int month) {
  int find_month();
  int day = 0,i;
  for (i=1990; i<year; i++){
    if (((float)(i/(float)(4))==((int)(i/(float)(4)))) && ((float)(i/(float)(100))!=((int)(i/(float)(100))))) {
      if ((i/(float)(400))==((int)(i/(float)(400)))) {
        day += 365;
      } else {day += 366;}
    } else {day += 365;}}
    if (i>1){day+=1;}
  for (i=1; i<=month; i++) {
    day += find_month(i,year);
    if (i==month) {
      day -= find_month(i,year);
    }
  }
  day = day%7;
  return day;
}

const char *count_month(int month) {
  switch (month)
  {
  case 1:
    return "January";
    break;
  case 2:
    return "February";
    break;
  case 3:
    return "March";
    break;
  case 4:
    return "April";
    break;
  case 5:
    return "May";
    break;
  case 6:
    return "June";
    break;
  case 7:
    return "July";
    break;
  case 8:
    return "August";
    break;
  case 9:
    return "September";
    break;
  case 10:
    return "October";
    break;
  case 11:
    return "November";
    break;
  case 12:
    return "December";
    break;
  }
}

int find_month(int month, int year) {
  switch (month)
  {
  case 1:
    return 31;
    break;
  case 2:
    if (((float)(year/(float)(4))==((int)(year/(float)(4)))) && ((float)(year/(float)(100))!=((int)(year/(float)(100))))) {
      if ((year/(float)(400))==((int)(year/(float)(400)))) {
        return 28;break;
      } else {return 29;break;}
    } else {return 28;break;}
  case 3:
    return 31;
    break;
  case 4:
    return 30;
    break;
  case 5:
    return 31;
    break;
  case 6:
    return 30;
    break;
  case 7:
    return 31;
    break;
  case 8:
    return 31;
    break;
  case 9:
    return 30;
    break;
  case 10:
    return 31;
    break;
  case 11:
    return 30;
    break;
  case 12:
    return 31;
    break;
  }
}
//char count_month(int month);
int main(void) {
  int year,month,day;
  printf("Enter year: ");
  scanf("%d", &year);
  printf("Enter month: ");
  scanf("%d", &month);
  printf("====================\n");
  printf("%s %d\n",count_month(month), year);
  printf("Sun Mon Tue Wed Thu Fri Sat\n");
  day = count_day(year,month);
  //printf("%d", day);
  int MD = find_month(month,year); int i;
  switch (day)
  {
  case 1:
    printf("    ");
    break;
  case 2:
    printf("        ");
    break;
  case 3:
    printf("            ");
    break;
  case 4:
    printf("                ");
    break;
  case 5:
    printf("                    ");
    break;
  case 6:
    printf("                        ");
    break;
  default:
    break;
  }
  int count = day;
  for (i=1; i<=MD; i++) {
    printf("%3d ", i);
    if (count == 6) {
      printf("\n");
      count = 0;
    } else {count += 1;}
    //printf("(%d)", count);
  }
  return 0;
}