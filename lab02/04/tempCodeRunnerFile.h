int count_day(float year, int month) {
  int day = 0,i;
  for (i=1990; i<=year; i++){
    if (((year/4)==((int)(year/4))) && ((year/100)!=((int)(year/100)))) {
      if ((year/400)==((int)(year/400))) {
        day += 365;
      } else {day += 366;}
    } else {day += 365;}}
  day = day%7;
  return day;
}