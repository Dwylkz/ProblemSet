#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define Nre(c, a, b) for (int c = a; c > b; c--)
#define MAXN (2200)
#define INFI (0x7fffffff)

int main()
{
    #if 1
        freopen("test.txt", "rt", stdin);
    #endif

    int Cas = 1;
    static char b[MAXN];
    while(scanf("%s", b), b[0] != '-')
    {
        int mo = INFI, op = 0, lb = 0, len = strlen(b);
        Rep(i, 0, len)
            if (b[i] == '{') lb++;
            else if (!lb) op++, lb++;
            else lb--;
        op += lb >> 1;
        mo = min(mo, op);
        op = lb = 0;
        Nre(i, len - 1, -1)
            if (b[i] == '}') lb++;
            else if (!lb) op++, lb++;
            else lb--;
        op += lb >> 1;
        mo = min(mo, op);
        printf("%d. %d\n", Cas++, mo);
    }
    return 0;
}
