#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <queue>
#include <map>
#include <cmath>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define Nre(c, a, b) for (int c = a; c > b; c--)
#define MAXN (1100)
#define INFI (0x7fffffff)
#define PI (3.141)
#define X2(x) ((x) * (x))
#define EPS 1e-3

double R, T, d1[MAXN], d2[MAXN];
int n;

int chk(double r1)
{
    double r2 = sqrt(T / PI - r1 * r1);
    int D = 0;
    Rep(i, 0, n)
    {
        bool a = (r1 * r1 - d1[i] >= EPS),
             b = (r2 * r2 - d2[i] >= EPS);
        D += a ^ b;
    }
    return D;
}

int main()
{
    #if 1
        freopen("test.txt", "rt", stdin);
    #endif

    int Cas = 1;
    while(scanf("%d", &n), n)
    {
        double x, y, x1, x2, y1, y2;
        scanf("%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &T);
        R = sqrt((T / PI));
        Rep(i, 0, n)
        {
            scanf("%lf%lf", &x, &y);
            d1[i] = X2(x1 - x) + X2(y1 - y);
            d2[i] = X2(x2 - x) + X2(y2 - y);
        }
        double l = 0, m1, m2, r = R;
        int ans = 0;
        while (r - l > EPS)
        {
            m1 = l + (r - l) / 3;
            m2 = r - (r - l) / 3;
            if (chk(m1) < chk(m2)) l = m1;
            else r = m2;
        }
        printf("%d. %d\n", Cas++, chk(l));
    }
    return 0;
}
