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

int n, t1, t2, t3;

int tun(int s)
{
    int tsu = 0;
    tsu += 2 * n;
    if (t1 > s) tsu += n - t1 + s;
    else if (t1 < s) tsu += s - t1;
    tsu += n;
    if (t1 > t2) tsu += n - t1 + t2;
    else tsu += t2 - t1;
    if (t3 > t2) tsu += n - t3 + t2;
    else tsu += t2 - t3;
    return tsu;
}

int main()
{
    #if 1
        freopen("test.txt", "rt", stdin);
    #endif

    while (scanf("%d%d%d%d", &n, &t1, &t2, &t3), n || t1 || t2 || t3)
    {
        int tsu = 0;
        Rep(i, 0, n) tsu += tun(i);
        printf("%.3lf\n", 1.0 * tsu / n);
    }

    return 0;
}
