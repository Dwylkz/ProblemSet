#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <map>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define Nre(c, a, b) for (int c = a; c > b; c--)
#define MAXR (25)
#define MAXC (3500)
#define MAXX (MAXC * 10)
#define INFI (0x7fffffff)
typedef long long LL;

int SG[MAXR][MAXC], mov[3][2] = {{0, -1}, {-1, 0}, {-1, -1}}, RS[MAXR];

void Gen_SG()
{
    bool mex[MAXX];

    Rep(i, 0, MAXR) Rep(j, 0, MAXC)
    {
        memset(mex, 0, sizeof mex);
        Rep(k, 0, 3)
        {
            int maxl = max(i, j);
            Rep(l, 1, maxl + 1)
            {
                int x = i + l * mov[k][0], y = j + l * mov[k][1];
                if (0 <= x && x < MAXR && 0 <= y && y < MAXC)
                    mex[SG[x][y]] = 1;
            }
        }
        Rep(k, 0, MAXX) if (!mex[k])
        {
            SG[i][j] = k;
            break;
        }
    }
    Rep(i, 0, MAXR)
    {
        RS[i] = -1;
        Nre(j, MAXC - 2, -1)
        {
            bool isl = 1;
            int now = MAXC - 1, k = j, det = MAXC - 1 - j, s = j - det * 10;
            if (i > 17) s = j - det;
            Rep(k, s, j + 1) if (SG[i][k + det] != SG[i][k] + det)
            {
                isl = 0;
                break;
            }
            if (isl)
            {
                RS[i] = j;
                break;
            }
        }
    }
    #if 0
        #if 0
            freopen("SG.out", "wt", stdout);
            Rep(i, 0, MAXC)
            {
                Rep(j, 0, MAXR)
                    printf(" %4d", SG[j][i]);
                puts("");
            }
        #endif
        freopen("test.out", "wt", stdout);
        Rep(i, 0, MAXR)
        {
            int k = 0;
            printf(" %4d : RS = %4d CL = %4d\n", i, RS[i], MAXC - 1 - RS[i]);
            Rep(j, RS[i] + 1, MAXC)
            {
                if (k && k % 18 == 0)
                    puts("");
                printf(" %4d", SG[i][j] - SG[i][j - 1]);
                k++;
            }
            puts("\n");
        }
    #endif
}

int main()
{
    #if 1
        freopen("test.txt", "rt", stdin);
    #endif

    int T, R, N, x;
    LL C, y, sg, sgs;

    Gen_SG();
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%lld%d", &R, &C, &N);
        sgs = 0;
        while (N--)
        {
            scanf("%d%lld", &x, &y);
            x--; y--;
            if (y < MAXC) sg = SG[x][y];
            else
            {
                LL l = MAXC - 1 - RS[x], s = MAXC + (y - MAXC) % l - l;
                sg =  y - s + SG[x][s];
            }
            sgs ^= sg;
        }
        puts(sgs? "YES": "NO");
    }

    return 0;
}
