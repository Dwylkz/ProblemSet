#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define Clr(c, a, b) fill(c, c + a, b)
#define MAXN (7007)
#define INF (0x7fffffff)

char A[MAXN], B[MAXN];

int GCD(int a, int b)
{
    return b? GCD(b, a % b): a;
}

int main()
{
    #if 1
        freopen("test.txt", "rt", stdin);
    #endif

    int ts, sa, la, lb;

    while (scanf("%s", A), strcmp(A, "-1"))
    {
        sa = 0;
        scanf("%s", B);
        la = strlen(A);
        lb = strlen(B);
        Rep(i, 0, la)
        {
            ts = 0;
            Rep(j, 0, la)
                if (j + i < lb && A[j] == B[j + i])
                    ts++;
            if (ts > sa) sa = ts;
        }
        Rep(i, 0, lb)
        {
            ts = 0;
            Rep(j, 0, lb)
                if (j + i < la && B[j] == A[j + i])
                    ts++;
            if (ts > sa) sa = ts;
        }
        ts = sa * 2;
        sa = la + lb;
        la = GCD(ts, sa);
        ts /= la;
        sa /= la;
        printf("appx(%s,%s) = %d", A, B, ts);
        if (!(ts == sa || !ts)) printf("/%d", sa);
        putchar('\n');
    }

    return 0;
}
