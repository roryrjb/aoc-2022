#include <stdio.h>
#include <stdlib.h>

int main() {
  char data[16];

  FILE *input;

  if (fopen_s(&input, "1.txt", "r")) {
    perror("fopen_s");
    exit(EXIT_FAILURE);
  }

  long accum = 0;
  long calories = 0;

  while (fgets(data, 16, input) != NULL) {
    calories += strtol(data, NULL, 10);
    if (calories > accum)
      accum = calories;
    if (data[0] == '\n')
      calories = 0;
  }

  printf("%ld\n", accum);

  return 0;
}