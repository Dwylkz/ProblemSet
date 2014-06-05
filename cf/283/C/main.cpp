#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <stack>
#include <string.h>
#include <iostream>
using namespace std;
const int MAXN = 2*10e5+10;
#define Rep(c, a, b) for (int c = (a); c < (b); c++)
//SLY
typedef struct Node{
	int ky, sz, ct, sm, lz;
	int rv;
	Node *p, *s[2];
} *PNode;
Node t[MAXN];
PNode top;
struct SLY{
	PNode rt, ll, rr;
	PNode cre(int ky, PNode fa = 0){
		PNode x;
		x = top++;
		x->ky = ky;
		x->sz = x->ct = 1;
		x->p = fa;
		x->s[0] = x->s[1] = 0;
		x->rv = 0;
		x->sm = ky;
		x->lz = 0;
		return x;
	}
	PNode ini(){
		top = t;
		rt = rr = cre(-2);
		rt->s[0] = ll = cre(-1, rt);
		sly(ll);
		return rt;
	}
	PNode set(int _rv, int _lz, PNode x){
		x->rv ^= _rv;
		if (_rv) swap(x->s[0], x->s[1]);
		x->ky += _lz;
		x->sm += _lz * x->sz;
		x->lz += _lz;
		return x;
	}
	PNode pus(PNode x){
		Rep(i, 0, 2) if (x->s[i]) {
			set(x->rv, x->lz, x->s[i]);
		}
		x->rv = 0;
		x->lz = 0;
		return x;
	}
	PNode upd(PNode x){
		x->sz = 1;
		x->sm = x->ky;
		Rep(i, 0, 2) if (x->s[i]) {
			x->sz += x->s[i]->sz;
			x->sm += x->s[i]->sm;
		}
#if 1
		puts("here");
#endif
		return x;
	}
	PNode rot(PNode x, bool b = 0){
		PNode y = pus(pus(x)->s[!b]);
		x->s[!b] = y->s[b];
		if (y->s[b]) y->s[b]->p = x;
		y->p = x->p;
		if (!x->p) rt = y;
		else x->p->s[x->p->s[0] != x] = y;
		x->p = y; y->s[b] = x;
		return upd(x);
	}
	PNode sly(PNode x, PNode fa = 0){
		while (x->p != fa){
			bool bp = x->p->s[0] != x;
			if (x->p->p == fa){
				rot(x->p, !bp);
				break;
			}
			bool bg = x->p->p->s[0] != x->p;
			if (bg ^ bp) rot(x->p, bg);
			else rot(x->p->p, !bg);
			rot(x->p, !bg);
		}
		return upd(x);
	}
	PNode mxk(PNode x, bool b = 0){
		while (pus(x)->s[b]) x = x->s[b];
		return x;
	}
	PNode del(PNode x){
		if (!--x->ct){
			if (sly(pus(x))->s[1]){
				PNode y = sly(mxk(x->s[1], 0));
				y->s[0] = x->s[0];
				if (x->s[0]) x->s[0]->p = y;
				x->p = 0;
			}
			else{
				rt = x->s[0];
				if (rt) rt->p = 0;
				x->s[0] = 0;
			}
		}
		return rt? upd(rt): rt;
	}
	PNode sel(int k, PNode x){
		int t = 1 + (x->s[0]? x->s[0]->sz: 0);
		while (t != k){
			x = pus(x)->s[t < k];
			k -= t * (t < k);
			t = 1 + (x->s[0]? x->s[0]->sz: 0);
		}
		return sly(x);
	}
	PNode ina(int ky, PNode x, bool b = 0){
		if (pus(x)->s[b]){
			PNode y = mxk(x->s[b], !b);
			x = y->s[!b] = cre(ky, y);
		}
		else x = x->s[b] = cre(ky, x);
		return sly(x);
	}
	PNode add(int lz, PNode x) {
		return set(0, lz, x);
	}
	PNode tra(PNode x){
		stack<PNode> S;
		stack<int> L;
		S.push(x); L.push(0);
		bool f = 0;
		while (S.size()){
			if (!S.top() || L.top() == 3){
				if (S.top()) upd(S.top());
				S.pop(); L.pop();
			} else if (!L.top()){
				pus(S.top());
				S.push(S.top()->s[0]);
				L.top()++; L.push(0);
			} else if (L.top() < 2){
				if (!f) f = 1;
				else putchar(' ');
				//printf("%d", S.top()->ky);
#if 1
				printf("%d->(%d, %d)", S.top()->ky,
						(S.top()->s[0] != 0? S.top()->s[0]->ky: -3),
						(S.top()->s[1] != 0? S.top()->s[1]->ky: -3));
#endif
				L.top()++;
			} else{
				S.push(S.top()->s[1]);
				L.top()++; L.push(0);
			}
		}
		puts("");
		return x;
	}
};

SLY zkl;

int main()
{
#if 1
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	int n, t, a, x, k;
	while (~scanf("%d", &n)) {
		zkl.ini();
#if 0
		printf("%d\n ", zkl.rt->sz);
#endif
		zkl.ina(0, zkl.sel(zkl.rt->sz - 1, zkl.rt), 1);
		while (n--) {
			scanf("%d", &t);
			if (t == 1) {
				scanf("%d%d", &a, &x);
				PNode i = zkl.sly(zkl.sel(1, zkl.rt));
#if 1
				printf("sz = %d\n", zkl.rt->sz);
				zkl.tra(zkl.rt);
				printf("i->s[1] = %d, rt = %d\n", i->s[1]->ky, zkl.rt == i);
#endif
				PNode j = zkl.sel(a + 2, zkl.rt);
				zkl.sly(j, i);
#if 1
				printf("i = %d j = %d\n", i->ky, j->ky);
#endif
				//zkl.sly(zkl.add(x, i->s[0]));
			} else if (t == 2) {
				scanf("%d", &k);
				zkl.ina(k, zkl.sel(zkl.rt->sz, zkl.rt));
			} else {
				zkl.del(zkl.sel(zkl.rt->sz - 1, zkl.rt));
			}
#if 1
			printf("sz = %d\n", zkl.rt->sz);
			zkl.tra(zkl.rt);
#endif
			int sm = zkl.rt->sm + 3;
			printf("%.6lf\n", 1.0 * sm / (zkl.rt->sz - 2));
		}
	}
	return 0;
}
