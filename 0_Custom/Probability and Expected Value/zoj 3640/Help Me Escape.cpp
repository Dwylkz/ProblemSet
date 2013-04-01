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
#define FL(c, a ,b) fill(c, c + a, b)
#define MS(c, a) memset(c, a, sizeof c)
#define Rep(c, a, b) for (int c = (a); c < (b); c++)
#define Nre(c, a, b) for (int c = (a); c > (b); c--)
#define MAXN (22000)
typedef long long LL;
typedef int AI[MAXN];
typedef double AD[MAXN];
typedef LL AL[MAXN];

int n, f, dp[2][MAXN];
AI ci, ti;
double ex;

int main()
{
#if 1
	freopen("test.txt", "rt", stdin);
#endif
	while (~scanf("%d%d", &n, &f))
	{
		//Initialize
		int sc = f, cm = 0;
		Rep(i, 0, n)
		{
			scanf("%d", ci + i);
			ti[i] = (1.0 + sqrt(5.0)) / 2.0 * ci[i] * ci[i];
			cm = max(cm, ci[i]);
		}
		//Solve
		cm <<= 1;
		ex = 0;
		int t = 1, dep = 0;
		double mol = 1.0 /  n;
		MS(dp, 0);
		Rep(i, f, cm + 1) dp[0][i] = 1;
		while (dp[!t][cm])
		{
			sc = cm;
			MS(dp[t], 0);
			Rep(i, 0, n)
			{
				ex += (dep + ti[i]) * mol * (dp[!t][cm] - dp[!t][ci[i]]);
				Rep(j, f, ci[i] + 1)
				{
					dp[t][j + ci[i]] += dp[!t][j] - dp[!t][j - 1];
					sc = min(sc, j + ci[i]);
				}
			}
			Rep(i, sc, cm + 1) dp[t][i] += dp[t][i - 1];
			dep++;
			t ^= 1;
			mol /= n;
		}
		printf("%.3lf\n", ex);
	}
	return 0;
}
