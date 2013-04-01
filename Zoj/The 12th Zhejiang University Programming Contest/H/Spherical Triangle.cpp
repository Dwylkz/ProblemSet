#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define Pi acos(-1.0)

double ga(double xa,double ya,double xb,double yb,double xc,double yc)
{
    double a, b , c , d;
    a = cos(yb) * cos(yc) * cos(xb - xc) + sin(yb) * sin(yc);
    b = cos(ya) * cos(yc) * cos(xa - xc) + sin(ya) * sin(yc);
    c = cos(ya) * cos(yb) * cos(xa - xb) + sin(ya) * sin(yb);
    d = (a - b * c) / (sin(acos(b)) * sin(acos(c)));
    return acos(d);
}

int main()
{
    #if 1
        freopen("test.txt", "rt", stdin);
    #endif
    int T;
    double a[3], b[3], c[3];

    scanf("%d", &T);
    while (T--)
    {
        Rep(i, 0, 3)
        {
            scanf("%lf%lf", a + i, b + i);
            a[i] *= Pi / 180.0;
            b[i] *= Pi / 180.0;
        }
        c[0] = ga(a[0], b[0], a[1], b[1], a[2], b[2]);
        c[1] = ga(a[1], b[1], a[2], b[2], a[0], b[0]);
        c[2] = ga(a[2], b[2], a[0], b[0], a[1], b[1]);
        printf("%.2lf\n", (c[0] + c[1] + c[2]) * 180 / Pi);
    }

    return 0;
}
