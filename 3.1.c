#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Lowercase item types a through z have priorities 1 through 26. ('a' == 97)
// Uppercase item types A through Z have priorities 27 through 52. ('A' == 65)

#define BUF_SIZE 64

int main() {
  char data[BUF_SIZE];
  int total = 0;

  FILE *input;

  if (fopen_s(&input, "3.txt", "r") != 0) {
    fprintf(stderr, "Failed to open input file.\n");
    exit(EXIT_FAILURE);
  };

  while (fgets(data, BUF_SIZE, input) != NULL) {
    char match = '\0';
    size_t len = strlen(data);
    len = data[len - 1] == '\n' ? len - 1 : len; // don't count newlines

    for (int i = 0; i < len / 2; i++) {
      char ch = data[i];

      for (size_t j = len / 2; j < len; j++) {
        if (ch == data[j]) {
          match = ch;
          break;
        }
      }

      if (match != '\0')
        break;
    }

    // since chars are numbers let's just make the adjustment
    total += (match >= 97) ? match - 96 : match - 38;
  }

  printf("3.1: %d\n", total);
}
