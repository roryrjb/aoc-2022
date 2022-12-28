#include <stdio.h>
#include <stdlib.h>

#define ROCK 'A'
#define PAPER 'B'
#define SCISSORS 'C'
#define LOSE 'X'
#define DRAW 'Y'
#define WIN 'Z'

int choice_score(char choice) {
  switch (choice) {
  case ROCK:
    return 1;
  case PAPER:
    return 2;
  case SCISSORS:
    return 3;
  }

  return 0;
}

char choose(char opponent_choice, char outcome) {
  switch (outcome) {
  case LOSE:
    if (opponent_choice == ROCK)
      return SCISSORS;
    if (opponent_choice == PAPER)
      return ROCK;
    if (opponent_choice == SCISSORS)
      return PAPER;
  case WIN:
    if (opponent_choice == ROCK)
      return PAPER;
    if (opponent_choice == PAPER)
      return SCISSORS;
    if (opponent_choice == SCISSORS)
      return ROCK;
  case DRAW:
    return opponent_choice;
  }

  return -1;
}

int main() {
  char data[16];
  int overall_total = 0;

  FILE *input;

  if (fopen_s(&input, "2.txt", "r") != 0) {
    fprintf(stderr, "Failed to open input file.\n");
    exit(EXIT_FAILURE);
  };

  while (fgets(data, 16, input) != 0) {
    int total = 0;

    char choice = choose(data[0], data[2]);
    total += choice_score(choice);

    switch (data[2]) {
    case WIN:
      total += 6;
      break;
    case DRAW:
      total += 3;
      break;
    }

    overall_total += total;
  }

  printf("2.2: %d\n", overall_total);
}
