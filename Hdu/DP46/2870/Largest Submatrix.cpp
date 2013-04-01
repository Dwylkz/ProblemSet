#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define Nre(c, a, b) for (int c = a; c > b; c--)
#define MAXN (1100)
#define INFI (0x7fffffff)
#define LL long long

bool C[3][4] = {{1, 0, 1, 1}, {1, 1, 0, 1}, {0, 1, 1, 1}};
int n, m, L[MAXN], R[MAXN], F[MAXN];
char M[MAXN][MAXN];

int dp(int x)
{
    int tmax = 0;

    memset(F, 0, sizeof F);
    Rep(i, 0, n)
    {
        Rep(j, 0, m)
        {
            if (M[i][j] == x + 'a' || (M[i][j] > 'v' && C[x][M[i][j] - 'w']))
                F[j]++;
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
            tmax = max(tmax, F[j] * (R[j] - L[j] + 1));
        }
    }

    return tmax;
}

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
        Rep(i, 0, 3) maxs = max(maxs, dp(i));
        printf("%d\n", maxs);
    }

    return 0;
}
