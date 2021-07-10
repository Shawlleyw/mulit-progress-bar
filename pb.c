#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
const int N = 2;
pthread_mutex_t mutex;
void *bar(void*);

int main(){
    pthread_t tid[N];
    pthread_mutex_init(&mutex, NULL);
    for(int i = 0; i < N; i++)
        tid[i] = -1;
    int num[10];
    for(int i = 0; i < 10; i++)
        num[i] = i;
    for(int i = 0; i < N; i++)
        pthread_create(tid+i, NULL, bar, num+i);
    
    for(int i = 0; i < N; i++)
        pthread_join(tid[i], NULL);
    return 0;
}

void *bar(void* parg){
    int id = *(int *)parg;
    id++;
#ifdef DEBUG
    pthread_mutex_lock(&mutex);
    printf("%d\n",id);
    fflush(stdout);
    pthread_mutex_unlock(&mutex);
#else
    char s[20];
    for(int i = 0; i < 20; i++)
        s[i] = '-';
    for(int i = 0; i < 20; i++){
        s[i] = '#';
        pthread_mutex_lock(&mutex);
        printf("\033[%dB", id);
        printf("\r[progressing] [%s] [%d / 100]  [thread_id: %d]", s, (i+1)*5, id);
        printf("\033[%dA", id);
        fflush(stdout);
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
#endif
    return NULL;
}