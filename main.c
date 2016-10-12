#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_HP 20
#define MAX_BANDWIDTH 10
#define UNFUN_FACTOR 5

int bandwidth, i, HP;
bool living;

int main(int argc, char **argv) {
  HP = MAX_HP;
  bandwidth = MAX_BANDWIDTH;
  living = true;
  char *todo[2] = {"work","home"};
  char *beingAlive[5] = {
    "exploring"
    ,"learning"
    ,"dancing"
    ,"singing"
    ,"being generally silly"
  };
  srand(time(NULL));

  for (i = 0; i < MAX_BANDWIDTH+MAX_HP-1; ++i) {
    // randomly select live or exist
    if((int)(rand()%UNFUN_FACTOR) == 0  && bandwidth > 0) {
      printf("I feel so alive %s!\n", beingAlive[(int)(rand()%5)]);
      bandwidth--;
    } else {
      printf("%s\n", todo[(int)(rand()%2)]);
      HP--;
    }
  }
  printf("Time to just enjoy being alive for a bit\n");
  HP--;

  living = false; // can't die until you're done living

  printf("Well, good game.\n");
  return EXIT_SUCCESS;
}
