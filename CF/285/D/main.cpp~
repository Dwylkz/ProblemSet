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
#define MAXN (17)
#define INFI (0x7fffffff)
#define MOD (1000000007)
//Type-Alias
typedef long long LL;
typedef long double LD;
typedef int AI[MAXN];
typedef double AD[MAXN];
typedef LL ALL[MAXN];
typedef LD ALD[MAXN];

struct DLX
{
#define DLXR (MAXN*2)
#define DLXC (MAXN*3)
#define DF(c, a, b) for (int c = a[b]; c != b; c = a[c])
	typedef int DS[DLXR * DLXC], DR[DLXR], DC[DLXC];
	DS L, R, U, D, O, C;
	DR P;
	DC S;
	int id, cr, rh, ms, lim;
	void ini(int n)
	{
		id = ++n;
		Rep(i, 0, n)
		{
			L[i] = (i - 1 + n) % n;
			R[i] = (i + 1) % n;
			U[i] = D[i] = i;
		}
		MS(S, cr = 0);
		MS(P, 0);
		ms = 0;
	}	
	void ins(int i, int j)
	{
		i++; j++;
		if (cr < i)
		{
			rh = L[id] = R[id] = id;
			cr = i;
		}
		L[id] = L[rh]; R[id] = rh;
		R[L[rh]] = id; L[rh] = id;
		U[id] = U[j]; D[id] = j;
		D[U[j]] = id; U[j] = id;
		S[j]++; O[id] = i; C[id++] = j;
	}
	void erm(int c)
	{
		L[R[c]] = L[c]; R[L[c]] = R[c];
		DF(i, D, c) DF(j, R, i)
			U[D[j]] = U[j], D[U[j]] = D[j], S[C[j]]--;
	}
	void ers(int c)
	{
		L[R[c]] = c; R[L[c]] = c;
		DF(i, D, c) DF(j, R, i)
			U[D[j]] = j, D[U[j]] = j, S[C[j]]++;
	}
	bool edf(int sp)
	{
		if (lim < R[0]) {
			ms++;
			return 1;
		}
		int x = R[0];
		DF(i, R, 0) if (S[i] < S[x]) x = i;
		erm(x);
		DF(i, D, x)
		{
			P[O[i]] = 1;
			DF(j, R, i) erm(C[j]);
			edf(sp + 1);
			DF(j, L, i) ers(C[j]); //L
			P[O[i]] = 0;
		}
		ers(x);
		return 0;
	}
};


DLX zkl;
int n, m[MAXN][MAXN];
LL mul;

int main()
{
#if 1
	freopen("input.in", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	while (~scanf("%d", &n)) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				m[i][j] = (i + j) % n;
			}
		}
		mul = 1;
		for (int i = 1; i <= n; i++) {
			mul = mul * i % MOD;
		}
#if 1
		printf("%lld\n", mul);
		Rep(i, 0, n) {
			Rep(j, 0, n) {
				printf("%4d", m[i][j]);
			}
			puts("");
		}
#endif
		zkl.ini(3 * n);
		zkl.lim = 2 * n;
		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (m[i][j] == k) {
#if 0
						printf("%d + %d = %d\n", i, j, k);
#endif
						zkl.ins(k, i);
						zkl.ins(k, n + j);
						zkl.ins(k, n + n + k);
					}
				}
			}
		}
		zkl.edf(0);
		mul = zkl.ms % MOD;
		printf("%lld\n", mul);
	}
	return 0;
}
