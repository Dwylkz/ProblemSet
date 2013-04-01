#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define MAXN (200)
#define INFI (0x7fffffff)

struct Cid
{
    int x, y;
} S[MAXN];

int n, a;

int main()
{
    #if 1
        freopen("test.txt", "rt", stdin);
    #endif
    int T, mini;

    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        mini = INFI;
        Rep(i, 0, n)
        {
            scanf("%d%d", &S[i].x, &S[i].y);
            Rep(j, 0, i)
                mini = min(mini, abs(S[i].x - S[j].x) + abs(S[i].y - S[j].y));
        }
        printf("%d\n", mini);
    }
    return 0;
}
