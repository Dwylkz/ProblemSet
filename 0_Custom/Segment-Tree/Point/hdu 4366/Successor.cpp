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
#define MS(c, a) memset(c, a, sizeof c)
#define Rep(c, a, b) for (int c = (a); c < (b); c++)
#define Nre(c, a, b) for (int c = (a); c > (b); c--)
#define MAXN (50050)
#define MAXM (1000010)
#define INFI (0x7fffffff)

struct Edge
{
	int v, next;
};
vector<Edge> E;
int L[MAXN];
void G_ini()
{
	E.clear();
	MS(L, -1);
}
void AE(int u, int v)
{
	Edge te = {v, L[u]};
	L[u] = E.size();
	E.push_back(te);
}

struct Stf
{
	int sr, ll, ay, l, r;
	void inp()
	{
		scanf("%d%d%d", &sr, &ll, &ay);
	}
} s[MAXN];
bool cmp(int p, int q)
{
	return s[p].ay > s[q].ay;
}

typedef struct SNode
{
	int l, r, m, mx;
	SNode *ls, *rs;
	SNode()
	{
		l = r = m = mx = -1;
		ls = rs = 0;
	}
	void set(int _mx)
	{
		mx = _mx;
	}
	void upd(SNode *ls, SNode *rs)
	{
		mx = max(ls->mx, rs->mx);
	}
} *PSNode;
SNode St[MAXN << 1], *Stop = St;
struct SGT
{
	PSNode rt;
	void bui(int l, int r, PSNode x)
	{
		x->l = l;
		x->r = r;
		x->m = (l + r) >> 1;
		x->set(-1);
		if (l == r) return ;
		bui(l, x->m, x->ls = ++Stop);
		bui(x->m + 1, r, x->rs = ++Stop);
	}
	void ins(int l, int r, int _mx, PSNode x)
	{
		if (l <= x->l && x->r <= r) x->set(_mx);
		else
		{
			if (l <= x->m) ins(l, r, _mx, x->ls);
			if (x->m < r) ins(l, r, _mx, x->rs);
			x->upd(x->ls, x->rs);
		}
	}
	SNode que(int l, int r, PSNode x)
	{
		SNode res;
		if (l <= x->l && x->r <= r) res = *x; 
		else
		{
			SNode lre, rre;
			if (l <= x->m) lre = que(l, r, x->ls);
			if (x->m < r) rre = que(l, r, x->rs);
			x->upd(x->ls, x->rs);
			res.upd(&lre, &rre);
		}
		return res;
	}
} sgt;

int n, m, id[MAXN], ind, res[MAXM], H[MAXM];

void TTI(int u)
{
	s[u].l = ind++;
	for (int i = L[u]; i != -1; i = E[i].next) TTI(E[i].v);
	s[u].r = ind - 1;
}

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
		G_ini();
		MS(H, -1);
		Rep(i, 1, n)
		{
			s[i].inp();
			H[s[i].ll] = id[i] = i;
			AE(s[i].sr, i);
		}
		TTI(ind = 0);
		sort(id + 1, id + n, cmp);
		sgt.bui(0, n - 1, sgt.rt = Stop = St);
		for (int i = 1; i < n;) 
		{
			int j;
			for (j = i; j < n && s[id[j]].ay == s[id[i]].ay; j++)
			{
				SNode x;
				if (s[id[j]].l < s[id[j]].r)
					x = sgt.que(s[id[j]].l + 1, s[id[j]].r, sgt.rt);
				res[id[j]] = x.mx < 0? -1: H[x.mx];
			}
			for (j = i; j < n && s[id[j]].ay == s[id[i]].ay; j++)
				sgt.ins(s[id[j]].l, s[id[j]].l, s[id[j]].ll, sgt.rt);
			i = j;
		}
		while (m--)
		{
			int q;
			scanf("%d", &q);
			printf("%d\n", res[q]);	
		}
	}
	return 0;
}
