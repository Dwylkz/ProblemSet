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
#define MAXN (6)
#define MAXH (4 << 10)
#define INFI (0x7fffffff)
#define LM(x, y) ((x) << ((y) << 1))
#define RM(x, y) ((x) >> ((y) << 1))
#define NB(x, y) (~LM(x, y))
#define GB(x, y) (RM(x, y) & 3)
#define SB(x, y, z) ((x) | RM(z, y))
#define CB(x, y) ((x) & NB(3, y))

int n, mov[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
char M[MAXN][MAXN];

struct Node
{
    int s, a, d;
    Node(int ts = 0, int ta = 0, int td = 0)
        : s(ts), a(ta), d(td) {}
};

int BFS(int s)
{
    int ans = 0;
    bool H[MAXH];
    static queue<Node> Q;

    memset(H, 0, sizeof H);
    Q.push(Node(s, 0));
    while (!Q.empty())
    {
        Node u = Q.front();
        Q.pop();
        if (!H[u.d])
        {
            ans++;
            H[u.d] = 1;
        }
        Rep(i, 0, 9) if (GB(s, i)) Rep(j, 0, 4)
        {
            int x = i / 3 + mov[j][0], y = i % 3 + mov[j][1],
                z = 3 * x + y,
                c = GB(u.s, z);
            if (0 <= x && x < 3 && 0 <= y && y < 3 && !c)
                Q.push(Node(CB(u.s, i), SB(u.a, c, u.d), u.d + 1));
        }
    }

    return ans;
}

int main()
{
#if 1
    freopen("test.txt", "rt", stdin);
#endif

    int Cas = 1, h;

    while (~scanf("%d", &n))
    {
        int s = 0;
        Rep(i, 0, 3)
        {
            scanf("%s", M[i]);
            Rep(j, 0, 3)
            {
                if (M[i][j] == '*') M[i][j] = 0;
                else if (M[i][j] == 'B') M[i][j] = 1;
                else M[i][j] = 2;
                s = SB(s, M[i][j], i * 3 + j);
            }
        }
        printf("Case %d: %d\n", Cas++, BFS(s));
    }

    return 0;
}
