#ifndef DATE
#define DATE
#include <stdbool.h>

typedef struct {
  int day;
  int month;
  int year;
} Date;

typedef struct 
{
  Date start;
  Date end;
} DateRange;

int compareDate(Date date1, Date date2);
bool isDateInRange(Date date, DateRange DateRange);

#endif