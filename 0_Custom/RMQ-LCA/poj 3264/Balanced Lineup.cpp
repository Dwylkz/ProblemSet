#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define Clr(c, a, b) fill(c, c + a, b)
#define MS(c, a) memset(c, a, sizeof(c))
#define MAXN (55000)
#define MAXT (4400)
#define INFI (512)

struct minST
{
    int t[20][MAXN];

    int low(int x)
    {
        int c = 0;
        while ((1 << c) <= x) c++;
        return c;
    }

    void ini(int *S, int len)
    {
        int tp, l = low(len);

        Rep(i, 0, len) t[0][i] = S[i];
        Rep(i, 1, l) Rep(j, 0, len)
        {
            tp = (1 << i >> 1);
            if (j + tp < len)
                t[i][j] = min(t[i - 1][j], t[i - 1][j + tp]);
        }
        #if 0
            Rep(i, 0, l)
            {
                Rep(j, 0, len)
                    printf(" %d", t[i][j]);
                puts("");
            }
            puts("");
        #endif
    }

    int que(int l, int r)
    {
        int j, tp;

        if (l > r) swap(l, r);
        j = low(r - l + 1) - 1;
        tp = (1 << j);
        return min(t[j][l], t[j][r - tp + 1]);
    }
} minst;

struct maxST
{
    int t[20][MAXN];

    int low(int x)
    {
        int c = 0;
        while ((1 << c) <= x) c++;
        return c;
    }

    void ini(int *S, int len)
    {
        int tp, l = low(len);

        Rep(i, 0, len) t[0][i] = S[i];
        Rep(i, 1, l) Rep(j, 0, len)
        {
            tp = (1 << i >> 1);
            if (j + tp < len)
                t[i][j] = max(t[i - 1][j], t[i - 1][j + tp]);
        }
        #if 0
            Rep(i, 0, l)
            {
                Rep(j, 0, len)
                    printf(" %d", t[i][j]);
                puts("");
            }
        #endif
    }

    int que(int l, int r)
    {
        int j, tp;

        if (l > r) swap(l, r);
        j = low(r - l + 1) - 1;
        tp = (1 << j);
        return max(t[j][l], t[j][r - tp + 1]);
    }
} maxst;

int n, q, C[MAXN];

int main()
{
    #if 1
        freopen("test.txt", "rt", stdin);
    #endif

    int l, r;

    scanf("%d%d", &n, &q);
    Rep(i, 0, n) scanf("%d", C + i);
    #if 0
        Rep(i, 0, n)
            printf(" %d", C[i]);
        puts("");
    #endif
    minst.ini(C, n);
    maxst.ini(C, n);
    while (q--)
    {
        scanf("%d%d", &l, &r);
        l--; r--;
        #if 0
            printf("%d - %d\n", maxst.que(l, r), minst.que(l, r));
        #endif
        printf("%d\n", maxst.que(l, r) - minst.que(l, r));
    }

    return 0;
}
