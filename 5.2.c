#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 64
#define STACKS 9

int main() {
  char data[BUF_SIZE];

  FILE *input;

  if (fopen_s(&input, "5.txt", "r") != 0) {
    fprintf(stderr, "Failed to open input file.\n");
    exit(EXIT_FAILURE);
  };

  //     [C]             [L]         [T]
  //     [V] [R] [M]     [T]         [B]
  //     [F] [G] [H] [Q] [Q]         [H]
  //     [W] [L] [P] [V] [M] [V]     [F]
  //     [P] [C] [W] [S] [Z] [B] [S] [P]
  // [G] [R] [M] [B] [F] [J] [S] [Z] [D]
  // [J] [L] [P] [F] [C] [H] [F] [J] [C]
  // [Z] [Q] [F] [L] [G] [W] [H] [F] [M]
  //  1   2   3   4   5   6   7   8   9

  char stacks[STACKS][BUF_SIZE] = {"ZJG",     "QLRPWFVC", "FPMCLGR",
                                   "LFBWPHM", "GCFSVQ",   "WHJZMQTL",
                                   "HFSBV",   "FJZS",     "MCDPFHBT"};

  while (fgets(data, BUF_SIZE, input) != 0) {
    if (data[0] != 'm')
      continue;

    size_t len = strlen(data);
    int counter = 0;
    char numbers[3][BUF_SIZE] = {"", "", ""};
    int in_digit = 0;

    for (int i = 0, j = 0; i < len; i++) {
      char c = data[i];

      if (isdigit(c)) {
        in_digit = 1;
        numbers[counter][j++] = c;
      } else {
        if (in_digit)
          counter++;
        in_digit = 0;
        j = 0;
      }
    }

    long amount = strtol(numbers[0], NULL, 10);
    long from = strtol(numbers[1], NULL, 10);
    long to = strtol(numbers[2], NULL, 10);
    char str_to_move[amount + 1];
    memset(str_to_move, '\0', amount + 1);
    int offset = strlen(stacks[from - 1]) - amount;
    strncpy(str_to_move, &stacks[from - 1][offset], amount + 1);
    stacks[from - 1][offset] = '\0';
    strncat(stacks[to - 1], str_to_move, amount);
  }

  printf("5.2: ");

  for (int i = 0; i < STACKS; i++) {
    printf("%c", stacks[i][strlen(stacks[i]) - 1]);
  }

  printf("\n");
}
