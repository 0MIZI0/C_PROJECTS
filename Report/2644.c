#include<stdio.h>
#include<string.h>
#define MAX_SIZE 101
 
int n, a, b, m;
int map[MAX_SIZE][MAX_SIZE];
int visited[MAX_SIZE] = { 0 };
int ans[MAX_SIZE] = { 0 };
 
int queue[MAX_SIZE];
int start = 0; int end = 0;
 
void enqueue(int v) {
    queue[end] = v;
    end = (end + 1) % MAX_SIZE;
}
 
int dequeue() {
    int temp = queue[start];
    start = (start + 1) % MAX_SIZE;
    return temp;
}
 
int isQueEmpty() {
    return (start == end) ? 1 : 0;
}
 
void do_bfs(int start) {
    enqueue(start);
    visited[start] = 1;
    while (isQueEmpty() == 0) {
        int next_node = dequeue();
        for (int i = 1; i <= n; i++) {
            if (visited[i] == 0 && map[next_node][i] == 1) {
                visited[i] = 1;
                ans[i] = ans[next_node] + 1;
                enqueue(i);
            }
        }
    }
}
 
void solution() {
    do_bfs(a);
    if (ans[b] == 0) {
        printf("-1");
    }
    else {
        printf("%d", ans[b]);
    }
}
 
 
int main() {
    scanf("%d", &n);
    scanf("%d %d", &a, &b);
    scanf("%d", &m);
    int parent, child;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &parent, &child);
        map[parent][child] = 1;
        map[child][parent] = 1;
    }
    solution();
    return 0;
}