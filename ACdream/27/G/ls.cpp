#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <cstring>
#include <string>
#include <memory.h>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define Clr(c, a) memset(c, a, sizeof c)
#define LLU long long
#define MAXN (110)
#define MOD (0x7fffffff)

char P[MAXN], buf[MAXN];
int n;

int main()
{
    #if 1
        freopen("test.txt", "rt", stdin);
    #endif

    int lp, lb;
    bool mat;

    while (~scanf("%s", P))
    {
        lp = strlen(P);
        scanf("%d", &n);
        while (n--)
        {
            mat = 0;
            scanf("%s", buf);
            lb = strlen(buf);
            int j, ti;
            Rep(i, 0, lb)
            {
                ti = i;
                j = 0;
                while (true)
                {
                    while (j < lp && P[j] == '*') j++;
                    while (i < lb && j < lp && buf[ti] != P[j]) ti++;
                    for (; ti < lb && j < lp && buf[ti] == P[j]; ti++, j++);
                    if (j == lp)
                    {
                        if (ti == lb) mat = 1;
                        else if (P[lp - 1] == '*') mat = 1;
                        break;
                    }
                    if (ti == lb) break;
                    if (P[j] != '*') break;
                }
                if (mat) break;
            }
            if (mat) puts(buf);
        }
    }

    return 0;
}
