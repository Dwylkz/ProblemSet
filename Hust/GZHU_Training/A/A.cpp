#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define Nre(c, a, b) for (int c = a; c > b; c--)
#define MAXN (1100)
#define INFI (0x7fffffff)
typedef long long LL;

int p[MAXN], l;
LL b[MAXN];

void SV()
{
    p[l = 0] = 1;
    b[l++] = 1;
    p[l] = 2;
    b[l++] = 2;
    Rep(i, 3, 90)
    {
        bool isp = 1;
        Rep(j, 2, i) if (i % j == 0) isp = 0;
        if (isp)
        {
            p[l]=  i;
            b[l] = b[l - 1] * i;
            l++;
        }
        if (b[l - 1] > 0x7fffffff) break;
    }
    l--;
    #if 0
        Rep(i, 0, l) printf(" %4d", p[i]);
        puts("");
        Rep(i, 0, l) printf(" %4lld", b[i]);
        puts("");
    #endif
}

void DFS(int n, int i)
{
    if (i < 0) return ;
    DFS(n % b[i], i - 1);
    if (n / b[i])
    {
        if (n % b[i]) printf(" +");
        printf(" %lld", n / b[i]);
        Rep(j, 1, i + 1) printf("*%d", p[j]);
    }
}

int main()
{
    #if 1
        freopen("test.txt", "rt", stdin);
    #endif

    int n;

    SV();
    while (scanf("%d", &n), n)
    {
        printf("%d =", n);
        DFS(n, l - 1);
        puts("");
    }

    return 0;
}

