#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define Clr(c, a, b) fill(c, c + a, b)
#define MAXN (7007)
#define INF (0x7fffffff)

double a, b, c, r;
double p, s1, s2;

int main()
{
    #if 1
        freopen("test.txt", "rt", stdin);
    #endif

    int T;

    scanf("%d", &T);
    Rep(C, 0, T)
    {
        scanf("%lf%lf%lf%lf", &a, &b, &c, &r);
        p = (a + b + c) / 2;
        s1 = sqrt(p * (p - a) * (p - b)* (p - c));
        s2 = r * s1 / (1 + r);
        p = sqrt(r / (1 + r));
        printf("Case %d: %lf\n", C + 1, a * p);
    }

    return 0;
}
