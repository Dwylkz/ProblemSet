#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define Clr(c, a, b) fill(c, c + a, b)
#define MAXN (26)

double v, p[MAXN];

int main()
{
    #if 1
        freopen("test.txt", "rt", stdin);
    #endif

    int n;
    char d[2];
    double tp;

    scanf("%lf%d", &v, &n);
    Clr(p, MAXN, 0.0);
    Rep(i, 0, n)
    {
        scanf("%1s %lf", d, &tp);
        p[d[0] - 'A'] = tp;
    }
    Rep(i, 0, MAXN)
        if (p[i] >= 0.05 * v)
            printf("%c\n", 'A' + i);

    return 0;
}
