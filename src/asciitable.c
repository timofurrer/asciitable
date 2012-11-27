#include <stdio.h>
#include <stdlib.h>

#define START_NUMBER   32
#define END_NUMBER    127

#define COLUMNS         3

int main(int argc, char **argv)
{
  int x, y;
  int rows, cols = COLUMNS;

  if(argc > 1)
  {
    cols = atoi(argv[1]);
    if(cols > 6)
    {
      fprintf(stderr, "\033[1;31mError:\033[0;31m Cannot print ascii table in more than 6 columns\033[0m\n\n");
      cols = 6;
    }
  }

  rows = (127 - 32) / cols + 1;

  for(x = 0; x < cols; x++)
    printf("\033[36mDEC\033[0m   HEX   OCT   \033[1;36mCHR\033[0m       ");
  printf("\n");

  for(x = 0; x < cols; x++)
  {
    printf("=====================");
    if(x != cols - 1)
      printf("=======");
  }
  printf("\n");

  for(y = START_NUMBER; y < (START_NUMBER + rows); y++)
  {
    for(x = y; x <= END_NUMBER; x += rows)
      printf("\033[36m%3d\033[0m   %3x   %3o   \033[1;36m%c\033[0m         ", x, x, x, x);
    printf("\n");
  }

  return EXIT_SUCCESS;
}
