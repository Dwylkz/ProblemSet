#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define Nre(c, a, b) for (int c = a; c > b; c--)
#define MAXN (1100)
#define INFI (0x7fffffff)
#define LL long long

int n, m, L[MAXN], R[MAXN], F[MAXN], TF[MAXN];
char M[MAXN][MAXN];

int main()
{
    #if 1
        freopen("test.txt", "rt", stdin);
    #endif

    int maxs;

    while (~scanf("%d%d", &n, &m))
    {
        maxs = 0;
        Rep(i, 0, n) scanf("%s", M[i]);
        memset(F, 0, sizeof F);
        Rep(i, 0, n)
        {
            Rep(j, 0, m)
            {
                if (M[i][j] == '1')
                    F[j]++;
                else F[j] = 0;
                TF[j] = F[j];
            }
            sort(TF, TF + m);
            Rep(j, 0, m)
            {
                L[j] = j;
                while (L[j] && TF[L[j] - 1] >= TF[j])
                    L[j] = L[L[j] - 1];
            }
            Nre(j, m - 1, -1)
            {
                R[j] = j;
                while (R[j] < m - 1 && TF[R[j] + 1] >= TF[j])
                    R[j] = R[R[j] + 1];
                maxs = max(maxs, TF[j] * (R[j] - L[j] + 1));
            }
        }
        printf("%d\n", maxs);
    }

    return 0;
}
