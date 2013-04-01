//Header
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cctype>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;
//Macro
//STL-Alias
#define UN(c, a) unique(c, a)
#define MS(c, a) memset(c, a, sizeof c)
#define FLC(c, a ,b) fill(c, c + a, b)
#define LOS(c, a, b) lower_bound(c, a, b)
#define UPS(c, a, b) upper_bound(c, a, b)
//Syntax-Alias
#define Rep(c, a, b) for (int c = (a); c < (b); c++)
#define Nre(c, a, b) for (int c = (a); c > (b); c--)
//DEBUG
#define FK puts("Fu*k here!")
#define PA(s, c, a, b, p, f){\
    printf(s);\
    Rep(c, a, b) printf(p, (f));\
    puts("");}
//Constant
#define INFL (0x7fffffffffffffffLL)
#define INFI (0x7fffffff)
#define BASE (150001LL)
#define MOD (13131)
#define MAXN (15)
//Type-Alias
typedef long long LL;
typedef long double LD;
typedef int AI[MAXN];
typedef bool AB[MAXN];
typedef double AD[MAXN];
typedef LL ALL[MAXN];
typedef LD ALD[MAXN];
//BOP
#define LM(x, y) ((x) << (y))
#define RM(x, y) ((x) >> (y))
#define BITW (1)
#define BMOD (LM(1, BITW) - 1)
#define GB(x, y)\
    (RM(x, y * BITW) & BMOD)
#define CB(x, y)\
    (x & ~LM(BMOD, y * BITW))
#define SBW(x, y, z)\
    (x | LM(y, z * BITW))
#define SBI(x, a, b)\
    ((LM(BMOD, b * BITW) - LM(BMOD, a * BITW)) | x)
#define CBI(x, a, b)\
    (~(LM(BMOD, b * BITW) - LM(BMOD, a * BITW)) & x)

int n, E[MAXN], S[1 << MAXN], se;

LL EC(int a, int b)
{
    return b + BASE * a;
}
map<LL, bool> H;

void DFS(int n, int a, int b, int c)
{
    if (a >= se - a) return ;
    if (!n)
    {
        if (!a || !b || !c) return ;
        if (a >= b && b >= c) H[EC(a, b)]= 1;
        return ;
    }
    int _n = n - 1, e = E[n - 1];
    DFS(_n, a + e, b, c);
    DFS(_n, a, b + e, c);
    DFS(_n, a, b, c + e);
}

int main()
{
#if 1
    freopen("test.txt", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    int T;
    scanf("%d", &T);
    while (T--)
    {
        //Initialize
        scanf("%d", &n);
        se = 0;
        Rep(i, 0, n)
        {
            scanf("%d", E + i);
            se += E[i];
        }
        //Solve
        H.clear();
        DFS(n, 0, 0, 0);
        printf("%d\n", H.size());
    }
    return 0;
}
