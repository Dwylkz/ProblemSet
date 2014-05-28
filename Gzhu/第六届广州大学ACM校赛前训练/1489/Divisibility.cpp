#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <vector>
#include <cstring>
#include <string>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define MAXN (200)
#define INFI (0x7fffffff)

int n, x, y;

int GCD(int a, int b)
{
    return b? GCd(b, a % b): a;
}

int main()
{
    #if 1
        freopen("test.txt", "rt", stdin);
    #endif
    int T;

    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
    }
    return 0;
}
