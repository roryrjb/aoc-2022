#include <stdio.h>
#include <stdlib.h>

static inline int smallest_index(long *arr, int size) {
  int smallest = 0;

  for (int i = 0; i < size; i++) {
    if (arr[i] < arr[smallest]) {
      smallest = i;
    }
  }

  return smallest;
}

int main() {
  char data[16];
  long top3[3] = {0, 0, 0};

  FILE *input;

  if (fopen_s(&input, "1.txt", "r")) {
    perror("fopen_s");
    exit(EXIT_FAILURE);
  }

  long calories = 0;

  while (fgets(data, 16, input) != NULL) {
    calories += strtol(data, NULL, 10);
    if (data[0] == '\n') {
      int index = smallest_index(top3, 3);
      long smallest = top3[index];

      if (calories > smallest) {
        top3[index] = calories;
      }

      calories = 0;
    }
  }

  printf("1.2: %ld + %ld + %ld = %ld\n", top3[0], top3[1], top3[2],
         top3[0] + top3[1] + top3[2]);

  return 0;
}