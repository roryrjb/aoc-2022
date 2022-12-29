#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 4096

int main() {
  char data[BUF_SIZE];
  int marker = 0;

  FILE *input;

  if (fopen_s(&input, "6.txt", "r") != 0) {
    fprintf(stderr, "Failed to open input file.\n");
    exit(EXIT_FAILURE);
  };

  while (fgets(data, BUF_SIZE, input) != 0) {
    for (int i = 0; i < strlen(data); i++) {
      char chunk[15] = {'\0'};
      strncpy(chunk, &data[i], 14);
      bool marker = true;

      for (int i = 0; i < 14; i++) {
        for (int j = 0; j < 14; j++) {
          if (chunk[i] == chunk[j] && i != j)
            marker = false;
        }
      }

      if (marker == true) {
        printf("6.2: %d (\"%s\")\n", i + 14, chunk);
        break;
      }
    }
  }
}
