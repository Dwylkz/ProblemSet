#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define Nre(c, a, b) for (int c = a; c > b; c--)
#define MAXN (1100)
#define LL long long

int n, m, F[MAXN], L[MAXN], R[MAXN];

int main()
{
    #if 1
        freopen("test.txt", "rt", stdin);
    #endif
    char ch[2];
    int maxs, T;

    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &m);
        memset(F, 0, sizeof F);
        maxs = 0;
        Rep(i, 0, n)
        {
            Rep(j, 0, m)
            {
                scanf("%1s", ch);
                if (ch[0] == 'F') F[j]++;
                else F[j] = 0;
                L[j] = j;
                while (L[j] && F[L[j] - 1] >= F[j])
                    L[j] = L[L[j] - 1];
            }
            Nre(j, m - 1, -1)
            {
                R[j] = j;
                while (R[j] < m - 1 && F[R[j] + 1] >= F[j])
                    R[j] = R[R[j] + 1];
                maxs = max(maxs, F[j] * (R[j] - L[j] + 1));
            }
        }
        printf("%d\n", 3 * maxs);
    }

    return 0;
}
