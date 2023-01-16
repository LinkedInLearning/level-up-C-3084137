#include <stdio.h>
#include <time.h>

/* return the proper number of days in
   February for the current year */
int february(int year)
{
  if ((year % 400) == 0)
    return (29);
  if ((year % 100) == 0)
    return (28);
  if ((year % 4) == 0)
    return (29);
  return (28);
}

int main()
{
  time_t t = time(NULL);
  struct tm time = *localtime(&t);

  int days_in_month[] = {31, 28, 31, 30, 31, 30,
                         31, 31, 30, 31, 30, 31};
  char *months[] = {"January", "February", "March", "April", "May",
                    "June", "July", "August", "September", "October",
                    "November", "December"};
  char *days[] = {"Sunday", "Monday", "Tuesday", "Wednesday",
                  "Thursday", "Friday", "Saturday"};

  int this_month_num = time.tm_mon;
  int today_num = time.tm_mday;
  int this_year_num = time.tm_year + 1900;

  this_month_num = 11;
  today_num = 27;

  days_in_month[1] = february(time.tm_year + 1900);

  printf("Today is: %s, %s %d, %d\n", days[time.tm_wday],
         months[this_month_num], today_num, this_year_num);

  int until_monday = (7 - time.tm_wday + 1);
  int monday_date = today_num + until_monday;

  if (monday_date > days_in_month[this_month_num])
  {
    monday_date = monday_date % days_in_month[this_month_num];
    this_month_num++;
  }

  if (this_month_num == 12)
  {
    this_year_num++;
    this_month_num = 0;
  }
  printf("Next Monday is: %s %d, %d (%d days away)\n",
         months[this_month_num], monday_date,
         this_year_num, until_monday);

  puts("");
  return 0;
}