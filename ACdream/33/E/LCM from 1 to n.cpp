#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
#define LL long long
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define Nre(c, a, b) for (int c = a; c < b; c++)
#define MAXN (100000001)
#define MAXM (10001)
#define MOD (0x100000000LL)

int bp[MAXN / 32 + 2], lp, p[5800000], s[MAXM], r[MAXM], ans[MAXM];
//vector<int> p;

void Sieve()
{
    LL i, j;
    //p.push_back(2);
    lp = 0;
    p[lp++] = 2;
    for (j = 4; j < MAXN; j += 2)
        bp[j >> 5] |= (1 << (j & 31));
    for (i = 3; i < MAXN; i += 2)
        if (!(bp[i >> 5] & (1 << (i & 31))))
        {
            p[lp++] = i;
            //p.push_back(i);
            for (j = i * i; j < MAXN; j += i)
                bp[j >> 5] |= (1 << (j & 31));
        }
    #if 1
        printf("size = %d\n", lp);
    #endif
}

bool cmp(int a, int b)
{
    return s[a] < s[b];
}

LL n;

int main()
{
    #if 1
        freopen("test.txt", "rt", stdin);
    #endif

    int T;
    LL lcm;

    Sieve();
    scanf("%d", &T);
    #if 0
        printf("  MOD = %lld\n", MOD);
    #endif

    Rep(i, 0, T)
    {
        scanf("%d", s + i);
        r[i] = i;
    }
    sort(r, r + T, cmp);

    return 0;
}
