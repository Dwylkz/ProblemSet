#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define MAXN (55)

double m, n;

int main()
{
    #if 1
        freopen("test.txt", "rt", stdin);
    #endif
    int ce;
    double p, Ex, k;

    while (~scanf("%lf%lf", &n, &m))
    {
        p = (m + n) * (m + n - 1.0);
        ce = floor(m / 2.0);
        Ex = ceil(m / 2.0);
        k = (2.0 * n + m - 1.0) * m;
        Rep(i, 0, ce) Ex *= (m - 2 * i) * (m - 2 * i - 1) / p;
        if ((int)m % 2) Ex *= k / p;
        printf("%.2lf\n", Ex);
        #if 1
            puts("test :");
            printf(" ceil = %d\n", ce);
            printf(" k = %.2lf\n", k);
        #endif
    }

    return 0;
}
