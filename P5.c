#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int seen[1000] = {0};
  int count = 0, h;

  srand(time(NULL));

  while (1) {
    h = rand() % 1000;
    count++;
    printf("Attempt %d: hash = %d --> ", count, h);
    if (seen[h]) {
      printf("Collision Detected!\n");
      break;
    }
    printf("No collision\n");
    seen[h] = 1;
  }

  printf("Total attempts: %d, collided value: %d\n", count, h);
  return 0;
}