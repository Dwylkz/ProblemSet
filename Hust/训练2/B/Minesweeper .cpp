#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define MAXN (200)

int n, m, C[MAXN][MAXN];
char B[MAXN][MAXN];
int mov[8][2] = {0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1, -1, 0, -1, 1};

bool chk(int x, int y)
{
    return -1 < x && x < n && -1 < y && y < m && C[x][y] > -1;
}

int main()
{
    #if 1
        freopen("test.txt", "rt", stdin);
    #endif
    int F = 1;

    while (scanf("%d%d", &n, &m))
    {
        if (F > 1 && (n || m)) putchar('\n');
        if (!(n || m)) break;
        Rep(i, 0, n)
        {
            scanf("%s", B[i]);
            Rep(j, 0, m)
                if (B[i][j] == '*')
                    C[i][j] = -1;
                else C[i][j] = 0;
        }
        Rep(x, 0, n) Rep(y, 0, m)
            if (C[x][y] < 0) Rep(i, 0, 8)
                if (chk(x + mov[i][0], y + mov[i][1]))
                    C[x + mov[i][0]][y + mov[i][1]]++;
        printf("Field #%d:\n", F++);
        Rep(i, 0, n)
        {
            Rep(j, 0, m)
                if (C[i][j] < 0)
                    printf("*");
                else printf("%d", C[i][j]);
            putchar('\n');
        }
    }

    return 0;
}
