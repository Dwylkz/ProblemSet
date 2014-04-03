#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_set>
using namespace std;
const int N = 1e5+5;
const int M = 1e2+5;
const int MOD = 1e9+7;

struct BIA {
	int t[N];
	void init() {
		memset(t, 0, sizeof(t));
	}
	void add(int x, int y) {
		for (x++; x < N; x += -x&x)
			t[x] += y;
	}
	void rangeAdd(int x, int y, int z) {
		add(x, z);
		add(y+1, -z);
	}
	int ask(int x) {
		int ret = 0;
		for (x++; x; x -= -x&x)
			ret += t[x];
		return ret;
	}
};

struct Ask {
	int l, r, k;
	void input() {
		scanf("%d%d%d", &l, &r, &k);
		l--;
		r--;
	}
} q[N];

BIA ts[M];
int n, m, a[N], c[N+M][M];

void init() {
	for (int i = 0; i < M; i++) ts[i].init();
	for (int i = c[0][0] = 1; i < N+M; i++)
		for (int j = c[i][0] = 1; j < M; j++)
			c[i][j] = (c[i-1][j]+c[i-1][j-1])%MOD;
}

int main() {
#ifndef ONLINE_JUDGE 
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d%d", &n, &m); ) {
		for (int i = 0; i < n; i++)
			scanf("%d", a+i);
		for (int i = 0; i < m; i++)
			q[i].input();
		init();
		sort(q, q+m, [&](Ask a, Ask b){return a.l < b.l;});
		for (int i = 0; i < m; i++) {
			int j = i;
			unordered_set<int> h;
			for ( ; i < m && q[i].l == q[j].l; i++) {
				ts[q[i].k].rangeAdd(q[i].l, q[i].r, 1);
				h.insert(q[i].k);
			}
			for (auto hi: h) {
				for (int k = 0; k < n; k++)
					if (k >= q[j].l)
						a[k] = (a[k]+1ll*c[k-q[j].l+hi][hi]*ts[hi].ask(k)%MOD)%MOD;
			}
			for (int k = j; k < i; k++)
				ts[q[k].k].rangeAdd(q[k].l, q[k].r, -1);
			i--;
		}
		for (int i = 0, w = 0; i < n; i++)
			printf("%d%c", a[i], i < n-1? ' ': '\n');
  }
  return 0;
}
