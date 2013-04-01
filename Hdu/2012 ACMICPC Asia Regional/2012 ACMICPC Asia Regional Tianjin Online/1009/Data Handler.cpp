/*
 I can hardly belive that I hadn't read this problem clearly.
 It's Fu*king easy!!!!!
 Sh*t, we could got the ticket to Tianjin if I had fu*k this fu*king  problem!

 Clam down.....

 5 operations
 	MoveLeft L/R correspond to 
 		Move L/R to it's Precursor
 	MoveRight L/R correspond to 
 		Move L/R to it's Successor
 	Insert L/R X correspond to 
 		Insert X in L's Successor/R's Precursor
 	Delete L/R correspond to
 		Delete L's Successor/R's Precursor
 	Rervse correspond to
 		Splay L below root, Splay R below L and Rervse R's LeftSubtree
 	Output correspond to
 		Infix traversal. simulate the DFS to avoid Stack-OverFlow

 This's it.
 */
//Header
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
#include <cmath>
using namespace std;
//Macro
//STL-Alias
#define UN(c, a) unique(c, a)
#define MS(c, a) memset(c, a, sizeof c)
#define FLC(c, a ,b) fill(c, c + a, b)
#define LOS(c, a, b) lower_bound(c, a, b)
#define UPS(c, a, b) upper_bound(c, a, b)
//Syntax-Alias
#define Rep(c, a, b) for (int c = (a); c < (b); c++)
#define Nre(c, a, b) for (int c = (a); c > (b); c--)
//DEBUG
#define FK puts("Fu*k here!")
#define PA(s, c, a, b, p, f){\
	printf(s);\
	Rep(c, a, b) printf(p, (f));\
	puts("");}
//Constant
#define INFL (0x7fffffffffffffffLL)
#define INFI (0x7fffffff)
#define MOD ()
#define MAXN (1000005)
//Type-Alias
typedef long long LL;
typedef long double LD;
typedef int AI[MAXN];
typedef bool AB[MAXN];
typedef double AD[MAXN];
typedef LL ALL[MAXN];
typedef LD ALD[MAXN];

//SLY
typedef struct Node{
     int ky, sz;
     int rv;
     Node *p, *s[2];
} *PNode;
struct SLY{
    Node t[MAXN];
    PNode top, rt, ll, rr;
    void ini(){
        top = t;
        rt = ll = cre(-1);
        rt->s[1] = rr = cre(-2, rt);
    }
    PNode cre(int key, PNode fa = 0){
        top->ky = key;
        top->sz = 1;
        top->p = fa;
        top->s[0] = top->s[1] = 0;
        top->rv = 0;
        return top++;
    }
    PNode set(PNode x, int rvs){
        x->rv ^= rvs;
        if (rvs) swap(x->s[0], x->s[1]);
        return x;
    }
    PNode pus(PNode x){
        Rep(i, 0, 2) if (x->s[i]) set(x->s[i], x->rv);
        x->rv = 0;
        return x;
    }
    PNode upd(PNode x){
        x->sz = 1;
        Rep(i, 0, 2) if (x->s[i])
            x->sz += x->s[i]->sz;
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
	PNode pos(PNode x, bool b = 0){
		if (sly(pus(x))->s[b]) return mxk(x->s[b], !b);
		return x;
	}
    PNode del(PNode x){
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
        return upd(rt);
    }
    PNode bui(int l, int r, int *s, PNode fa = 0){
        int m = (l + r) >> 1;
        PNode x = cre(s[m], fa);
        if (l < m) x->s[0] = bui(l, m - 1, s, x);
        if (m < r) x->s[1] = bui(m + 1, r, s, x);
        return upd(x);
    }
    PNode sel(PNode x, int ind){
        int tid = 1 + (x->s[0]? x->s[0]->sz: 0);
        while (tid != ind){
            x = pus(x)->s[tid < ind];
            ind -= tid * (tid < ind);
            tid = 1 + (x->s[0]? x->s[0]->sz: 0);
        }
        return sly(x);
    }
    PNode ina(PNode x, int key = 0, bool b = 0){
        if (pus(x)->s[b]){
            PNode y = mxk(x->s[b], !b);
            x = y->s[!b] = cre(key, y);
        }
        else x = x->s[b] = cre(key, x);
        return sly(x);
    }
    PNode rvs(PNode x){
        return set(x, 1);
    }
    void tra(PNode x){
		stack<PNode> S;
		stack<int> L;
		S.push(x); L.push(0);
		bool f = 0;
		while (S.size()){
			if (!S.top() || L.top() == 3){
				if (S.top()) upd(S.top());
				S.pop(); L.pop();
			}
			else if (!L.top()){
				pus(S.top());
				S.push(S.top()->s[0]);
				L.top()++; L.push(0);
			}
			else if (L.top() < 2){
				if (!f) f = 1;
				else putchar(' ');
				printf("%d", S.top()->ky);
				L.top()++;
			}
			else{
				S.push(S.top()->s[1]);
				L.top()++; L.push(0);
			}
		}
		puts("");
    }
} zkl;

int n, m;
AI A;

int main()
{
#if 1
	freopen("test.txt", "r", stdin);
	freopen("test.out", "w", stdout);
#endif
	int T;
	scanf("%d", &T);
	while (T--)
	{
		//Initialize
		zkl.ini();
		scanf("%d", &n);
		Rep(i, 0, n) scanf("%d", A + i);
		zkl.sly(zkl.rr->s[0] = zkl.bui(0, n - 1, A, zkl.rr));
		int l, r;
		scanf("%d%d%d", &l, &r, &m);
		PNode P[2] = {zkl.sel(zkl.rt, l), zkl.sel(zkl.rt, r + 2)};
		while (m--)
		{
			zkl.sly(P[1], zkl.sly(P[0]));
			char op[20];
			scanf("%s", op);
			if (!strcmp(op, "Reverse"))
				zkl.rvs(P[1]->s[0]);
			else
			{
				char hd[4];
				scanf("%s", hd);
				bool b = hd[0] != 'L';
				if (!strcmp(op, "Delete"))
					zkl.del(zkl.pos(P[b], !b));
				else if (!strcmp(op, "MoveLeft"))
					P[b] = zkl.pos(P[b], 0);
				else if (!strcmp(op, "MoveRight"))
					P[b] = zkl.pos(P[b], 1);
				else 
				{
					int x;
					scanf("%d", &x);
					zkl.ina(P[b], x, !b);
				}
			}
		}
		//Solve
		zkl.tra(zkl.sly(zkl.rr, zkl.sly(zkl.ll))->s[0]);
	}
	return 0;
}
