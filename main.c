#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>

#define NUM_THREADS 4

// http://randu.org/tutorials/threads/

/* create thread argument struct for thr_func() */
typedef struct _thread_data_t {
  int tid;
  char *stuff[];
} thread_data_t;

void *live(void *arg) {
  thread_data_t *data = (thread_data_t *)arg;
  sleep((int)(rand()%2));
  printf("printing alive\n");
  printf("I feel so alive %s!\n",
    (char*)(data->stuff)[(int)(rand()%5)]);
  pthread_exit(NULL);
}

int main(int argc, char **argv) {
  pthread_t thr[NUM_THREADS];
  int bandwidth, rc;
  /* create a thread_data_t argument array */
  thread_data_t thr_data[NUM_THREADS];

  int i;
  int HP = 100;
  bool living = true;
  const char *todo[2] = {"work","home"};
  const char *beingAlive[5] = {
    "exploring"
    ,"learning"
    ,"being silly"
    ,"dancing"
    ,"singing"
  };
  srand(time(NULL));

  for (i = 0; i < NUM_THREADS; ++i) {
    thr_data[i].tid = bandwidth;
    if ((rc = pthread_create(&thr[i], NULL, live, &thr_data[i]))) {
      printf("thread error\n");
      fprintf(stderr, "error: pthread_create, rc: %d\n", rc);
      return EXIT_FAILURE;
    }
  }
  while(HP > 0){
    printf("printing work/home\n");
    printf("%s\n", todo[(int)(rand()%2)]);
    HP--;
    if(HP <= 0){
      for (i = 0; i < NUM_THREADS; ++i) {
        pthread_join(thr[i], NULL);
      } // can't die until you're done living
      living = false;
      break;
    }
  }
  printf("Well, good game.");
  return EXIT_SUCCESS;
}
