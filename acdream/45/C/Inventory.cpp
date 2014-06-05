#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define MAXV (52)
#define INFI (0x7fffffff)

int n;

int main()
{
    #if 1
        freopen("test.txt", "rt", stdin);
    #endif

    int Cas, pi[2], di[2], ni[2], dn, cost;

    scanf("%d", &Cas);
    while (Cas--){
        scanf("%d", &n);
        cost = 0;
        p[0] = ni[0] = d[0] = -1;
        Rep(i, 0, n){
            scanf("%d%d%d", p + 1, n + 1, d + 1);
            if (i && p[0] < p[1]){
                dn = max(n[0], n[0] - d[1]);
                cost += p[0] * dn + p[1] * (d[1] - )
            }
            p[0] = p[1];
            n[0] = n[1];
            d[0] = d[1];
        }
    }

    return 0;
}
