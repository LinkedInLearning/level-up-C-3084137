#include <stdio.h>

int main()
{
  float amount[] = {
      0.49, 1.27, 0.75, 1.31, 0.83};
  int x;
  int coin_count[4] = {0, 0, 0, 0};
  float coin_val_in_pennies[] = {
      25, 10, 5, 1};

  for (x = 0; x < 5; x++)
  {
    /* initialize coins
       To avoid precision/rounding errors, scale x 100 (to pennies)*/
    for (int i = 0; i < 4; i++)
      coin_count[i] = 0;
    int change = amount[x] * 100;

    printf("Making change for: $%.2f\n", amount[x]);

    for (int i = 0; i < 4; i++)
    {
      // printf("  Changing $%.2f...\n", coin_val_in_pennies[i] / 100.0);
      while (change >= coin_val_in_pennies[i])
      {
        coin_count[i]++;
        change -= coin_val_in_pennies[i];
        // printf("    Left: $%.2f\n", change / 100.0);
      }
    }
    printf(" DONE -- Changed to: %d quarters, %d dimes, %d nickels, %d pennies\n",
           coin_count[0], coin_count[1], coin_count[2], coin_count[3]);
  }
}