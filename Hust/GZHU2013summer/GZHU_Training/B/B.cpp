#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define Nre(c, a, b) for (int c = a; c > b; c--)
#define MAXN (5500)

int main()
{
    #if 1
        freopen("test.txt", "rt", stdin);
    #endif

    int T, t, f, c, p;

    while (scanf("%d%d%d%d", &t, &f, &c, &p), t || f || c || p)
    {
        bool yes = 0;
        double tl = 9 * max(0.0, f - 0.5) + 4 * max(0.0, c - 0.5) + 4 * max(0.0, p - 0.5);
        double tu = 9 * max(f + 0.4, 0.0) + 4 * max(0.0, c + 0.4) + 4 * max(0.0, p + 0.4);
        /*Rep(i, -5, 5) Rep(j, -5, 5) Rep(k, -5, 5)
        {
            double tf = i * 0.1 + f;
            double tc = j * 0.1 + c;
            double tp = k * 0.1 + p;
            double tt = tf * 9 + tc * 4 + tp * 4;
            if (tt + 0.5 == t)
            {
                printf("%d %lf\n", t, tt);
                yes = 1;
            }
        }*/
        puts(int(tl + 0.5) <= t && int(t + 0.5) <= tu? "yes": "no");
    }

    return 0;
}
