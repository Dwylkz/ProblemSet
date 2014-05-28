#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int N = 1e5+10;
const int MOD = 1e9+7;
const int MAGIC = 12347;

struct Graph {
	struct Edge {
		int v, to;
	};
	vector<Edge> es;
	vector<int> hs;
	void Init(int n){
		es.clear();
		hs = vector<int>(n, -1);
	}
	void Add(int u, int v) {
		Edge t = {v, hs[u]};
		hs[u] = es.size();
		es.push_back(t);
	}
	int operator () (int x) {
		return hs[x];
	}
	Edge& operator [] (int x) {
		return es[x];
	}
};
struct Fenwick {
	vector<int> t;
	void Init(int n) {
		t = vector<int>(n+2, 0);
	}
	void Add(int x, int y) {
		for (x++; x < t.size(); x += -x&x)
			t[x] = (t[x]+y)%MOD;
	}
	int Get(int x) {
		int ret = 0;
		for (x++; x; x -= -x&x)
			ret = (ret+t[x])%MOD;
		return ret;
	}
	void RangeAdd(int l, int r, int y) {
		Add(l,y);
		Add(r+1, -y);
	}
};
struct Operate {
	int l, r, d;
};

Graph g;
vector<Operate> o[N];
int n, q, w[N];

Fenwick zkl;
void go(int u, int d) {
	for (int i = 0; i < o[u].size(); i++)
		zkl.RangeAdd(o[u][i].l, o[u][i].r, o[u][i].d);
	w[u] = (w[u]+zkl.Get(d))%MOD;
	for (int e = g(u); ~e; e = g[e].to)
		go(g[e].v, d+1);
	for (int i = 0; i < o[u].size(); i++)
		zkl.RangeAdd(o[u][i].l, o[u][i].r, -o[u][i].d);
}

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
	int T;
	scanf("%d", &T);
  for (int cas = 1; cas <= T; cas++) {
		scanf("%d", &n);
		g.Init(n);
		for (int v = 1; v < n; v++) {
			int u;
			scanf("%d", &u);
			g.Add(u-1, v);
		}
		scanf("%d", &q);
		for (int i = 0; i < n; i++)
			o[i].clear();
		for (int i = 0; i < q; i++) {
			int u, l, r, d;
			scanf("%d%d%d%d", &u, &l, &r, &d);
			Operate t = {l, r, (d%MOD+MOD)%MOD};
			o[u-1].push_back(t);
		}
		zkl.Init(n);
		fill(w, w+n, 0);
		go(0, 1);
		int ret = 0;
		for (int i = 0; i < n; i++)
			ret = (1ll*ret*MAGIC%MOD+w[i])%MOD;
		printf("Case %d: %d\n", cas, ret);
  }
  return 0;
}
