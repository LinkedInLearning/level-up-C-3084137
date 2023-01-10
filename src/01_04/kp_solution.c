#include <stdio.h>

int main()
{
  int x, count;

  printf("Enter a starting number: ");
  scanf("%d", &x);

  printf("Hailstone Sequence: ");
  printf("%d", x);
  count++;

  while (x != 1)
  {
    if (x % 2 == 0) // it's even
    {
      x /= 2;
    }
    else // it's odd
    {
      x = (x * 3) + 1;
    }
    printf(", %d", x);
    count++;

    if (x == 1)
      break;
  }
  printf("\n");
  printf("Length: %d\n", count);
}