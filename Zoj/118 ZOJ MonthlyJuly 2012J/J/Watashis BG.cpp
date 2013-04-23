#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define Nre(c, a, b) for (int c = a; c > b; c--)
#define MAXN (66)
#define INFI (10000001)

int N, M, w[MAXN];
bool dp[INFI];

int main()
{
    #if 1
        freopen("test.txt", "rt", stdin);
    #endif

    while (~scanf("%d%d", &N, &M))
    {
        int tsu = 0;
        Rep(i, 0, N)
        {
            scanf("%d", w + i);
            tsu += w[i];
        }
        if (tsu <= M)
        {
            printf("%d\n", tsu);
            continue;
        }
        sort(w, w + N);
        memset(dp, 0, sizeof dp);
        dp[0] = 1;
        Rep(i, 0, N) if (w[i] <= M)
        {
            bool f = 0;
            Nre(j, M, -1) if(dp[j] && j + w[i] <= M)
            {
                dp[j + w[i]] = 1;
                if (j + w[i] == M)
                {
                    f = 1;
                    break;
                }
            }
            if (f) break;
        }
        int mw = 0;
        Nre(i, M, -1) if (dp[i])
        {
            mw = i;
            break;
        }
        printf("%d\n", mw);
    }

    return 0;
}
