#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cctype>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define MAXN (16)

char B[MAXN][MAXN];
int mov[16][2] = {{0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1},
                  {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}};
int cmo[6][9] = {{2, 1, 3}, {2, 5, 7}, {4, 0, 2, 4, 6}, {4, 1, 3, 5, 7},
                 {8, 0, 1, 2, 3, 4, 5, 6, 7}, {8, 8, 9, 10, 11, 12, 13, 14, 15}};

bool chk(int x, int y)
{
    return -1 < x && x < 8 && -1 < y && y < 8;
}

int sea(int x, int y)
{
    #if 0
        printf(" in [%d, %d]\n", x, y);
    #endif
    char che = B[x][y];
    bool bw = isupper(B[x][y]);
    int id, mo = 0, tx, ty;

    if (!bw) che -= 32;
    if (che == 'R') id = 2;
    else if (che == 'B') id = 3;
    else if (che == 'Q') id = 4;
    else
    {
        mo = 1;
        if (che == 'P') id = bw;
        else if (che == 'K')id = 4;
        else id = 5;
    }
    #if 0
        printf(" bw = %d che = %c id = %d\n", bw, che, id);
    #endif
    Rep(i, 1, 8)
    {
        Rep(j, 1, cmo[id][0] + 1)
        {
            tx = x + i * mov[cmo[id][j]][0];
            ty = y + i * mov[cmo[id][j]][1];
            if (chk(tx, ty))
            {
                #if 0
                    printf("  to [%d, %d]: %c\n", tx, ty, B[tx][ty]);
                #endif
                if (bw && B[tx][ty] == 'k')
                    return 1;
                else if (!bw && B[tx][ty] == 'K')
                    return 2;
            }
        }
        if (mo) break;
    }

    return 0;
}

int main()
{
    #if 1
        freopen("test.txt", "rt", stdin);
    #endif
    int C = 1, kic;
    bool emb;

    while (1)
    {
        emb = 1;
        kic = 0;
        Rep(i, 0, 8)
        {
            scanf("%s", B[i]);
            Rep(j, 0, 8) if (B[i][j] != '.')
                emb = 0;
        }
        if (emb) break;
        Rep(i, 0, 8)
        {
            Rep(j, 0, 8)
            {
                if (B[i][j] != '.')
                    kic = sea(i, j);
                #if 0
                    printf("  [%d, %d] here = %c\n", i, j, B[i][j]);
                #endif
                if (kic) break;
            }
            if (kic) break;
        }
        printf("Game #%d: ", C++);
        if (kic == 2) puts("white king is in check.");
        else if (kic == 1) puts("black king is in check.");
        else puts("no king is in check.");
    }

    return 0;
}
