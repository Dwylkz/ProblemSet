#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define MAXN (11000)

double a0, x[MAXN];
int n;

void cb()
{
    double bn = 1;
    Rep(i, 0, 100)
    {
        printf("b%d = %lf\n", i, bn);
        bn = 1 + (double(i)) / bn;
    }
}

int main()
{
    #if 1
        freopen("test.txt", "rt", stdin);
    #endif
    int T;

    cb();

    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        Rep(i, 0, n) scanf("%lf", &x);
    }

    return 0;
}
