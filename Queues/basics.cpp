#include <stdio.h>
#define MAXLEN 100

typedef struct {
    int element[MAXLEN];
    int front, rear;
} queue;

queue init() {
    queue Q;
    Q.front = Q.rear = -1;
    return Q;
}

int size(queue Q) {
    return (Q.rear - Q.front + 1);
}

int isEmpty(queue Q) {
    return (Q.front == -1 || Q.front > Q.rear);
}

int isFull(queue Q) {
    return (Q.rear == MAXLEN - 1);
}

int front(queue Q) {
    if (isEmpty(Q)) {
        printf("Empty queue\n");
        return -1;  // Indicate empty queue
    }
    return Q.element[Q.front];
}

queue enqueue(queue Q, int x) {
    if (isFull(Q)) {
        printf("OVERFLOW\n");
    } else if (isEmpty(Q)) {
        Q.front = Q.rear = 0;
        Q.element[Q.rear] = x;
    } else {
        Q.rear++;
        Q.element[Q.rear] = x;
    }
    return Q;
}

queue dequeue(queue Q) {
    if (isEmpty(Q)) {
        printf("UNDERFLOW\n");
    } else {
        Q.front++;
        if (Q.front > Q.rear) {
            Q.front = Q.rear = -1;  // Reset queue if it becomes empty
        }
    }
    return Q;
}

void print(queue Q) {
    if (isEmpty(Q)) {
        printf("Queue is empty\n");
        return;
    }
    for (int i = Q.front; i <= Q.rear; i++) {
        printf("%d ", Q.element[i]);
    }
    printf("\n");
}

int main() {
    queue Q = init();
    Q = enqueue(Q, 5);
    Q = enqueue(Q, 3);
    Q = dequeue(Q);
    Q = enqueue(Q, 7);
    Q = dequeue(Q);
    printf("Current queue: "); print(Q);
    printf(" with front = %d.\n", front(Q));
    Q = enqueue(Q, 9);
    Q = enqueue(Q, 3);
    Q = enqueue(Q, 1);
    printf("Current queue: "); print(Q);
    printf(" with front = %d.\n", front(Q));
    printf("Size is %d.\n", size(Q));
    return 0;
}
