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
#define MAXN (11000000)

char EC[MAXN], C[MAXN];

int main()
{
#if 1
	freopen("test.txt", "rt", stdin);
#endif
	int T, Cas = 1;

	scanf("%d\n", &T);
	while (T--)
	{
		scanf("%[^\n]", C);
		scanf("%s\n", EC);
		int l = strlen(C);
		printf("%d ", Cas++);
		Rep(i, 0, l) if ('A' <= C[i] && C[i] <= 'Z')
			putchar(EC[C[i] - 'A']);
		else putchar(C[i]);
		puts("");
	}
	return 0;
}
