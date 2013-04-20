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
	  maxn = 1e6 + 10;
const long long inf64 = 0x7fffffffffffffffLL; 
//structure
struct Node {
	int s, c, x;
	Node *ls, *rs;
	void set(int _c, int _x, int l, int r) {
		if (_c != -1) {
			s = _c * (r - l + 1);
			x = 0;
			c = _c;
		} else if (_x) {
			s = (r - l + 1) - s;
			if (c != -1) {
				c ^= 1;
			} else {
				x ^= _x;
			}
		}
	}
	void pus(int l, int r) {
		int m = l + r >> 1;
		ls->set(c, x, l, m);
		rs->set(c, x, m + 1, r);
		c = -1;
		x = 0;
	}
	void upd(int l, int r) {
		s = ls->s + rs->s;
	}
};
//type definition
typedef long long LL;
typedef Node *PNode;
//global variable
Node t[maxn * 2 * 4];
PNode rt[4], top;
int n, m, A[maxn];
//access and mutator
int GetBit(int x, int i) {
	return (x >> i) & 1;
}
void Init() {
	top = t;
}
PNode New() {
	return top++;
}
void Build(int *s, int i, int L, int R, PNode x) {
	x->c = -1;
	x->s = x->x = 0;
	if (L == R) {
		x->s = x->c = GetBit(s[L], i);
		return ;
	}
	int m = L + R >> 1;
	if (L <= m) {
		Build(s, i, L, m, x->ls = New());
	}
	if (m < R) {
		Build(s, i, m + 1, R, x->rs = New());
	}
	x->upd(L, R);
}
void Cover(int op, int xo, int l, int r, int L, int R, PNode x) {
	if (l <= L && R <= r) {
		x->set(op, xo, L, R);
	} else {
		int m = L + R >> 1;
		x->pus(L, R);
		if (l <= m) {
			Cover(op, xo, l, r, L, m, x->ls);
		}
		if (m < r) {
			Cover(op, xo, l, r, m + 1, R, x->rs);
		}
		x->upd(L, R);
	}
}
int Ask(int l, int r, int L, int R, PNode x) {
	int res = 0;
	if (l <= L && R <= r) {
		res = x->s;
	} else {
		int m = L + R >> 1;
		x->pus(L, R);
		if (l <= m) {
			res += Ask(l, r, L, m, x->ls);
		}
		if (m < r) {
			res += Ask(l, r, m + 1, R, x->rs);
		}
		x->upd(L, R);
	}
	return res;
}
//main
int main() {
#if 1
	freopen(input, "r", stdin);
	//freopen(output, "w", stdout);
#endif
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++) {
			scanf("%d", A + i);
		}
		Init();
		for (int i = 0; i < 4; i++) {
			Build(A, i, 0, n - 1, rt[i] = New());
		}
		while (m--) {
			char op[10];
			int opn, L, R;
			scanf("%s", op);
			if (!strcmp(op, "SUM")) {
				scanf("%d%d", &L, &R);
				int res = 0;
				for (int i = 3; 0 <= i; i--) {
					res =  res * 2 + Ask(L, R, 0, n - 1, rt[i]);
				}
				printf("%d\n", res);
			} else {
				scanf("%d%d%d", &opn, &L, &R);
				for (int i = 0; i < 4; i++) {
					int b = GetBit(opn, i);
					if (!strcmp(op, "AND") && !b) {
						Cover(0, 0, L, R, 0, n - 1, rt[i]);
					}
					if (!strcmp(op, "OR") && b) {
						Cover(1, 0, L, R, 0, n - 1, rt[i]);
					}
					if (!strcmp(op, "XOR") && b) {
						Cover(-1, 1, L, R, 0, n - 1, rt[i]);
					}
				}
			}
#if 0
			for (int i = 0 ; i < n; i++) {
				int res = 0;
				for (int j = 3; 0 <= j; j--) {
					res = res * 2 + Ask(i, i, 0, n - 1, rt[j]);
				}
				printf("%3d", res);
			}
			puts("");
#endif
		}
	}
	return 0;
}
