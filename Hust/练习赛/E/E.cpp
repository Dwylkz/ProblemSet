#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <queue>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
typedef long long LL;

struct BT
{
    int nb, md, ne;
    friend bool operator < (BT p, BT q)
    {
        if (p.nb != q.nb) return p.nb > q.nb;
        if (p.md != q.md) return p.md > q.md;
        return p.ne > q.ne;
    }
};

int main()
{
    #if 1
        freopen("test.txt", "rt", stdin);
    #endif

    int T, n, m, Cas = 1;

    while (~scanf("%d%d", &n, &m))
    {
        priority_queue<BT> Q;
        Rep(i, 1, m + 1)
        {
            BT tb = {0, abs(m + 1 - 2 * i), i};
            Q.push(tb);
        }
        Rep(i, 0, n)
        {
            BT tb = Q.top();
            Q.pop();
            printf("%d\n", tb.ne);
            tb.nb++;
            Q.push(tb);
        }
    }

    return 0;
}
