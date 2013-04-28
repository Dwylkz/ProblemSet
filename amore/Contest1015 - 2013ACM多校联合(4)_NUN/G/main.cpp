#include <cstdio>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
const int maxn = 1e5 + 10;
typedef unsigned char UC;
typedef unsigned int UI;
struct Edge {
	int w, v, to;
};
int L[maxn];
vector<Edge> E;
void EdgeInit() {
	E.clear();
	memset(L, -1, sizeof(L));
}
void AE(int w, int u, int v) {
	Edge te = {w, v, L[u]};
	L[u] = E.size();
	E.push_back(te);
}
void SAE(int w, int x, int u, int v) {
	AE(w, u, v);
	AE(x, v, u);
}
int s, t, m;
//Dinic
int dis[maxn];
int BFS(int src, int snk) {
	queue<int> Q;
	memset(dis, -1, sizeof(dis));
	Q.push(snk);
	dis[snk] = 0;
	while (!Q.empty()) {
		int u = Q.front();
		Q.pop();
		for (int i = L[u]; i != -1; i = E[i].to) {
			int v = E[i].v;
			if (E[i ^ 1].w && dis[v] == -1) {
				dis[v] = dis[u] + 1;
				Q.push(v);
			}
		}
	}
	return dis[src] != -1;
}
int DFS(int u, int mf = 0x7fffffff) {
	int rm = mf;
	if (!dis[u]) {
		return mf;
	}
	for (int i = L[u]; i != -1; i = E[i].to) {
		int w = E[i].w, v = E[i].v;
		if (w && dis[u] == dis[v] + 1) {
			int df = DFS(v, min(rm, w));
			E[i].w -= df;
			E[i ^ 1].w += df;
			rm -= df;
			if (!rm) {
				return mf;
			}
		}
	}
	return mf - rm;
}
int Dinic(int src, int snk) {
	int maxf = 0;
	while (BFS(src, snk)) {
		maxf += DFS(src);
	}
	return maxf;
}
int main() {
#if 1
	freopen("input.txt", "rt", stdin);
#endif
	while (~scanf("%d%d%d", &s, &t, &m)) {
		EdgeInit();
		while (m--) {
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			SAE(w, 0, u, v);
		}
		printf("%d\n", Dinic(s, t));
	}
}
