#include<stdio.h>
#define MAX_QUEUE 10000 //100 * 100
#define MAX_INT 101 //최대 정수
int i, j, N, M;
 
int map[MAX_INT][MAX_INT];
int visit[MAX_INT][MAX_INT];
 
 
struct node {
    int x;
    int y;
};
 
struct node queue[MAX_QUEUE + 1];
int end = 0;
int start = 0;
int max = 0;
 
int vectX[4] = { 0,0,1,-1 };
int vectY[4] = { 1, -1, 0, 0 };
 
 
struct node deque() {
    struct node temp = queue[start];
    start = (start + 1) % MAX_QUEUE;
    return temp;
}
 
int isQueEmpty() {
    if (start == end) {
        return 0;
    }
    return 1;
}
 
void enque(int X, int Y) {
    struct node temp;
    temp.x = X;
    temp.y = Y;
    queue[end] = temp;
    end = (end + 1) % MAX_QUEUE;
}
 
void do_BFS() {
    int nextX;
    int nextY;
    while (isQueEmpty()) {
        
        struct node k = deque();
 
        for (i = 0; i < 4; i++) {
            nextX = k.x + vectX[i];
            nextY = k.y + vectY[i];
 
            if (nextX >= 1 && nextX <= M && nextY >= 1 && nextY <= N) {
        
                if (map[nextX][nextY] == 1) {
                    if (visit[nextX][nextY] == 0) {
                        visit[nextX][nextY] = visit[k.x][k.y] + 1;
                        enque(nextX, nextY);
                    }
                }
            }
        }
    }
}
 
int main() {
    scanf("%d %d", &M, &N);
    for (i = 1; i <= M; i++) {
        for (j = 1; j <= N; j++) {
            scanf("%1d", &map[i][j]);
        }
    }
 
    visit[1][1] = 1;
    enque(1, 1);
    do_BFS();
    printf("%d\n", visit[M][N]);
 
    return 0;
}