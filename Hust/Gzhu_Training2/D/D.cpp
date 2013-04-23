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
#define MAXN (110000)

int n, d, a, b, C[MAXN], id[MAXN];

bool cmp(int p, int q)
{
	return C[p] < C[q];
}

vector<int> RC;

int main()
{
#if 1
	freopen("test.txt", "rt", stdin);
#endif
	while (~scanf("%d%d", &n, &d))
	{
		scanf("%d%d", &a, &b);
		Rep(i, 0, n)
		{
			int ai, bi;
			scanf("%d%d", &ai, &bi);
			id[i] = i;
			C[i] = a * ai + b * bi;
		}
		sort(id, id + n, cmp);
		RC.clear();
		int res = 0;
		Rep(i, 0, n)
			if (d >= C[id[i]])
			{
				d -= C[id[i]];
				RC.push_back(id[i] + 1);
				res++;
			}
			else break;
		printf("%d\n", res);
		Rep(i, 0, RC.size())
		{
			printf("%d", RC[i]);
			if (i < RC.size() - 1) putchar(' ');
		}
		puts("");
	}
	return 0;
}
