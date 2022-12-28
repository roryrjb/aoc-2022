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

  int counter = 0;
  char group[3][BUF_SIZE];
  char match = '\0';

  while (fgets(data, BUF_SIZE, input) != NULL) {
    strcpy_s(group[counter++], BUF_SIZE, data);

    if (counter == 3) {
      counter = 0;
      char *a = group[0];
      char *b = group[1];
      char *c = group[2];

      for (int i = 0; i < strlen(a); i++) {
        for (int j = 0; j < strlen(b); j++) {
          for (int k = 0; k < strlen(c); k++) {
            if (a[i] == b[j] && a[i] == c[k] && c[k] == b[j]) {
              match = a[i];
              break;
            }
          }

          if (match != '\0')
            break;
        }

        if (match != '\0')
          break;
      }

      int score = (match >= 97) ? match - 96 : match - 38;
      match = '\0';
      total += score;
    }
  }

  printf("3.2: %d\n", total);
}
