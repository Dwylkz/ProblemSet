#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define MAXN (2000)
#define X2(x) (x * x)

int n, c[MAXN];;

int main()
{
    #if 1
        freopen("test.txt", "rt", stdin);
    #endif

    int n;

    while (scanf("%d", &n), n){
        bool pos = 1;
        Rep(i, 0, n) scanf("%d", c + i);
        sort(c, c + n);
        Rep(i, 1, n) if (c[i] - c[i - 1] > 200) pos = 0;
        if (1422 - c[n - 1] > 100) pos = 0;
        puts(pos? "POSSIBLE": "IMPOSSIBLE");
    }
    return 0;
}
