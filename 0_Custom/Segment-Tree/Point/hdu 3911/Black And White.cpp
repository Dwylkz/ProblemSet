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
#define MAXN (100010)

typedef struct SNode
{
	int l, r, m, ln,
		cc, rv, lc[2], rc[2], mc[2];
	SNode *ls, *rs;
	SNode()
	{
		l = r = m = ln = cc = rv = 0;
		Rep(i, 0, 2) lc[i] = rc[i] = mc[i] = 0;
	}
	void set(int _cc, int _rv)
	{
		if (_cc != -1)
		{
			cc = _cc;
			Rep(i, 0, 2) lc[i] = rc[i] = mc[i] = ln * (cc == i);
			rv = 0;
		}
		if (_rv) 
		{
			swap(lc[0], lc[1]);
			swap(rc[0], rc[1]);
			swap(mc[0], mc[1]);
			if (cc != -1) cc ^= 1;
			else rv ^= 1;
		}
	}
	void pus()
	{
		ls->set(cc, rv);
		rs->set(cc, rv);
		cc = -1;
		rv = 0;
	}
	void upd(SNode *ls, SNode *rs)
	{
		cc = (ls->cc == rs->cc)? ls->cc: -1;
		Rep(i, 0, 2)
		{
			lc[i] = ls->lc[i] + (ls->lc[i] == ls->ln) * (rs->lc[i]);	
			rc[i] = rs->rc[i] + (rs->rc[i] == rs->ln) * (ls->rc[i]);	
			mc[i] = ls->rc[i] + rs->lc[i];	
			mc[i] = max(mc[i], max(ls->mc[i], rs->mc[i]));
		}
	}
} *PSNode;
SNode St[MAXN << 1], *Stop = St;
struct SGT
{
	PSNode rt;
	void bui(int *s, int l, int r, PSNode x)
	{
		x->l = l;
		x->r = r;
		x->m = (l + r) >> 1;
		x->ln = r - l + 1;
		x->set(x->cc = 0, x->rv = 0);
		if (l == r)
		{
			x->set(s[l], 0);
			return ;
		}
		bui(s, l, x->m, x->ls = Stop++);
		bui(s, x->m + 1, r, x->rs = Stop++);
		x->upd(x->ls, x->rs);
	}
	void ins(int l, int r, PSNode x)
	{
		if (l <= x->l && x->r <= r) x->set(-1, 1);
		else
		{
			x->pus();
			if (l <= x->m) ins(l, r, x->ls);
			if (x->m < r) ins(l, r, x->rs);
			x->upd(x->ls, x->rs);
		}
	}
	SNode que(int l, int r, PSNode x)
	{
		SNode res;
		if (l <= x->l && x->r <= r) res = *x; 
		else
		{
			x->pus();
			SNode lre, rre;
			if (l <= x->m) lre = que(l, r, x->ls);
			if (x->m < r) rre = que(l, r, x->rs);
			x->upd(x->ls, x->rs);
			res.upd(&lre, &rre);
		}
		return res;
	}
} sgt;

int n, m, s[MAXN];

int main()
{
#if 1
	freopen("test.txt", "rt", stdin);
#endif
	while (~scanf("%d", &n))
	{
		Stop = St;
		Rep(i, 0, n) scanf("%d", s + i);
		sgt.bui(s, 0, n - 1, sgt.rt = Stop++);
		scanf("%d", &m);
		while (m--)
		{
			int x, i, j;
			scanf("%d%d%d", &x, &i, &j);
			i--;
			j--;
			if (x) sgt.ins(i, j, sgt.rt);
			else
			{
				SNode x = sgt.que(i, j, sgt.rt);
				printf("%d\n", x.mc[1]);
			}			
		}
	}
	return 0;
}
