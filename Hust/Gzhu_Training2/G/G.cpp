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
#define Rep(c, a, b) for (LL c = (a); c < (b); c++)
#define Nre(c, a, b) for (int c = (a); c > (b); c--)
#define MAXN ()
typedef long long LL;

LL m, n;

LL C(LL n, LL m)
{
	LL res = 1;
	for (LL i = 1; i <= m; i++)
		res = res * (n - i + 1) / i;
	return res;
}

int main()
{
#if 1
	freopen("test.txt", "rt", stdin);
#endif
	while (scanf("%lld%lld", &n, &m), n || m)
	{
		printf("%lld\n", C(n + m, min(n, m)));
	}
	return 0;
}
