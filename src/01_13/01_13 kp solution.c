#include <stdio.h>
#define TURNS 4

int main()
{
  int ball[2] = {-1, -1};
  int turns[TURNS][2] = {{10, 0}, {8, 2}, {4, 1}, {0, 6}};

  for (int i = 0; i < TURNS; i++)
  {
    ball[0] = turns[i][0];
    ball[1] = turns[i][1];

    printf("+-----------+\n");
    printf("|           |\n");
    if (ball[0] == 10)
    {
      puts("|  X     -  |");
      printf("|           |\n");
      puts("+-----------+");
      puts("|     X     |");
    }
    else if ((ball[0] + ball[1]) == 10)
    {
      printf("|  %2d   %2d  |\n", ball[0], ball[1]);
      printf("|           |\n");
      puts("+-----------+");
      puts("|     /     |");
    }
    else
    {
      if (ball[0] == 0 && ball[1] == 0)
      {
        puts("|  -     -  |");
        puts("|           |");
        puts("+-----------+");
        puts("|     0     +");
      }
      else if (ball[0] == 0)
      {
        printf("|  -    %2d  |\n", ball[1]);
        printf("|           |\n");
        puts("+-----------+");
        printf("|    %2d     |\n", ball[1]);
      }
      else if (ball[1] == 0)
      {
        printf("|  %2d     -  |\n", ball[0]);
        printf("|           |\n");
        puts("+-----------+");
        printf("|     %2d     |\n", ball[0]);
      }
      else
      {
        printf("|  %2d   %2d  |\n", ball[0], ball[1]);
        printf("|           |\n");
        puts("+-----------+");
        printf("|    %2d     |\n", ball[0] + ball[1]);
      }
    }
    puts("+-----------+\n");
  }
}