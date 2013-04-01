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
#define MS(a, b) memset(a, b, sizeof a)
#define Rep(c, a, b) for (int c = (a); c < (b); c++)
#define Nre(c, a, b) for (int c = (a); c > (b); c--)
#define MAXN (110000)

typedef struct Node
{
	int l, m, r, ln,
		cc, rv, lc[2], rc[2], mc[2], sm[2];
	Node *ls, *rs;
	Node()
	{
		l = m = r = ln = cc = rv = 0;
		Rep(i, 0, 2) lc[i] = rc[i] = mc[i] = sm[i] = 0;
	}
	void pus()
	{
		ls->set(cc, rv);
		rs->set(cc, rv);
		cc = -1;
		rv = 0;
	}
	void set(int _cc, int _rv)
	{
		if (_cc > -1)
		{
			cc = _cc;
			Rep(i, 0, 2) lc[i] = rc[i] = mc[i] = sm[i] = ln * (cc == i);
			rv = 0;
		}
		if (_rv)
		{
			swap(lc[0], lc[1]);
			swap(rc[0], rc[1]);
			swap(mc[0], mc[1]);
			swap(sm[0], sm[1]);
			if (cc > -1) cc ^= 1;
			else rv ^= 1;
		}
	}
	void upd(Node *ls, Node *rs)
	{
		cc = (ls->cc == rs->cc)? ls->cc: -1;
		Rep(i, 0, 2)
		{
			sm[i] = ls->sm[i] + rs->sm[i];
			lc[i] = ls->lc[i] + (ls->lc[i] == ls->ln) * rs->lc[i];
			rc[i] = rs->rc[i] + (rs->rc[i] == rs->ln) * ls->rc[i];
			mc[i] = max(ls->rc[i] + rs->lc[i], max(ls->mc[i], rs->mc[i]));
		}
	}
} *PNode;
struct SGT
{
	Node t[MAXN << 1], *top;
	void ini(int l, int r)
	{
		bui(l, r, top = t);
	}
	void bui(int l, int r, PNode x)
	{
		if (!x) x = t;
		x->l = l;
		x->r = r;
		x->m = (l + r) >> 1;
		x->ln = r - l + 1;
		x->ls = x->rs = 0;
		x->cc = x->rv = 0;
		x->set(0, 0);
		if (l == r) return ;
		if (l <= x->m) bui(l, x->m, x->ls = ++top);
		if (x->m < r) bui(x->m + 1, r, x->rs = ++top);
	}
	void ins(int l, int r, int _cc, int _rv, PNode x)
	{
		if (l <= x->l && x->r <= r) x->set(_cc, _rv);
		else
		{
			x->pus();
			if (l <= x->m) ins(l, r, _cc, _rv, x->ls);
			if (x->m < r) ins(l, r, _cc, _rv, x->rs);
			x->upd(x->ls, x->rs);
		}
	}
	Node que(int l, int r, PNode x)
	{
		Node res;
		if (l <= x->l && x->r <= r) res = *x;
		else
		{
			Node lre, rre;
			x->pus();
			if (l <= x->m) lre = que(l, r, x->ls);
			if (x->m < r) rre = que(l, r, x->rs);
			x->upd(x->ls, x->rs);
			res.upd(&lre, &rre);
		}
		return res;
	}
} sgt;

int n, m;

int main()
{
#if 1
	freopen("test.txt", "rt", stdin);
#endif

	int T;

	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &n, &m);
		sgt.ini(0, n - 1);
		Rep(i, 0, n)
		{
			int si;
			scanf("%d", &si);
			sgt.ins(i, i, si, 0, sgt.t);
		}
		while (m--)
		{
			int op, a, b;
			scanf("%d%d%d", &op, &a, &b);
			if (op < 2) sgt.ins(a, b, op, 0, sgt.t);
			else if (op < 3) sgt.ins(a, b, -1, 1, sgt.t);
			else
			{
				Node x = sgt.que(a, b, sgt.t);
				if (op < 4) printf("%d\n", x.sm[1]);
				else printf("%d\n", x.mc[1]);
			}
		}
	}
	return 0;
}
