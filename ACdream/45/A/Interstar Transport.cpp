#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define MAXV (52)
#define INFI (0x7fffffff)

int s, p, n, G[MAXV][MAXV], P[MAXV][MAXV], L[MAXV][MAXV];

void G_ini(){
    Rep(u, 0, MAXV){
        P[u][u] = u;
        Rep(v, 0, MAXV) L[u][v] = G[u][v] = INFI;
    }
}

void Floyd(){
    Rep(k, 0, s) Rep(i, 0, s) Rep(j, 0, s)
        if ((G[i][j] - G[i][k] == G[k][j] && L[i][j] - L[i][k] > L[k][j]) ||
            G[i][j] - G[i][k] > G[k][j])
            {
                G[i][j] = G[i][k] + G[k][j];
                L[i][j] = L[i][k] + L[k][j];
                P[i][j] = P[k][j];
            }
    #if 0
        Rep(u, 0, s){
            Rep(v, 0, s) printf(" %3d", G[u][v]);
            puts("");
        }
    #endif
}

void Path(int u, int v)
{
    if (P[u][v] != u) Path(u, P[u][v]);
    printf("%c ", P[u][v] + 'A');
}

int main()
{
    #if 1
        freopen("test.txt", "rt", stdin);
    #endif

    char u[2], v[2];
    int w;

    while (~scanf("%d%d", &s, &p)){
        G_ini();
        while (p--){
            scanf("%1s%1s%d", u, v, &w);
            G[u[0] - 'A'][v[0] - 'A'] = w;
            L[u[0] - 'A'][v[0] - 'A'] = 1;
            P[u[0] - 'A'][v[0] - 'A'] = u[0] - 'A';
            G[v[0] - 'A'][u[0] - 'A'] = w;
            L[v[0] - 'A'][u[0] - 'A'] = 1;
            P[v[0] - 'A'][u[0] - 'A'] = v[0] - 'A';
        }
        Floyd();
        scanf("%d", &n);
        while (n--){
            scanf("%1s%1s", u, v);
            Path(u[0] - 'A', v[0] - 'A');
            puts(v);
        }
    }

    return 0;
}
