#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define MAXN (20)
#define INFI (10000)
#define X2(x) (x * x)

int n, b, w, c, B[MAXN][MAXN], mov[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
bool vis[MAXN][MAXN];

void DFS(int x, int y)
{
    c++;
    vis[x][y] = 1;
    Rep(i, 0, 4)
    {
        int tx = mov[i][0] + x, ty = mov[i][1] + y;
        if (0 < tx && tx <= n && 0 < ty && ty <= n)
        {
            if (B[tx][ty] == 1) w++;
            if (B[tx][ty] == 2) b++;
            if (!vis[tx][ty] && !B[tx][ty]) DFS(tx, ty);
        }
    }
}

int main()
{
#if 1
    freopen("test.txt", "rt", stdin);
#endif

    while (scanf("%d", &n), n)
    {
        int x, y, cb = 0, cw = 0;

        memset(B, 0, sizeof B);
        scanf("%d%d", &b, &w);
        while(b--)
        {
            scanf("%d%d", &x, &y);
            B[x][y] = 2;
        }
        while (w--)
        {
            scanf("%d%d", &x, &y);
            B[x][y] = 1;
        }
        #if 0
            Rep(i, 1, n + 1)
            {
                Rep(j, 1, n + 1)
                    printf("%d", B[i][j]);
                puts("");
            }
        #endif
        memset(vis, 0, sizeof vis);
        Rep(i, 1, n + 1) Rep(j, 1, n + 1)
            if (!vis[i][j] && !B[i][j])
            {
                b = w = c = 0;
                DFS(i, j);
                if (b && !w) cb += c;
                if (!b && w) cw += c;
            }
        if (cb == cw) puts("Draw");
        else
        {
            printf(cb > cw? "Black": "White");
            printf(" wins by %d\n", abs(cb - cw));
        }
    }

    return 0;
}
