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
using namespace std;
#define Rep(c, a, b) for (int c = (a); c < (b); c++)
#define Nre(c, a, b) for (int c = (a); c > (b); c--)
#define MAXN (52)
#define INFI (0x7fffffff)

struct Pre
{
	int i, j, k;
	Pre(int _i = 0, int _j = 0, int _k = 0)
		: i(_i), j(_j), k(_k)
	{}
} ps[MAXN][MAXN][MAXN];

int K;
double f[MAXN], dp[MAXN][MAXN][MAXN];

int main()
{
#if 1
	freopen("test.txt", "rt", stdin);
#endif
	int T;
	scanf("%d", &T);
	Rep(Cas, 1, T + 1)
	{
		scanf("%d", &K);
		double sf = 0;
		Rep(i, 1, 27)
		{
			Rep(j, 0, MAXN) Rep(k, 0, MAXN) dp[i][j][k] = INFI;
			Rep(j, 0, MAXN) Rep(k, 0, MAXN) ps[i][j][k] = Pre(0, 0, 0);
			scanf("%lf", f + i);
			sf += f[i];
		}
		dp[1][1][1] = f[1];
		Rep(i, 2, 27) Rep(j, 1, K + 1) Rep(k, 1, 9) 
		{
			if (j < K && dp[i - 1][j][k] < dp[i][j + 1][1] - f[i])
			{
				dp[i][j + 1][1] = dp[i - 1][j][k] + f[i];
				ps[i][j + 1][1] = Pre(i - 1, j, k);
			}
			if (k < 8 && dp[i - 1][j][k] < dp[i][j][k + 1] - (k + 1) * f[i])
			{
				dp[i][j][k + 1] = dp[i - 1][j][k] + (k + 1) * f[i];
				ps[i][j][k + 1] = Pre(i - 1, j, k);
			}
		}
		int mj = 1, mk = 1;
		Rep(j, 4, K + 1) Rep(k, 1, 9)
			if (dp[26][j][k] < dp[26][mj][mk])
			{
				mj = j;
				mk = k;
			}
		int hash[MAXN];
		Pre nw(26, mj, mk);
		double ts = 0;
		while (nw.i && nw.j && nw.k)
		{
			hash[nw.i] = nw.j;
			ts += f[nw.i] * nw.k;
			nw = ps[nw.i][nw.j][nw.k];
		}
		printf("%d %.3lf ", Cas, ts / sf);
		for (int i = 1; i < 27;)
		{
			if (i > 1) putchar(' ');
			putchar('A' - 1 + i);
			for (i++; i < 27 && hash[i] == hash[i - 1]; i++) putchar('A' + i - 1);
		}
		puts("");
	}
	return 0;
}
