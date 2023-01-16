#include <stdio.h>

int leapyear(int n);

int main()
{

  for (int i = 1582; i <= 2101; i++)
  {
    if (leapyear(i) == 1)
      printf("  %d\n", i);
  }

  return 0;
}

int leapyear(int n)
{
  if (n % 4 == 0)
  {
    if (n % 100 == 0)
    {
      if (n % 400 == 0)
        return 1;
      else
        return 0;
    }
    else
      return 1;
  }
  else
    return 0;
}