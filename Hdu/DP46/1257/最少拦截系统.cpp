#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define Nre(c, a, b) for (int c = a; c > b; c--)
#define MAXN (30000)
#define INFI (0x7fffffff)
#define LL long long

int n, size, aco, S[MAXN];
int main()
{
    #if 1
        freopen("test.txt", "rt", stdin);
    #endif

    int h, j;

    while (~scanf("%d", &n))
    {
        aco = 0;
        Rep(i, 0, n)
        {
            scanf("%d", &h);
            for (j = 0; j < aco; j++)
                if (h <= S[j])
                {
                    S[j] = h;
                    break;
                }
            if (j == aco) S[aco++] = h;
        }
        #if 0
            printf("S:");
            Rep(i, 0, aco) printf(" %d", S[i]);
            puts("");
        #endif
        printf("%d\n", aco);
    }

    return 0;
}
