#include <stdio.h>
#include <stdbool.h>
#include "date.h"

int compareDate(Date date1, Date date2)
{
  Date difference = {date1.day - date2.day,
                     date1.month - date2.month,
                     date1.year - date2.year};

  if (difference.year != 0)
  {
    return difference.year < 0 ? -1 : 1;
  }
  if (difference.month != 0)
  {
    return difference.month < 0 ? -1 : 1;
  }
  if (difference.day != 0)
  {
    return difference.day < 0 ? -1 : 1;
  }

  return 0;
}

bool isDateInRange(Date date, DateRange dateRange)
{
  int startComparison = compareDate(date, dateRange.start);
  int endComparison = compareDate(dateRange.end, date);
  if (startComparison < 0 || endComparison < 0)
  {
    return false;
  }
  return true;
}