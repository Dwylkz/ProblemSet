#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define Clr(c, a, b) fill(c, c + a, b)
#define MAXN (21)

int w[MAXN][MAXN][MAXN];

int main()
{
    #if 1
        freopen("test.txt", "rt", stdin);
    #endif

    int a, b, c, ans;

    Rep(i, 0, MAXN) Rep(j, 0, MAXN) Rep(k, 0, MAXN)
        if (i * j * k == 0)
            w[i][j][k] = 1;
        else if (i < j && j < k)
            w[i][j][k] = w[i][j][k - 1] + w[i][j - 1][k - 1] - w[i][j - 1][k];
        else w[i][j][k] = w[i - 1][j][k] + w[i - 1][j - 1][k] + w[i - 1][j][k - 1] - w[i - 1][j - 1][k - 1];

    while (scanf("%d%d%d", &a, &b, &c))
    {
        if (a == -1 && b == -1 && c == -1)
            break;
        if (a <= 0 || b <= 0 || c <= 0)
            ans = 1;
        else if (a > 20 || b > 20 || c > 20)
            ans = w[20][20][20];
        else ans = w[a][b][c];
        printf("w(%d, %d, %d) = %d\n", a, b, c, ans);
    }

    return 0;
}
