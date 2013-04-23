#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define Nre(c, a, b) for (int c = a; c > b; c--)
#define MAXN (110000)
#define LL long long

int n;
LL L[MAXN], R[MAXN], S[MAXN];

int main()
{
    #if 1
        freopen("test.txt", "rt", stdin);
    #endif
    LL maxs;

    while (scanf("%d", &n), n)
    {
        Rep(i, 0, n)
        {
            scanf("%d", S + i);
            L[i] = i;
            while (L[i] && S[L[i] - 1] >= S[i]) L[i] = L[L[i] - 1];
        }
        maxs = 0;
        Nre(i, n - 1, -1)
        {
            R[i] = i;
            while (R[i] < n - 1 && S[R[i] + 1] >= S[i]) R[i] = R[R[i] + 1];
            maxs = max(maxs, (LL)S[i] * (R[i] - L[i] + 1));
        }
        printf("%I64d\n", maxs);
    }

    return 0;
}
