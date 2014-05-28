#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define Clr(c, a) memset(c, a, sizeof c)
#define LLU long long
#define MAXN (1100)
#define MOD (0x7fffffff)

struct Node
{
    int x, y;
};

char M[MAXN][MAXN];
int mov[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
int n;
LLU dp[MAXN][MAXN];
bool vis[MAXN][MAXN], inq[MAXN][MAXN];

bool fifl()
{
    queue<Node> Q;
    Node tq = {0, 0};

    Clr(vis, 0);
    Clr(inq, 0);
    Q.push(tq);
    inq[tq.x][tq.y] = 1;
    while (!Q.empty())
    {
        tq = Q.front();
        Q.pop();
        vis[tq.x][tq.y] = 1;
        inq[tq.x][tq.y] = 0;
        if (tq.x == n - 1 && tq.y == n - 1)
            break;
        Rep(i, 0, 4)
        {
            int x = tq.x + mov[i][0], y = tq.y + mov[i][1];

            if (0 <= x && x < n && 0 <= y && y < n && M[x][y] != '#' && !vis[x][y])
            {
                Node in = {x, y};
                if (!inq[x][y])
                {
                    Q.push(in);
                    inq[x][y] = 1;
                }
            }
        }
    }

    return vis[n - 1][n - 1];
}

int main()
{
    #if 1
        freopen("test.txt", "rt", stdin);
    #endif

    while (~scanf("%d", &n))
    {
        Clr(dp, 0);
        Rep(i, 0, n) scanf("%s", M + i);
        dp[0][0] = 1;
        Rep(i, 0, n)
            Rep(j, 0, n)
            {
                if (i + 1 < n && M[i + 1][j] != '#')
                    dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % MOD;
                if (j + 1 < n && M[i][j + 1] != '#')
                    dp[i][j + 1] = (dp[i][j + 1] + dp[i][j]) % MOD;
            }
        #if 0
            Rep(i, 0, n)
            {
                Rep(j, 0, n) printf(" %d", dp[i][j]);
                puts("");
            }
        #endif
        if (dp[n - 1][n - 1]) printf("%lld\n", dp[n - 1][n  -1]);
        else puts(fifl()? "THE GAME IS A LIE": "INCONCEIVABLE");
    }

    return 0;
}
