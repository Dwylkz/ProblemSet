#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <map>
#include <vector>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define Nre(c, a, b) for (int c = a; c > b; c--)
#define Clr(c, a, b) fill(c, c + a, b)
#define MS(c, a) memset(c, a, sizeof(c))
#define LLU long long
#define MAXN (11000)
#define MAXT (4400)
#define INFI 0x7fffffff
#define SHIFT (0)

map<int, int> H;
int n, t[MAXN];

int main()
{
#if 1
    freopen("test.txt", "rt", stdin);
#endif

    int T, x, y, maxs, tsu;

    scanf("%d", &T);
    Rep(C, 0, T)
    {
        H.clear();
        scanf("%d", &n);
        Rep(i, 0, n)
        {
            scanf("%d%d", &x, &y);
            if (!H[x]) H[x] = y;
            else H[x] += y;
            t[i] = x;
        }
        maxs = 0;
        Rep(i, 0, n)
        {
            tsu = 0;
            for (int node = t[i]; node; node >>= 1)
                tsu += H[node];
            maxs = max(maxs, tsu);
        }
        printf("Case %d: %d\n", C + 1, maxs);
    }

    return 0;
}
