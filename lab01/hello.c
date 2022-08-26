3#include <stdio.h>
int main(int argc, char **argv)
{ 
  int day;
  int month;
  float year;
  int total = 0;
  scanf("%d/%d/%f", &day, &month, &year);
  //printf("%d-%d-%d", day, month, year);
  total += day;
  int i;
  for (i=1; i<month; i++) {
    switch (i) {
      case 3:
        if ((year/400) == (int)(year/400)) {
          //printf("29-%d\n",i);
          total += 29;
        } else if ((year/4) == (int)((year)/4) && ((year/100) != (int)(year/100))) {
          //printf("29-%d\n",i);
          total += 29;
        } else {
          //printf("28-%d\n",i);
          total += 28;
        }
        break;
      case 4:
        //printf("30-%d\n",i);
        total += 30;
        break;
      case 6:
        //printf("30-%d\n",i);
        total += 30;
        break;
      case 10:
        //printf("30-%d\n",i);
        total += 30;
        break;
      case 11:
        //printf("30-%d\n",i);
        total += 30;
        break;
      default:
        if (month == 1) {
          break;
        }
        //printf("31-%d\n",i);
        total += 31;
    }
  }
  //printf("-------------------------\n");
  printf("%d", total);
  return 0;
}