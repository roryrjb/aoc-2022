#include <stdio.h>
#include <stdlib.h>

int main()
{
  char data[16];

  FILE *input;

  if (fopen_s(&input, "1.txt", "r") != 0)
  {
    fprintf(stderr, "Failed to open input file.\n");
    exit(EXIT_FAILURE);
  };

  if (input == NULL)
  {
    exit(EXIT_FAILURE);
  }

  long accum = 0;
  long calories = 0;

  while (fgets(data, 16, input) != NULL)
  {
    calories += strtol(data, NULL, 10);
    if (calories > accum)
      accum = calories;
    if (data[0] == '\n')
      calories = 0;
  }

  printf("1.1: %ld\n", accum);

  return 0;
}
