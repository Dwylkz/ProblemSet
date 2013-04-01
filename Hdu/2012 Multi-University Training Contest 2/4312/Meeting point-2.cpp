#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define MAXN (110000)
#define INFI (0x7fffffff)
#define INFL (0x7fffffffffffffffLL)
#define EPS (1e-8)
typedef double LL;
typedef int AI[MAXN];
typedef LL AL[MAXN];

struct Vec
{
    double x, y;
} V[MAXN];

int n;

bool cmpx(int p, int q)
{
    return V[p].x < V[q].x;
}

bool cmpy(int p, int q)
{
    return V[p].y < V[q].y;
}


int main()
{
    #if 1
        freopen("test.txt", "rt", stdin);
    #endif
    int T;

    scanf("%d", &T);
    while (T--)
    {
        static AL s, sx, sy;
        static AI x, y;
        scanf("%d", &n);
        Rep(i, 0, n)
        {
            double tx, ty;
            scanf("%lf%lf", &tx, &ty);
            V[i].x = (tx - ty) / 2;
            V[i].y = (tx + ty) / 2;
            x[i] = y[i] = i;
        }
        memset(s, 0, sizeof s);
        memset(sx, 0, sizeof sx);
        memset(sy, 0, sizeof sy);
        sort(x, x + n, cmpx);
        sort(y, y + n, cmpy);
        Rep(i, 0, n)
        {
            sx[i] = V[x[i]].x + sx[i - 1] * (i > 0);
            sy[i] = V[y[i]].y + sy[i - 1] * (i > 0);
        }
        Rep(i, 0, n)
        {
            s[x[i]] += (LL)(2 * i - n + 2) * V[x[i]].x + sx[n - 1] - 2 * sx[i];
            s[y[i]] += (LL)(2 * i - n + 2) * V[y[i]].y + sy[n - 1] - 2 * sy[i];
        }
        LL ans = INFL;
        Rep(i, 0, n) ans = min(ans, s[i]);
        printf("%.0lf\n", ans);
    }

    return 0;
}
