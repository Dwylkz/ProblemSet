#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <queue>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define Clr(c, a, b) fill(c, c + a, b)
#define LLU long long
#define MAXN (200)

int m, n, s, d;
bool G[MAXN][MAXN];

int main()
{
    #if 1
        freopen("test.txt", "rt", stdin);
    #endif
    int t, u, v, cou;

    while (~scanf("%d%d%d%d", &n, &m, &s, &d))
    {
        cou = n;
        Rep(i, 0, MAXN) Clr(G[i], MAXN, 0);
        while (m--)
        {
            scanf("%d%d", &u, &v);
            G[u][v] = G[v][u] = 1;
        }
        #if 1
            Rep(i, 0, n)
            {
                Rep(j, 0, n)
                    printf("%d", G[i][j]);
                putchar('\n');
            }
        #endif
        Rep(k, 0, n) Rep(i, 0, n) Rep(j, 0, n)
            if (G[i][k] && G[k][j])
                G[i][j] = 1;
        Rep(i, 0, n) if (G[s][i] && G[i][d])
            cou--;
        #if 1
            Rep(i, 0, n)
            {
                Rep(j, 0, n)
                    printf("%d", G[i][j]);
                putchar('\n');
            }
        #endif
        printf("%d\n", cou);
    }

    return 0;
}
