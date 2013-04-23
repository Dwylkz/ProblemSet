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
#define MS(c, a) memset(c, a, sizeof c)
#define Rep(c, a, b) for (int c = (a); c < (b); c++)
#define Nre(c, a, b) for (int c = (a); c > (b); c--)
#define MAXN (1010)
typedef double MT;
typedef MT AD[MAXN];

int N, M, I, J;
AD a, b, c, x, d;

void TDMA(int n, AD a, AD b, AD c, AD x, AD d)
{
	Rep(i, 1, n)
	{
		double tp = a[i] / b[i - 1];
		b[i] -= tp * c[i - 1];
		d[i] -= tp * d[i - 1];
	}
	x[n - 1] = d[n - 1] / b[n - 1];
	Nre(i, n - 2, -1) x[i] = (d[i] - c[i] * x[i + 1]) / b[i];
}

int main()
{
#if 1
	freopen("test.txt", "rt", stdin);
#endif
	while (~scanf("%d%d", &N, &M))
	{
		scanf("%d%d", &I, &J);
		MS(a, 0);
		MS(b, 0);
		MS(c, 0);
		MS(x, 0);
		MS(d, 0);
		Nre(i, N - 1, I - 1)
		{
			Rep(j, 0, M)
			{
				double tp = 2 + bool(j) + bool(j < M - 1);
				b[j] = 1 - 1 / tp;
				if (j) a[j] = -1 / tp;
				if (j < M - 1) c[j] = -1 / tp;
				d[j] = x[j] / tp + 1;
			}
			TDMA(M, a, b, c, x, d);
		}
		printf("%lf\n", x[J - 1]);
	}
	return 0;
}
