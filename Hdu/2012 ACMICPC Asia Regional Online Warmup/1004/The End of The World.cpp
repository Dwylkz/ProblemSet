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
#define MAXN (128)
typedef long long LL; 

char H[MAXN];

LL DFS(int n, int t)
{
	LL res = 0;
	for (;n >= 0; n--) if (H[n] != t)
	{
		bool ha[3] = {0};
		int _t;
		ha[t] = ha[H[n]] = 1;
		Rep(i, 0, 3) if (!ha[i]) _t = i;
		H[n] = t;
		res++;
		if (n)
		{
			res += DFS(n - 1, _t) + (1LL << n) - 1;
			Rep(i, 0, n) H[i] = t;
		}
		break;
	}
	return res;
}

int main()
{
#if 1
	freopen("test.txt", "rt", stdin);
#endif
	while (scanf("%s", H), H[0] != 'X')
	{
		int n = strlen(H);
		Rep(i, 0, n) H[i] -= 'A';
		printf("%lld\n", DFS(n - 1, 1));
	}
	return 0;
}
