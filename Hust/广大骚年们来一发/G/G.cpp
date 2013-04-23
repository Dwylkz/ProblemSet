#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define MAXN (22000)
#define MAXL (1000000000)

map<int, int> D, N;
map<int, int>::iterator beg;
bool S[MAXN];
int n, l[MAXN], r[MAXN];
char b[2], c[MAXN];

int main()
{
    #if 1
        freopen("test.txt", "rt", stdin);
    #endif

    int len, h, o, mh, mo, maxl, t, tmax;
    bool col;

    scanf("%d", &n);
    D[0] = D[1000000000] = 1;
    Rep(i, 0, n)
    {
        scanf("%d%d%1s", l + i, r + i, b);
        c[i] = b[0];
        D[l[i]] = D[r[i]] = 1;
    }
    for (len = 0, beg = D.begin(); beg != D.end(); beg++)
    {
        beg->second = len++;
        N[beg->second] = beg->first;
    }
    len <<= 1;
    Rep(i, 0, n)
    {
        col =  (c[i] == 'b'? 1: 0);
        h = (D[l[i]] << 1);
        o = (D[r[i]] << 1);
        #if 0
            printf("[%d, %d]\n", h, o);
        #endif
        Rep(j, h, o) S[j] = col;
    }
    mh = mo = maxl = col = t = 0;
    Rep(i, 0, len - 1)
        if (!S[i] && !col)
        {
            t = i;
            #if 0
                printf("t = %d\n", t);
            #endif
            col = 1;
        }
        else if ((i == len - 2 || S[i]) && col)
        {
            h = N[t >> 1];
            o = N[i >> 1];
            #if 0
                printf("[%d, %d) [%d, %d)\n", h, o, t,  i);
            #endif
            tmax = o - h + 1;
            if (t % 2 == 1) tmax--;
            if (i % 2 == 0) tmax--;
            if (tmax > maxl)
            {
                maxl = tmax;
                mh = h;
                mo = o;
                if (t % 2 == 1) mh++;
                if (i % 2 == 1) mo++;
            }
            col = 0;
        }
        printf("%d %d\n", mh, mo);
    #if 0
        printf("len = %d maxl = %d\n", len, maxl);
        Rep(i, 0, len)
            printf("%2d", S[i]);
        putchar('\n');
    #endif

    return 0;
}
