#include <stdio.h>

void initMatrix(char **in, int r, int c)
{
  char alpha[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

  for (int rr = 0; rr < r; rr++)
  {
    for (int cc = 0; cc < c; cc++)
      in[rr][cc] = alpha[rand() % 26];
  }
}

void printMatrix(char **in, int r, int c)
{
  for (int rr = 0; rr < r; rr++)
  {
    for (int cc = 0; cc < c; cc++)
      printf(" %c ", in[rr][cc]);
    printf("\n");
  }
}

void rotateMatrix(char **in, int r, int c, char **out)
{
  int t;
  int r_rot = 0;
  int c_rot = r - 1;

  for (int rr = 0; rr < r; rr++)
  {
    r_rot = 0;
    for (int cc = 0; cc < c; cc++)
    {
      out[r_rot][c_rot] = in[rr][cc];
      r_rot++;
    }
    c_rot--;
  }
}

int main()
{
  // note: dimensions are in row/column format
  int mat_sizes[3][2] = {{8, 3}, {5, 5}, {4, 6}};
  int r, c;
  srand(time(NULL));
  char **matrices[3];
  char **rotated[3];

  for (int n = 0; n < 3; n++)
  {
    printf("Matrix %d:\n", n + 1);

    matrices[n] = (char **)malloc(mat_sizes[n][0] * sizeof(char *));
    for (int r = 0; r < mat_sizes[n][0]; r++)
      matrices[n][r] = (char *)malloc(mat_sizes[0][1] * sizeof(char));
    initMatrix(matrices[n], mat_sizes[n][0], mat_sizes[n][1]);
    printMatrix(matrices[n], mat_sizes[n][0], mat_sizes[n][1]);

    puts("Rotated:");
    rotated[n] = (char **)malloc(mat_sizes[n][1] * sizeof(char *));
    for (int r = 0; r < mat_sizes[n][1]; r++)
      rotated[n][r] = (char *)malloc(mat_sizes[n][0] * sizeof(char));
    rotateMatrix(matrices[n], mat_sizes[n][0], mat_sizes[n][1], rotated[n]);
    printMatrix(rotated[n], mat_sizes[n][1], mat_sizes[n][0]);
    printf("\n");
  }
  return;
}