#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define Nre(c, a, b) for (int c = a; c > b; c--)
#define MAXN (32)
#define getb(x, y) (x & y)
#define setb(x, y) (x |= y)
#define clrb(x, y) (x &= (~y))

unsigned int b[MAXN];

int main()
{
    #if 1
        freopen("test.txt", "rt", stdin);
    #endif

    unsigned int n, m, l, u;

    Rep(i, 0, MAXN) b[i] = (1 << (MAXN - i - 1));
    #if 0
        Rep(i, 0, MAXN) printf(" %u", b[i]);
        puts("");
    #endif
    while (~scanf("%u%u%u", &n, &l, &u))
    {
        m = ~n;
        while (m < l || m > u)
        {
            Rep(i, 0, MAXN)
            if (getb(u, b[i]) > getb(m, b[i]))
                break;
            else if (getb(u, b[i]) < getb(m, b[i]))
                clrb(m, b[i]);
            Rep(i, 0, MAXN)
                if (getb(l, b[i]) < getb(m, b[i]))
                    break;
                else if (getb(l, b[i]) > getb(m, b[i]))
                    setb(m, b[i]);
        }
        printf("%u\n", m);
    }

    return 0;
}
