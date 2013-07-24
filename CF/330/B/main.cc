#include <cstdlib>
#include <vector>
#include <map>
#include <cstdio>
#include <cctype>
#include <string.h>
#include <string>
#include <iostream>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < (b); c++)
const int maxn = 1e3 + 10;

int n, m, g[maxn][maxn];

int main()
{
#if 1
	freopen("input.txt", "r", stdin);
#endif
  for ( ; ~scanf("%d%d", &n, &m); ) {
    memset(g, 0, sizeof(g));
    for (int i = 0; i < m; i++) {
      int a, b;
      a--, b--;
      g[a][b] = g[b][a] = -1;
    }
  }
	return 0;
}
