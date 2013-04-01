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

    int Cas = 1, n0, n1, n2, n3, n4;
    while(scanf("%d", &n0), n0)
    {
        n1 = 3 * n0;
        n2 = (n1 + (n1 & 1)) >> 1;
        n3 = 3 * n2;
        n4 = n3 / 9;
        n4 = n3 / 9;
    }
    return 0;
}
