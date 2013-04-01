#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define MAXN (200)
#define MAXP (MAXN * MAXN + 1)
#define INFI (0x7fffffff)

int G[MAXN][MAXN], mov[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
bool C[MAXP], vis[MAXN][MAXN];

void SP()
{
    int i, j;
    C[1] = 1;
    for (i = 4; i < MAXP; i += 2) C[i] = 1;
    for (i = 3; i < MAXP; i += 2) if (!C[i])
        for (j = i + i; j < MAXP; j += i) C[j] = 1;
    #if 0
        Rep(i, 2, MAXN) if (!C[i]) printf(" %d", i);
    #endif
}

void G_ini()
{
    int i, j, num = MAXN * MAXN;
    Rep(s, 0, MAXN / 2)
    {
        i = j = s;
        for (; j < MAXN - s - 1; j++) G[i][j] = num--;
        for (; i < MAXN - s - 1; i++) G[i][j] = num--;
        for (; j > s; j--) G[i][j] = num--;
        for (; i > s; i--) G[i][j] = num--;
    }
    #if 0
        Rep(i, 0, MAXN)
        {
            Rep(j, 0, MAXN) printf("(%3d)", G[i][j], P[i][j]);
            puts("");
        }
    #endif
}

struct Node
{
    int x, y, d;
    Node(int tx = 0, int ty = 0, int td = 0)
    {
        x = tx;
        y = ty;
        d = td;
    }
};

int BFS(int s, int t)
{
    int x, y;
    queue<Node> Q;

    Rep(i, 0, MAXN) Rep(j, 0, MAXN)
        if (G[i][j] == s)
        {
            x = i;
            y = j;
        }
    memset(vis, 0, sizeof vis);
    Q.push(Node(x, y, 0));
    vis[x][y] = 1;
    while (!Q.empty())
    {
        Node u = Q.front();
        Q.pop();
        if (G[u.x][u.y] == t) return u.d;
        Rep(i, 0, 4)
        {
            x = u.x + mov[i][0];
            y = u.y + mov[i][1];
            if (0 <= x && x < MAXN && 0 <= y && y < MAXN &&
                !vis[x][y] && C[G[x][y]])
                {
                    Q.push(Node(x, y, u.d + 1));
                    vis[x][y] = 1;
                }
        }
    }

    return INFI;
}

int main()
{
#if 1
    freopen("test.txt", "rt", stdin);
#endif

    int Cas = 1, x, y;

    SP();
    G_ini();
    while (~scanf("%d%d", &x, &y))
    {
        int dis = BFS(x, y);
        printf("Case %d: ", Cas++);
        if (dis != INFI) printf("%d\n", dis);
        else puts("impossible");
    }

    return 0;
}
