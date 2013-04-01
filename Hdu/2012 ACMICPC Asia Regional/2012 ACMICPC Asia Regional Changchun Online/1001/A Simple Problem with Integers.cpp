/*
   Intuitively, we can solve this problem by using segment-tree.

   As points we deal with are discrete, we should do some specail judge.
   Notice that k <= 10, so we can build 10 SGT or one SGT
   that every node has an array which store the addition value.

   But, unfortunately, an array with 10 space is not enough.
   For each K, it's K remainder must be considered.
   Thus, we need an 2-dimensional array.

   However, (100 * 50000 * 2) = 10^7 > 2^15 * 2^10 / 4 = 8.388608 * 10^6.

   Hence, we have to encode the array
   because we actually need 10 * (10 + 1) / 2 = 55 int-space.

   55 * 50000 * 2 = 5.5 * 10^6 < 8.88608 * 10^6.

   Then, how to "shift" is the last thing we should deal with.

   Sometimes the query [l, r, h] would be spilted into two part.
   (h as current "shift")

   l ..... m (m + 1) .....r
   |  h    |    |   _h    |

   For the left part we don't need to calculate the "shift".
   For the right one, we can work the _h out with formula below. 

   the remainder in the tail of left + the shift in the head of right = k

   Hence
	_h = (k - (m - (l + h) + 1) % k) % k + m + 1;
	      |   |                   |        |   |
	 	  |   remainder of left   |        current start position
		  |                       |
		  remainder of right
   
   At last, we should reduce the time cost in pushdown by using an array of k-size.
   The complexity of this method is about O(nlogn)-O(logn).
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
const int MAXN = 50005;
const int MOD = 11;
//Array
typedef int AI[MAXN];
typedef bool AB[MAXN];
typedef double AD[MAXN];
typedef LL ALL[MAXN];
typedef LD ALD[MAXN];

inline int PS(int x){
    return x * (x + 1) / 2;
}
inline int CH(int l, int r, int k){
    return (k - (r - l + 1) % k) % k;
}

//SGT
typedef struct Node{
    int l, r,
        s[MOD * (MOD + 1) >> 1], a[MOD];
    Node *ls, *rs;
    int m(){
        return (l + r) >> 1;
    }
    void set(int k, int h, int _a){
        s[PS(k) + h] += _a;
		a[k] = 1;
    }
    void pus(int k){
		if (!a[k]) return ;
        Rep(h, 0, k) if (l + h <= r)
        {
            int i = PS(k) + h;
            if (l + h <= m()) ls->set(k, h, s[i]);
            int _h = CH(l + h, m(), k);
            if (m() + _h < r) rs->set(k, _h, s[i]);
            s[i] = 0;
        }
		a[k] = 0;
    }
} *PNode;
struct SGT{
    Node t[MAXN << 1], *top;
    void bui(int l, int r, PNode x){
        x->l = l; x->r = r;
        MS(x->s, 0); MS(x->a, 0);
        if (l == r) return ;
        int m = x->m();
        if (l <= m) bui(l, m, x->ls = ++top);
        if (m < r) bui(m + 1, r, x->rs = ++top);
    }
    void ins(int l, int r, int k, int h, int a, PNode x){
        if (l <= x->l && x->r <= r) x->set(k, h, a);
        else{
            x->pus(k);
            int m = x->m();
            if (r <= m) ins(l, r, k, h, a, x->ls);
            else if (m < l) ins(l, r, k, h, a, x->rs);
            else{
                if (l + h <= m) ins(l, m, k, h, a, x->ls);
                int _h = CH(l + h, m, k);
                if (m + _h < r) ins(m + 1, r, k, _h, a, x->rs);
            }
        }
    }
    Node que(int k, PNode x){
        if (x->l == x->r) return *x;
        Rep(i, 1, MOD) x->pus(i);
        if (k <= x->m()) return que(k, x->ls);
        return que(k, x->rs);
    }
} zkl;

int n, q;

int main()
{
#if 1
    freopen("test.txt", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    while (~scanf("%d", &n))
    {
        //Initialize
        zkl.bui(1, n, zkl.top = zkl.t);
        Rep(i, 1, n + 1)
        {
            int c;
            scanf("%d", &c);
            zkl.ins(i, i, 1, 0, c, zkl.t);
        }
        //Solve
        scanf("%d", &q);
        while (q--)
        {
            int op, a;
            scanf("%d%d", &op, &a);
            if (op < 2)
            {
                int b, k, c;
                scanf("%d%d%d", &b, &k, &c);
                zkl.ins(a, b, k, 0, c, zkl.t);
            }
            else
            {
                Node x = zkl.que(a, zkl.t);
                int res = 0;
                Rep(k, 1, 11) res += x.s[PS(k)];
                printf("%d\n", res);
            }
        }
    }
    return 0;
}
