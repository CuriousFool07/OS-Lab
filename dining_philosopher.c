#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>

sem_t room;
sem_t ch[5];

void *philosopher(void* arg){
    int i = *(int *)arg;

    printf("\nPhilosopher %d entered the room.\n",i);

    sem_wait(&room);

    sem_wait(&ch[i]);
    printf("Philosopher %d has picked up left chopstick.\n",i);

    sem_wait(&ch[(i+1)%5]);
    printf("Philosopher %d has picked up right chopstick.\n",i);

    printf("Philosopher %d is eating.\n",i);

    sem_post(&ch[i]);
    sem_post(&ch[(i+1)%5]);

    printf("Philosopher %d finished eating.\n",i);

    sem_post(&room);

    return NULL;
}

int main(){
    pthread_t p[5];
    int id[5]={1,2,3,4,5};

    sem_init(&room,0,4);

    for(int i=0;i<5;i++){
        sem_init(&ch[i],0,1);
    }

    for(int i=0;i<5;i++){
        pthread_create(&p[i],NULL,philosopher,&id[i]);
    }
    for(int i=0;i<5;i++){
        pthread_join(p[i],NULL);
    }
    return 0;
}