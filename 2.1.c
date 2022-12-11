#include <stdio.h>
#include <stdlib.h>

int main()
{
  char data[16];
  FILE *input = fopen("2.txt", "r");
  int overall_total = 0;

  if (input == NULL)
  {
    exit(EXIT_FAILURE);
  }

  while (fgets(data, 16, input) != 0)
  {
    int total = 0;
    switch (data[2])
    {
    case 'X':
      total += 1;
      break;
    case 'Y':
      total += 2;
      break;
    case 'Z':
      total += 3;
      break;
    }

    switch (data[0])
    {
    case 'A':
      if (data[2] == 'Y')
        total += 6;
      if (data[2] == 'X')
        total += 3;
      break;
    case 'B':
      if (data[2] == 'Y')
        total += 3;
      if (data[2] == 'Z')
        total += 6;
      break;
    case 'C':
      if (data[2] == 'Z')
        total += 3;
      if (data[2] == 'X')
        total += 6;
      break;
    }

    overall_total += total;
  }

  printf("2.1: %d\n", overall_total);
}