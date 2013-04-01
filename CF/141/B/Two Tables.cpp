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
//STL
#define MS(c, a) memset(c, a, sizeof c)
//Syntax
#define Rep(c, a, b) for (int c = (a); c < (b); c++)
#define Nre(c, a, b) for (int c = (a); c > (b); c--)
//DEBUG
#define FK puts("Fu*k here!")
//Type
typedef unsigned int UI;
typedef long long LL;
typedef long double LD;
//Constant
const LL INFL = ~0ull >> 1;
const int INFI = ~0u >> 1;
const int MAXN = 55;
const int MOD = 1000000007;
//Array
typedef int AI[MAXN];
typedef bool AB[MAXN];
typedef double AD[MAXN];
typedef LL ALL[MAXN];
typedef LD ALD[MAXN];

int na, ma, nb, mb;
AI a[MAXN], b[MAXN];
int main()
{
#if 0
	freopen("test.txt", "r", stdin);
	freopen("test.out", "w", stdout);
#endif
	while (~scanf("%d%d", &na, &ma))
	{
		char buf[MAXN];
		Rep(i, 0, na)
		{
			scanf("%s", buf);
			Rep(j, 0, ma) a[i][j] = buf[j] - '0';
		}
		scanf("%d%d", &nb, &mb);
		Rep(i, 0, nb)
		{
			scanf("%s", buf);
			Rep(j, 0, mb) b[i][j] = buf[j] - '0';
		}
		int mx = -INFI, _i = INFI, _j = INFI;
		Rep(i, -MAXN, MAXN) Rep(j, -MAXN, MAXN)
		{
			int sm = 0;
			Rep(x, 0, na) Rep(y, 0, ma)
				if (0 <= x + i && x + i < nb && 0 <= y + j && y + j < mb)
					sm += a[x][y] * b[x + i][y + j];
			if (sm > mx)
			{
				mx = sm;
				_i = i;
				_j = j;
			}
		}
		printf("%d %d\n", _i, _j);
	}
	return 0;
}
