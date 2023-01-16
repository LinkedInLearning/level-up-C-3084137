#include <stdio.h>
#include <string.h>

int main()
{

  char original[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char deck[26];
  strcpy(deck, original);

  char out[26];
  char first[13], last[13];

  int count = 0;
  while (1)
  {
    int idx = 0;

    // split the deck
    for (int i = 0; i < 13; i++)
    {
      first[i] = deck[i];
      last[i] = deck[i + 13];
    }

    for (int i = 0; i < 13; i++)
    {
      deck[i * 2] = first[idx];
      deck[(i * 2) + 1] = last[idx];
      idx++;
    }
    count++;

    printf("  Shuffle [%02d]: %s\n", count, deck);

    // Check if back to original
    if (strcmp(deck, original) == 0)
      break;
  }

  printf("!!-- DONE --!!\n");
}
