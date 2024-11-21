#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <queue>
#include <unistd.h>

#define BUFFER_SIZE 5

using namespace std;

queue<int> buffer;
sem_t empty_slots, full;
pthread_mutex_t mutex;

void* producer(void* arg){
    int item;
    while(true){
        item = rand() % 100;
        sem_wait(&empty_slots);
        pthread_mutex_lock(&mutex);
        buffer.push(item);
        cout << "Produced: " << item << endl;
        pthread_mutex_unlock(&mutex);
        sem_post(&full);
        sleep(1);
    }
}

void* consumer(void* arg){
    int item;
    while(true){
        sem_wait(&full);
        pthread_mutex_lock(&mutex);
        item = buffer.front();
        buffer.pop();
        cout << "Consumed : " << item << endl;
        pthread_mutex_unlock(&mutex);
        sem_post(&empty_slots);
        sleep(1);
    }
}

int main(){
    pthread_t prodThread, consThread;

    sem_init(&empty_slots, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);
    pthread_mutex_init(&mutex, NULL);

    pthread_create(&prodThread, NULL, producer, NULL);
    pthread_create(&prodThread, NULL, consumer, NULL);

    pthread_join(prodThread, NULL);
    pthread_join(consThread, NULL);
    sem_destroy(&empty_slots);
    sem_destroy(&full);

    pthread_mutex_destroy(&mutex);

    return 0;
}