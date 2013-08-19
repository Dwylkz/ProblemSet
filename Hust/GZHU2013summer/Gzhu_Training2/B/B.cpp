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
#define MAXN ()

int main()
{
#if 1
	freopen("test.txt", "rt", stdin);
#endif
	int X, T, a, b, da, db;
	while (~scanf("%d%d%d%d%d%d", &X, &T, &a, &b, &da, &db))
	{
		bool yes = 0;
		if (X == 0) yes = 1;
		Rep(i, 0, T) if (max(0, a - i * da) == X || max(0, b - i * db) == X)
			yes = 1;
		Rep(i, 0, T) Rep(j, 0, T)
			if (X == max(0, a - i * da) + max(0, b - j * db))
				yes = 1;	
		puts(yes? "YES": "NO");
	}

	return 0;
}
