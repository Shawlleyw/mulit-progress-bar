#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

const int THREAD_N = 3;
const int BAR_LENGTH = 20;
typedef struct {
  int progress, count_to_val;
  pthread_t tid;
} thread_info;

void *ThreadTask(void *arg) {
  thread_info *cur_thread = arg;
  for (cur_thread->progress = 0;
      cur_thread->progress < cur_thread->count_to_val;
      cur_thread->progress++) {
        usleep(10000); 
  }
  return NULL;
}

void UpdateBar(thread_info* cur){
    int percent = (cur->progress * 100 / cur->count_to_val);
    printf("\r[progressing] [");
    for (int i = 0; i < BAR_LENGTH; i++){
        if(i <= percent * BAR_LENGTH / 100)putchar('#');
        else putchar('-');
    }
    printf("] [%d%% / 100%%]\n", percent);
}

int main(int argc, char **argv) {
  srand(time(NULL));
  thread_info th[THREAD_N];
  memset(th, -1, sizeof(th));
  for (int i = 0; i < THREAD_N; i++) {
    th[i].count_to_val = rand() % 1000 + 100;
    pthread_create(&th[i].tid, NULL, ThreadTask, &th[i]);
  }
  int done = 0;
  while (!done) {
    done = 1;
    for (int i = 0; i < THREAD_N; i++) {
        UpdateBar(&th[i]);
        if(th[i].progress != th[i].count_to_val)done = 0;
    }
    if(!done){
        printf("\033[%dF", THREAD_N);
    }
    usleep(10000);
  }
  return 0;
}