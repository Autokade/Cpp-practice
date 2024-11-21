#include<bits/stdc++.h>
#include<pthread.h>
#include<unistd.h>
using namespace std;


int g = 0;

void* myThreadFun(void* vargp){
    pid_t myid = getpid();

    static int s = 0;

    ++s;
    ++g;

cout << "Thread ID: " << myid << ", Static: " << s << ", Global: ";

return nullptr;
}

int main(){
    pthread_t tid;

    for(int i= 0; i < 3; i++){
        pthread_create(&tid, NULL, myThreadFun, NULL);
        
    }
    pthread_exit(NULL);
    return 0;
}c