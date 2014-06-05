#include <cstdlib>
#include <vector>
#include <map>
#include <cstdio>
#include <cctype>
#include <string.h>
#include <iostream>
using namespace std;
const int maxn = 100;
#define Rep(c, a, b) for (int c = a; c < (b); c++)
bool G[maxn][maxn], vis[maxn];
int n, m, one[maxn], two[maxn], three[maxn], stack[maxn];
void DFS(int u) {
	stack[stack[0]++] = u;
	vis[u] = 1;
	for (int v = 1; v <= n; v++) {
		if (G[u][v] && !vis[v]) {
			DFS(v);
		}
	}
}
int main()
{
#if 1
	freopen("input.txt", "r", stdin);
#endif
	while (~scanf("%d%d", &n, &m)) {
		memset(G, 0, sizeof(G));
		while (m--) {
			int a, b;
			scanf("%d%d", &a, &b);
			G[a][b] = G[b][a] = 1;
		}
		bool yes = 1;
		one[0] = two[0] = three[0] = 1;
		memset(vis, 0, sizeof(vis));
		for (int u = 1; u <= n; u++) {
			if (vis[u]) {
				continue;
			}
			stack[0] = 1;
			DFS(u);
			if (stack[0] == 2) {
				one[one[0]++] = stack[1];
			} else if (stack[0] == 3){
				for (int i = 1; i < stack[0]; i++) {
					two[two[0]++] = stack[i];
				}
			} else if (stack[0] == 4) {
				for (int i = 1; i < stack[0]; i++) {
					three[three[0]++] = stack[i];
				}
			} else {
				yes = 0;
				break;
			}
		}
		for ( ; yes && 1 < two[0]; two[0] -= 2, one[0]--) {
			three[three[0]++] = two[two[0] - 1];
			three[three[0]++] = two[two[0] - 2];
			if (one[0] < 2) {
				yes = 0;
				break;
			}
			three[three[0]++] = one[one[0] - 1];
		}
		for ( ; yes && 1 < one[0]; one[0] -= 3) {
			three[three[0]++] = one[one[0] - 1];
			three[three[0]++] = one[one[0] - 2];
			three[three[0]++] = one[one[0] - 3];
		}
		if (!yes) {
			puts("-1");
		} else {
			for ( ; 1 < three[0]; three[0] -= 3) {
				printf("%d %d %d\n", three[three[0] - 1],
						three[three[0] - 2],
						three[three[0] - 3]);
			}
		}
	} 
	return 0;
}
