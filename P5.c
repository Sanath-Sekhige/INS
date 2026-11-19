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

/*
Attempt 1: hash = 125 --> No collision
Attempt 2: hash = 633 --> No collision
Attempt 3: hash = 763 --> No collision
Attempt 4: hash = 439 --> No collision
Attempt 5: hash = 757 --> No collision
...
Attempt 35: hash = 975 --> No collision
Attempt 36: hash = 289 --> No collision
Attempt 37: hash = 755 --> No collision
Attempt 38: hash = 703 --> No collision
Attempt 39: hash = 763 --> Collision Detected!
Total attempts: 39, collided value: 763
*/