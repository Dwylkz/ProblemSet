#include <iostream>
#include <memory.h>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cmath>
using namespace std;
#define LLD unsigned long long
#define MAXI 100001

LLD eul[MAXI];
int fac[MAXI][20], l[MAXI];

void ini()
{
    int i, j;
    eul[1] = 1;
    for (i = 2; i < MAXI; i++) {
        if (eul[i] == 0)
            for (j = i; j < MAXI; j += i)
            {
                if (eul[j] == 0) eul[j] = j;
                fac[j][l[j]++] = i;
                eul[j] -= eul[j] / i;
            }
        eul[i] += eul[i - 1];
    }
}

LLD DFS(LLD x, LLD tn, LLD n)
{
    int i;
    LLD tsu = 0;
    for (i = x; i < l[n]; i++)
        tsu += tn / fac[n][i] - DFS(i + 1, tn / fac[n][i], n);
    return tsu;
}

int main()
{
    int T, C, a, b, c, d, k;
    LLD tsu;

    ini();
    scanf("%d", &T);
    for (C = 1; C <= T; C++)
    {
        scanf("%d%d%d%d%d", &a, &b, &c, &d, &k);
        if (k == 0) tsu = 0;
        else
        {
            b /= k; d /= k;
            if (b > d) swap(b, d);
            tsu = eul[b];
            for (c = b + 1; c <= d; c++)
                tsu += b - DFS(0, b, c);
        }
        printf("Case %d: %llu\n", C, tsu);
    }

    return 0;
}
