#include <cassert>
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
namespace Dwylkz{
    //Type
    typedef unsigned int UI;
    typedef long long LL;
    typedef long double LD;
    //Constant
    const LL INFL = ~0ull >> 1;
    const int INFI = ~0u >> 1;
    const int MAXN = 100005;
    const int MOD = 1e9 + 7;
    //Array
    typedef int AI[MAXN];
    typedef bool AB[MAXN];
    typedef double AD[MAXN];
    typedef LL ALL[MAXN];
    typedef LD ALD[MAXN];
}
using namespace Dwylkz;
//STL
#define MS(c, a) memset(c, a, sizeof c)
//Syntax
#define Rep(c, a, b) for (int c = (a); c < (b); c++)
#define Nre(c, a, b) for (int c = (a); c > (b); c--)
//DEBUG
#define FK puts("Fu*k here!")

//Blocky_Hash
struct BH{
    typedef int KT;
    struct BK{
        KT c;
        map<KT, int> S;
    };
	vector<BK> B;
    int sz, n;
    KT *A;
    void ini(KT *_A, int _n){
        for (A = _A, n = _n; sz * sz < n; sz++);
        B.resize(sz); Rep(i, 0, sz) upd(i);
    }
    void pus(int b){
        if (B[b].c < 0) return ;
        int L = b * sz, R = min(n, L + sz);
        Rep(i, L, R) A[i] = B[b].c;
		B[b].S.clear();
		B[b].S[B[b].c] = sz;
		B[b].c = -1;
    }
    void upd(int b){
        int L = b * sz, R = min(n, L + sz);
        B[b].S.clear(); B[b].c = -1;
		Rep(i, L, R) B[b].S[A[i]]++;
    }
    void ins(int c, int l, int r){
        int lb = l / sz, rb = r / sz, res = 0,
			L = rb * sz, R = min(r + 1, lb * sz + sz);
		pus(lb); Rep(i, l, R) A[i] = c; upd(lb);
		if (lb == rb) return ;
		pus(rb); Rep(i, L, r + 1) A[i] = c; upd(rb);
		Rep(i, lb + 1, rb) B[i].c = c;
    }
    int que(int c, int l, int r){
        int lb = l / sz, rb = r / sz, res = 0,
			L = rb * sz, R = min(r + 1, lb * sz + sz);
		pus(lb); Rep(i, l, R) res += A[i] == c;
		if (lb == rb) return res;
		pus(rb); Rep(i, L, r + 1) res += A[i] == c;
		Rep(i, lb + 1, rb) if (B[i].c < 0){
			if (B[i].S.find(c) != B[i].S.end()) res += B[i].S[c];
		}
		else res += (B[i].c == c) * sz;
        return res;
    }
};

BH zkl;
int n, q;
AI A;

int main()
{
#if 1
    freopen("test.txt", "r", stdin);
    //freopen("test.out", "w", stdout);
#endif
    while (~scanf("%d%d", &n, &q))
    {
        Rep(i, 0, n) scanf("%d", A + i);
        zkl.ini(A, n);
        while (q--){
            int op, l, r, c;
            scanf("%d%d%d%d", &op, &l, &r, &c);
            if (op < 2) zkl.ins(c, l, r);
            else printf("%d\n", zkl.que(c, l, r));
        }
    }
    return 0;
}

