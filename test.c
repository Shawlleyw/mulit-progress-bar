#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

const int THREAD_N = 3;
const int BAR_LENGTH = 20;
typedef enum {
  PULL,
  UNTAR,
  COMPLETE,
}TASK;
typedef struct {
  size_t total_size;
  FILE *fp;
  TASK progress;
  pthread_t tid;
} thread_info;


void PullTask(thread_info *cur_thread){
  char *ch = malloc(1024);
  int chunk_size = 1024;
  for(int i = 0; i < cur_thread->total_size; i += chunk_size){
    int lim = chunk_size;
    if(cur_thread->total_size - i < chunk_size) lim = cur_thread->total_size - i;
    for(int j = 0; j < lim; j++)
      ch[j] = 'a' + (i+j) % 26;
    fwrite(ch, 1, lim, cur_thread->fp);
    usleep(30);
  }
  free(ch);
}

void UntarTask(thread_info *cur_thread){
  sleep(2);
}

void *ThreadTask(void *arg) {
  pthread_detach(pthread_self());
  thread_info *cur_thread = arg;
  PullTask(cur_thread);
  cur_thread->progress = UNTAR;
  UntarTask(cur_thread);
  cur_thread->progress = COMPLETE;
  return NULL;
}

double CalcSize(int num){
  return 1.0*num / (1024*1024.0);
}

void UpdateBar(thread_info* cur){
  int read_size;
  if(cur->progress == COMPLETE){
    read_size = cur->total_size;
  }
  else{
    read_size = ftell(cur->fp);
  }
  
  if(cur->progress == PULL)printf("\rpulling   ");
  else if(cur->progress == UNTAR)printf("\rextracting");
  else printf("\rcompleted                   \n ");
  /**
  for (int i = 0; i < BAR_LENGTH; i++){
      if(i <= percent * BAR_LENGTH / 100)putchar('#');
      else putchar('-');
  }
  **/
  if(cur->progress != COMPLETE)printf("%6.1lfMB/%6.1lfMB\n", CalcSize(read_size), CalcSize(cur->total_size));
}

FILE *CalcPath(int i){
  FILE *fp = NULL;
  char *path = (char*)malloc(30);
  strcpy(path, "testfile");
  char ch[2];
  ch[0] = i + '0';
  ch[1] = '\0';
  strcat(path, ch);
  fp = fopen(path, "wb");
  return fp;
}


int main(int argc, char **argv) {
  srand(time(NULL));
  thread_info th[THREAD_N];
  memset(th, 0, sizeof(0));
  for (int i = 0; i < THREAD_N; i++) {
    th[i].progress = PULL;
    th[i].fp = CalcPath(i);
    th[i].total_size = rand() % 60000000 + 10000000;
    pthread_create(&th[i].tid, NULL, ThreadTask, &th[i]);
  }
  int done = 0;
  while (!done) {
    done = 1;
    for (int i = 0; i < THREAD_N; i++) {
        UpdateBar(&th[i]);
        if(th[i].progress != COMPLETE)done = 0;
        else{
          free(th[i].fp);
          th[i].fp = NULL;
        }
    }
    if(!done){
        printf("\033[%dF", THREAD_N);
    }
    usleep(40000);
  }
  return 0;
}