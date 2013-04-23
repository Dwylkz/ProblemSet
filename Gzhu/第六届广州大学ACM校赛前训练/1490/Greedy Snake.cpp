#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define MAXN (12)
#define INFI (0x7fffffff)

int n, m, sx, sy, M[MAXN][MAXN], maxi;
int mov[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
bool vis[MAXN][MAXN];
vector<int> sta;

bool jud(int x, int y)
{
    return -1 < x && x < n && -1 < y && y < m && !vis[x][y] && M[x][y];
}

void DFS(int x, int y, int app)
{
    int tx, ty;

    if (M[x][y] == -2)
    {
        maxi = max(maxi, app + 2);
        #if 0
            Rep(i, 0, sta.size())
                printf("[%d, %d, %d]", sta[i] / 10 + 1, sta[i] % 10 + 1, M[sta[i] / 10][sta[i] % 10]);
            putchar('\n');
        #endif
        return ;
    }
    sta.push_back(x*10 + y);
    vis[x][y] = 1;
    Rep(i, 0, 4)
    {
        tx = x + mov[i][0];
        ty = y + mov[i][1];
        if (jud(tx, ty)) DFS(tx, ty, app + M[tx][ty]);
    }
    vis[x][y] = 0;
    sta.pop_back();
}

int main()
{
    #if 1
        freopen("test.txt", "rt", stdin);
    #endif
    int T;

    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &m);
        maxi = -1;
        Rep(i, 0, n) Rep(j, 0, m)
        {
            scanf("%d", M[i] + j);
            if (M[i][j] == -1)
            {
                sx = i;
                sy = j;
            }
        }
        #if 0
            Rep(i, 0, n)
            {
                Rep(j, 0, m)
                    printf("%4d", M[i][j]);
                putchar('\n');
            }
        #endif
        sta.clear();
        DFS(sx, sy, 0);
        printf("%d\n", maxi);
    }
    return 0;
}
