#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define MAXN 755
#define INFI 0x7fffffff
#define Sqr(x) ((x) * (x))

int n, m, x[MAXN], y[MAXN], G[MAXN][MAXN];
int pre[MAXN], mst_c[MAXN];
bool ims[MAXN];

void Prim()
{
    int min_d, min_i;
    Rep(i, 0, n)
    {
        mst_c[i] = G[0][i];
        pre[i] = 0;
    }
    ims[0] = true;
    Rep(k, 0, n - 1)
    {
        min_d = INFI;
        Rep(i, 0, n)
            if (!ims[i] && min_d > mst_c[i])
            {
                min_d = mst_c[i];
                min_i = i;
            }
        if (min_d) printf("%d %d\n", pre[min_i] + 1, min_i + 1);
        ims[min_i] = true;
        mst_c[min_i] = min_d;
        Rep(i, 0, n)
            if (!ims[i] && G[min_i][i] < mst_c[i])
            {
                mst_c[i] = G[min_i][i];
                pre[i] = min_i;
            }
    }
}

int main()
{
    scanf("%d", &n);
    Rep(i, 0, n)
    {
        scanf("%d%d", x + i, y + i);
        Rep(j, 0, n)
            G[i][j] = G[j][i] = Sqr(x[i] - x[j]) + Sqr(y[i] - y[j]);
    }
    scanf("%d", &m);
    Rep(i, 0, m)
    {
        scanf("%d%d", x, y);
        x[0]--; y[0]--;
        G[x[0]][y[0]] = G[y[0]][x[0]] = 0;
    }
    Prim();

    return 0;
}
