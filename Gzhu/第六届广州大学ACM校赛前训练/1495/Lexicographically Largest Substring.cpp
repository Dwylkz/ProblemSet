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

int n, m, l, maxi;
char C[MAXN];

int main()
{
    #if 1
        freopen("test.txt", "rt", stdin);
    #endif
    int T, tmax, tl;
    string mc, tm;

    scanf("%d", &T);
    while (T--)
    {
        mc = "";
        scanf("%s", C);
        l = strlen(C);
        Rep(i, 0, l) Rep(j, i + 1, l + 1)
        {
            tm = "";
            Rep(k, i, j) tm += C[k];
            if (tm > mc) mc = tm;
        }
        printf("%s\n", mc.c_str());
    }
    return 0;
}
