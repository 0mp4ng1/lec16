#include <stdio.h>
#include <algorithm>

#define INF 1000000 //무한대
int V, E;
int d[401][401];

int main(){
    scanf("%d %d", &V, &E);

    for(int i=1;i<=V;i++){
        for(int j=1;j<=V;j++){
            d[i][j] = INF;
        }
    }

    for(int i=0;i<E;i++){
        int a,b,c;
        scanf("%d %d %d", &a, &b, &c);
        d[a][b] = c;
    }

    for(int k=1;k<=V;k++){
        for(int i=1;i<=V;i++){
            for(int j=1;j<=V;j++){
                d[i][j] = std::min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    int result = INF;
    for(int i=1;i<=V;i++){
        if(result > d[i][i]) result = d[i][i];
    }

    if(result == INF) printf("-1\n");
    else printf("%d\n",result);
    return 0;
}
