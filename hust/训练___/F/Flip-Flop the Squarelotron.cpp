#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <map>
#include <cstring>
#include <string>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define Nre(c, a, b) for (int c = a; c > b; c--)
#define MAXN (101)
#define MAXC (88)

int ma[MAXN][MAXN], n;

void UD(int s, int l)
{
    Rep(i, 0, l / 2) Rep(j, 0, l)
        swap(ma[s + i][s + j], ma[s + l - i - 1][s + j]);
}

void LR(int s, int l)
{
    Rep(i, 0, l) Rep(j, 0, l / 2)
        swap(ma[s + i][s + j], ma[s + i][s + l - j - 1]);
}

void PD(int s, int l)
{
    Rep(i, 0, l) Rep(j, i, l)
        swap(ma[s + i][s + j], ma[s + j][s + i]);
}

void ID(int s, int l)
{
    Rep(i, 0, l) Rep(j, l - i - 1, l)
        swap(ma[s + i][s + j], ma[s + l - j - 1][s + l - i - 1]);
}

int main()
{
    #if 1
        freopen("test.txt", "rt", stdin);
    #endif
    int M, T, C, ri;

    scanf("%d", &M);
    while (M--)
    {
        scanf("%d", &n);
        Rep(i, 0, n) Rep(j, 0, n)
            scanf("%d", ma[i] + j);
        ri = (n & 1)? (n + 1) / 2: n / 2;
        #if 0
            printf(" ri = %d\n", ri);
        #endif
        Rep(i, 0, ri)
        {
            scanf("%d", &T);
            while (T--)
            {
                scanf("%d", &C);
                if (C < 2)
                {
                    UD(i, n - 2 * i);
                    if (i < ri - 1) UD(i + 1, n - 2 * (i + 1));
                }
                else if (C < 3)
                {
                    LR(i, n - 2 * i);
                    if (i < ri - 1) LR(i + 1, n - 2 * (i + 1));
                }
                else if (C < 4)
                {
                    PD(i, n - 2 * i);
                    if (i < ri - 1) PD(i + 1, n - 2 * (i + 1));
                }
                else
                {
                    ID(i, n - 2 * i);
                    if (i < ri - 1) ID(i + 1, n - 2 * (i + 1));
                }
            }
        }
        Rep(i, 0, n)
        {
            Rep(j, 0, n)
            {
                printf("%d", ma[i][j]);
                if (j < n - 1) putchar(' ');
            }
            puts("");
        }
    }

    return 0;
}
