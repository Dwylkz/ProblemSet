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
#define MAXN (50005)
#define MAXB (15)
#define GB(x, y) (((x) >> (y)) & 1)
#define INFI (0x7fffffff)

typedef struct INode
{
	INode *ky[2];
} *PINode;
INode It[(1 << MAXB) * (1 << 10)], *Itop = It;
struct IDT
{
	PINode rt;
	void ini()
	{
		rt = cre();
	}
	PINode cre()
	{
		MS(Itop->ky, 0);
		return Itop++;
	}
	void ins(int ky)
	{
		PINode x = rt;
		Nre(i, 14, -1)
		{
			int b = GB(ky, i);
			if (!x->ky[b]) x->ky[b] = cre();
			x = x->ky[b];
		}
	}
	int que(int ky)
	{
		PINode x = rt;
		int res = 0;
		Nre(i, 14, -1)
		{
			int b = GB(ky, i);
			if (x->ky[!b])
			{
				res += 1 << i;
				x = x->ky[!b];
			}
			else x = x->ky[b];
		}
		return res;
	}
} idt;

typedef struct SNode
{
	IDT idt;
	int l, r, m;
	SNode *ls, *rs;
} *PSNode;
SNode St[MAXN << 1], *Stop = St;
struct SGT
{
	PSNode rt;
	void ini(int *s, int l, int r)
	{
		bui(s, l, r, rt = Stop++);
	}		
	void bui(int *s, int l, int r, PSNode x)
	{
		x->l = l;
		x->r = r;
		x->m = (l + r) >> 1;
		x->ls = x->rs = 0;
		x->idt.ini();
		Rep(i, l, r + 1) x->idt.ins(s[i]);
		if (l == r) return ;
		if (l <= x->m) bui(s, l, x->m, x->ls = Stop++);
		if (x->m < r) bui(s, x->m + 1, r, x->rs = Stop++);
	}
	int que(int l, int r, int b, PSNode x)
	{
		int res = 0;
		if (l <= x->l && x->r <= r) res = x->idt.que(b);
		else
		{
			if (l <= x->m) res = max(res, que(l, r, b, x->ls));
			if (x->m < r) res = max(res, que(l, r, b, x->rs));
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

	while (~scanf("%d%d", &n, &m))
	{
		Itop = It;
		Stop = St;
		Rep(i, 0, n) scanf("%d", s + i);
		sgt.ini(s, 0, n - 1);
		while (m--)
		{
			int h, o, b;
			scanf("%d%d%d", &h, &o, &b);
			if (h > o) swap(h, o);
			printf("%d\n", sgt.que(--h, --o, b, sgt.rt));
		}
	}

	return 0;
}
