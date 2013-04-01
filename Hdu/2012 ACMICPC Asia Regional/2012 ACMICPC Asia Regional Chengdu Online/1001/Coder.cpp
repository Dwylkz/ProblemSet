/*
 Maintain two domain when we update the splay tree.
 	x->s[i] as the sum of aj which j mod 5 == i in subtree x
 	x->sz as the size of subtree x
 
 Then, Root->s[3] is the sum of whole set.

 k = tree size;
 add O(logk)
 del O(logk)
 sum O(1)
 
 So, the time complexity is about O(nlogn).
*/
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
//STL
#define MS(c, a) memset(c, a, sizeof c)
//Syntax
#define Rep(c, a, b) for (int c = (a); c < (b); c++)
#define Nre(c, a, b) for (int c = (a); c > (b); c--)
//DEBUG
#define FK puts("Fu*k here!")
//Type
typedef unsigned int UI;
typedef long long LL;
typedef long double LD;
//Constant
const LL INFL = 0x7fffffffffffffffLL;
const int INFI = 0x7fffffff;
const int MAXN = 100005;
const int MOD = 1000000007;
//Array
typedef int AI[MAXN];
typedef bool AB[MAXN];
typedef double AD[MAXN];
typedef LL ALL[MAXN];
typedef LD ALD[MAXN];

//SLY
typedef struct Node{
     int ky, sz, ct;
     LL sm[5];
     Node *p, *s[2];
} *PNode;
struct SLY{
    Node t[MAXN];
    PNode top, rt;
    void ini(){
        top = t;
		rt = 0;
    }
    PNode cre(int key, PNode fa = 0){
        top->ky = key;
        top->sz = top->ct = 1;
        top->p = fa;
        top->s[0] = top->s[1] = 0;
        MS(top->sm, 0);
        return top++;
    }
    PNode set(PNode x, int rvs){
        return x;
    }
    PNode pus(PNode x){
        return x;
    }
    PNode upd(PNode x){
        x->sz = 1;
        Rep(i, 0, 2) if (x->s[i])
			x->sz += x->s[i]->sz;
		int ls = x->sz; 
		if (x->s[1]) ls -= x->s[1]->sz;
		MS(x->sm, 0);
		x->sm[ls % 5] = x->ky;
		if (x->s[0]) Rep(i, 0, 5) x->sm[i] += x->s[0]->sm[i];
		if (x->s[1]) Rep(i, 0, 5) x->sm[(ls + i) % 5] += x->s[1]->sm[i];
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
    PNode ias(int key, bool ios = 0){
		if (!rt){
			if (ios) rt = cre(key);
			return rt;
		}
		PNode y = 0, x = rt;
		while (x && pus(x)->ky != key){
			y = x;
			x = x->s[x->ky < key];
		}
		if (ios){
			if (!x) y->s[y->ky < key] = x = cre(key, y);
			else x->ct++;
		}
		return x? sly(x): x;
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
        return rt? upd(rt): 0;
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

int n;

int main()
{
#if 1
	freopen("test.txt", "r", stdin);
	freopen("test.out", "w", stdout);
#endif
	while (~scanf("%d", &n))
	{
		zkl.ini();
		while (n--)
		{
			char op[10];
			scanf("%s", op);
			if (!strcmp(op, "sum"))
				printf("%lld\n", zkl.rt? zkl.rt->sm[3]: 0);
			else
			{
				int x;
				scanf("%d", &x);
				if (!strcmp(op, "add")) zkl.ias(x, 1);
				if (!strcmp(op, "del")) zkl.del(zkl.ias(x));
			}
			//zkl.tra(zkl.rt);
		}
	}
	return 0;
}
