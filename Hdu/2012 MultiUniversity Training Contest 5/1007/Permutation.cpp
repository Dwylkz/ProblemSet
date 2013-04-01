#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define MAXN (13)
typedef long long LL;

int GCD(int a, int b)
{
    return b? GCD(b, a % b): a;
}

int LCM(int a, int b)
{
    return a / GCD(a, b) * b;
}

int ar[MAXN];

int FR(int u)
{
    int lp = 1, x = u;
    //printf("fuck %d\n", u);
    while (ar[x] != u)
    {
        //puts("fuck");
        x = ar[x];
        lp++;
    }
    return lp;
}

void fuck()
{
    Rep(i, 1, MAXN)
    {
        int k = 0;
        bool hash[10000] = {0};
        memset(hash, 0, sizeof hash);
        Rep(j, 1, i + 1) ar[j] = j;
        do
        {
            int lcm = 1;
            bool yes = 1;
            #if 0
                printf("n = %d:\n", i);
                Rep(j, 1, i + 1) printf(" %d", ar[j]);
                puts("");
            #endif
            Rep(j, 1, i + 1) if (ar[j] == j)
            {
                yes = 0;
                break;
            }
            //if (yes)
            {
                Rep(j, 1, i + 1) lcm = LCM(lcm, FR(j));
                if (!hash[lcm])
                {
                    k++;
                    hash[lcm] = 1;
                }
            }
        } while (next_permutation(ar + 1, ar + i + 1));
        //Rep(j, 1 , i + i) printf(" %d", hash[j]);
        puts("");
        printf("%d %d\n", i, k);
    }
}

int main()
{
#if 1
	freopen("test.txt", "rt", stdin);
#endif
	int n;

    fuck();
	while (~scanf("%d", &n))
	{
	}
	return 0;
}
