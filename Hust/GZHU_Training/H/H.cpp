#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define Nre(c, a, b) for (int c = a; c > b; c--)
#define MAXN (5500)

int main()
{
    #if 1
        freopen("test.txt", "rt", stdin);
    #endif

    int T;

    scanf("%d", &T);
    while (T--)
    {
        int a, b, x, y;
        scanf("%d%d%d%d", &a, &b, &x, &y);
        if ((x <= a && y <= b) || (x <= b && y <= a))
            puts("Escape is possible.");
        else puts("Box cannot be dropped.");
    }

    return 0;
}
