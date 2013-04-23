#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define MAXN (11000)

int n, r[MAXN];
double k, t1, t2, w[MAXN];

bool cmp(int a, int b)
{
    if (w[a] != w[b]) return w[a] > w[b];
    return a < b;
}

int main()
{
    #if 0
        freopen("test.txt", "rt", stdin);
    #endif

    while (~scanf("%d%lf%lf%lf", &n, &t1, &t2, &k))
    {
        Rep(i, 0, n)
        {
            double ai, bi;
            r[i] = i;
            scanf("%lf%lf", &ai, &bi);
            w[i] = ai * t1 * (1 - k / 100.0) + bi * t2;
            if (bi * t1 * (1 - k / 100.0) + ai * t2 > w[i])
                w[i] = bi * t1 * (1 - k / 100.0) + ai * t2;
        }
        sort(r, r + n, cmp);
        Rep(i, 0, n) printf("%d %.2lf\n", r[i] + 1, w[r[i]]);
    }

    return 0;
}
