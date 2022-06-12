#include <stdio.h>
#define MAX 101
#define COST_INF 1e9

int graph[MAX][MAX];

int main(){

    int n,m;
    int a,b,c;

    for(int i = 0;i < MAX;i++){
        for(int j = 0;j < MAX;j++){
            graph[i][j] = COST_INF;
            if( i == j ) graph[i][j] = 0; //자기 자신으로 가는 비용은 0
        }
    } // 초기화

    scanf("%d\n%d",&n,&m);
    for(int i = 0;i < m;i++){
        scanf("%d %d %d", &a, &b, &c);
        if( c < graph[a][b] ) graph[a][b] = c;
    }//입력

    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++) if(graph[i][j] > (graph[i][k]+graph[k][j])) graph[i][j] = graph[i][k]+graph[k][j];
        }
    }

    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            if(graph[i][j] == COST_INF) printf("0 ");
            else printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    return 0;
}