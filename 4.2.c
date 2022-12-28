#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 16

int main() {
  char data[BUF_SIZE];
  int total = 0;

  FILE *input;

  if (fopen_s(&input, "4.txt", "r") != 0) {
    fprintf(stderr, "Failed to open input file.\n");
    exit(EXIT_FAILURE);
  };

  int counter = 0;

  while (fgets(data, BUF_SIZE, input) != NULL) {
    size_t len = strlen(data);

    if (len < 2)
      continue;

    char numbers[4][BUF_SIZE] = {"", "", "", ""};

    for (int i = 0, j = 0; i < len; i++) {
      char c = data[i];

      if (c >= '0' && c <= '9') {
        numbers[counter][j++] = c;
      } else if (c == '-' || c == ',') {
        j = 0;
        counter++;
      } else {
        break;
      }
    }

    counter = 0;

    long a1 = strtol(numbers[0], NULL, 10);
    long a2 = strtol(numbers[1], NULL, 10);
    long b1 = strtol(numbers[2], NULL, 10);
    long b2 = strtol(numbers[3], NULL, 10);

    for (int i = a1; i <= a2; i++) {
      if (i >= b1 && i <= b2) {
        total++;
        break;
      }
    }
  }

  printf("4.2: %d\n", total);
}
