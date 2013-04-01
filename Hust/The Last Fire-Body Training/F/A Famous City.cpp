#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define MAXN ()
#define MAXP ()
#define INFI (0x7fffffff)

int n;
vector<int> S;

int main()
{
#if 1
    freopen("test.txt", "rt", stdin);
#endif

    int Cas = 1, h, tb;

    while (~scanf("%d", &n))
    {
        tb = 0;
        S.clear();
        while (n--)
        {
            scanf("%d", &h);
            while (S.size() && S[S.size() - 1] >= h)
            {
                if (S[S.size() - 1] != h) tb++;
                S.pop_back();
            }
            if (h) S.push_back(h);
        }
        tb += unique(S.begin(), S.end()) - S.begin();
        printf("Case %d: %d\n", Cas++, tb);
    }

    return 0;
}
