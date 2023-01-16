#include <stdio.h>

int main()
{
  // Use row, column order. 0,0 is upper left.
  int done = 0;
  int r, c, count = 0;
  int move;
  srand(time(0));

  // init king
  int king_row = 4;
  int king_col = 5;

  // show initial
  printf("Start:\n");
  for (r = 0; r < 8; r++)
  {
    for (c = 0; c < 8; c++)
    {
      if ((king_row == r + 1) && (king_col == c + 1))
        printf(" K ");
      else
        printf(" . ");
    }
    printf("\n");
  }
  // getchar();
  sleep(1);

  do
  {
    count++;

    // randomize king movement, where number is a direction within a 3x3 matrix.
    // for example, 1 = move up-left; 5 = no movement; 8 = down.
    move = rand() % 9 + 1;
    printf("Move Direction: ");
    switch (move)
    {
    case 1:
      king_row--;
      king_col--;
      printf("Up-Left\n");
      break;
    case 2:
      king_row--;
      printf("Up\n");
      break;
    case 3:
      king_row--;
      king_col++;
      printf("Up-Right\n");
      break;
    case 4:
      king_col--;
      printf("Left\n");
      break;
    case 5:
      printf("-\n");
      break;
    case 6:
      king_col++;
      printf("Right\n");
      break;
    case 7:
      king_row++;
      king_col--;
      printf("Down-Left\n");
      break;
    case 8:
      king_row++;
      printf("Down\n");
      break;
    case 9:
      king_row++;
      king_col++;
      printf("Down-Right\n");
      break;
    default:
      printf("None\n");
      break;
    }

    // display
    printf("Move: %d\n", count);
    for (r = 0; r < 8; r++)
    {
      for (c = 0; c < 8; c++)
      {
        if ((king_row == r + 1) && (king_col == c + 1))
          printf(" K ");
        else
          printf(" . ");
      }
      printf("\n");
    }

    // getchar();
    sleep(1);

    if ((king_col > 8) || king_col < 1 ||
        (king_row > 8) || king_row < 1)
    {
      printf("King is out of bounds at: %d, %d (After %d moves)\n", king_row, king_col, count);
      done = 1;
    }

  } while (done == 0);
}