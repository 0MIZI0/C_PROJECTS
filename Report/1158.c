//백준 1158 - 요세푸스 문제
#include <stdio.h>
#define MAX 5001

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
  int n,k;
  int removed = 0;

  scanf("%d %d",&n,&k);
  for(int i = 1; i <= n; i++) enqueue(i);
   
  printf("<");
  while(size != 0){
    for(int i = 1; i <= k; i++){
      if(i == k){
        ++removed;
        if(removed == n){
          printf("%d",dequeue());
        }
        else{ 
          printf("%d, ",dequeue());
        }
      }
      else{
        enqueue(dequeue());
      }
    }
  }
  printf(">");
  return 0;
}
