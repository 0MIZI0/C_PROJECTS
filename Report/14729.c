// 백준 2164 - 카드 2
#include <stdio.h>
#define MAX 500001

int queue[MAX];
int front = 0, rear=0, size=0;

// 원형 큐 push
void enqueue(int item){
  rear = (rear + 1) % MAX;
  queue[rear] = item;
  size++;
}

// 원형 큐 pop
int dequeue(){
  front = (front + 1) % MAX;
  size--;
  return queue[front];
}

int main(){
    int i, N;
    scanf("%d", &N);    

    for(i = 1;i <= N; i++) enqueue(i);
    while( size != 1){
        dequeue();
        enqueue(dequeue());
    }

    printf("%d", dequeue());
    return 0;
}