#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define MAXV (52)
#define INFI (0x7fffffff)

int n;

int main()
{
    #if 1
        freopen("test.txt", "rt", stdin);
    #endif

    int Cas, r1, c1, r2, c2;

    scanf("%d", &Cas);
    Rep(CCa, 1, Cas + 1)
    {
        scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
        printf("Case %d: ", CCa);
        if ((r1 & 1) ^ (c1 & 1) ^ (r2 & 1) ^ (c2 & 1)) puts("impossible");
        else if (abs(r1 - r2) == abs(c1 - c2)) puts("1");
        else puts("2");
    }

    return 0;
}
