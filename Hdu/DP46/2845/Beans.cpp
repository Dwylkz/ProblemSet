#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define Nre(c, a, b) for (int c = a; c > b; c--)
#define MAXN (220000)
#define INFI (0x7fffffff)
#define LL long long

int n, m, R[MAXN], C[MAXN];

int main()
{
    #if 1
        freopen("test.txt", "rt", stdin);
    #endif

    int B, dp;

    while (~scanf("%d%d", &n, &m))
    {
        Rep(i, 2, n + 2)
        {
            Rep(j, 2, m + 2)
            {
                scanf("%d", &B);
                C[j] = max(C[j - 1], C[j - 2] + B);
            }
            R[i] = max(R[i - 1], R[i - 2] + C[m + 1]);
        }
        printf("%d\n", R[n + 1]);
    }

    return 0;
}
