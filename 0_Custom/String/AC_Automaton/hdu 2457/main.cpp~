//coder: SXDwylkz
//heads
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cctype>
#include <algorithm>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <cstring>
#include <cmath>
//namespaces
using namespace std;
//constants
const char input[] = "input.in",
	  output[] = "output.out";
const int inf32 = 0x7fffffff,
	  maxn = 1e3 + 10,
	  maxm = 55 * 22;
const long long inf64 = 0x7fffffffffffffffLL; 
//type definition
typedef int AB[maxn];
typedef int AI[maxn];
typedef char AC[maxn];
typedef long long LL;
//Extern
struct ACA {
	enum {n = maxm, m = 4};
	typedef struct Node {
		Node *s[m], *p;
		int a, d;
	} *PNode;
	Node t[n], *rt, *q[n];
	int sz;
	void init() {
		memset(t, sz = 0, sizeof(t));
		rt = t + sz++;
	}
	void add(int a, int *k, int l) {
		PNode x = rt;
		for (int i = 0; i < l; i++) {
			int j = k[i];
			if (!x->s[j]) {
				x->s[j] = t + sz++;
			}
			x = x->s[j];
		}
		x->a = a;
	}
	void make() {
		PNode *h = q, *o = q;
		rt->p = rt;
		for (int i = 0; i < m; i++) {
			if (rt->s[i]) {
				rt->s[i]->p = rt;
				rt->s[i]->d = 1;
				*(o++) = rt->s[i];
			} else {
				rt->s[i] = rt;
			}
		}
		for ( ; h < o; ) {
			PNode u = *(h++);
			for (int i = 0; i < m; i++) {
				if (u->s[i]) {
					u->s[i]->p = u->p->s[i];
					u->s[i]->d = u->d + 1;
					u->s[i]->a |= u->p->s[i]->a;
					*(o++) = u->s[i];
				} else {
					u->s[i] = u->p->s[i];
				}
			}
		}
	}
};
ACA aca;
int n, key[maxn], f[maxn][maxm], hs[128];
char buf[maxn];
void toInt(int *t, char *s) {
	hs['A'] = 0;
	hs['C'] = 1;
	hs['T'] = 2;
	hs['G'] = 3;
	for ( ; *s; s++) {
		*(t++) = hs[*s];
	}
}
int dMin(int lv, int rv) {
	if (rv < lv) {
		swap(lv, rv);
	}
	if (lv == -1) {
		return rv;
	}
	return lv;
}
//main
int main() {
#if 1
	freopen(input, "r", stdin);
	//freopen(output, "w", stdout);
#endif
	for (int Case = 1; ~scanf("%d", &n) && n; ) {
		aca.init();
		for (int i = 0; i < n; i++) {
			scanf("%s", buf);
			toInt(key, buf);
			aca.add(1, key, strlen(buf));
		}
		aca.make();
		scanf("%s", buf);
		toInt(key, buf);
		memset(f, -1, sizeof(f));
		f[0][0] = 0;
		for (int i = 1, l = strlen(buf); i <= l; i++) {
			for (int u = 0; u < aca.sz; u++) {
				if (f[i - 1][u] == -1) {
					continue;
				}
				for (int j = 0; j < 4; j++) {
					int v = aca.t[u].s[j] - aca.t, d = (key[i - 1] != j);
					if (!aca.t[v].a) {
						f[i][v] = dMin(f[i - 1][u] + d, f[i][v]);
					}
				}
			}
		}
		int res = -1;
		for (int u = 0, l = strlen(buf); u < aca.sz; u++) {
			res = dMin(res, f[l][u]);
		}
		printf("Case %d: %d\n", Case++, res);
	}
	return 0;
}
