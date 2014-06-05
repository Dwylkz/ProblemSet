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
#define MAXN (550)
#define MAXB (990)
#define INFI (0x7fffffff)
//Type-Alias
typedef long long LL;
typedef long double LD;
typedef int AI[MAXN];
typedef double AD[MAXN];
typedef LL ALL[MAXN];
typedef LD ALD[MAXN];

struct DLX
{
#define DF(c, a, b) for (int c = a[b]; c != b; c = a[c])
	typedef int DI[MAXB * MAXN];
	DI L, R, U, D, C, S, H;
	int id, cr, rh, ms;
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
		ms = INFI;
	}	
	void ins(int i, int j)
	{
		if (cr < i)
		{
			rh = L[id] = R[id] = id;
			cr++;
		}
		L[id] = L[rh]; R[id] = rh;
		R[L[rh]] = id; L[rh] = id;
		U[id] = U[j]; D[id] = j;
		D[U[j]] = id; U[j] = id;
		S[j]++; C[id++] = j;
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
		if (!R[0])
		{
			ms = min(ms, sp);
			return 1;
		}
		int x = R[0];
		DF(i, R, 0) if (S[i] < S[x]) x = i;
		erm(x);
		DF(i, D, x)
		{
			DF(j, R, i) erm(C[j]);
			edf(sp + 1);
			DF(j, L, i) ers(C[j]);
		}
		ers(x);
		return 0;
	}
} dlx;

int n, m, p;

int main()
{
#if 1
	freopen("test.txt", "r", stdin);
#endif
	int T, Cas = 1;
	scanf("%d", &T);
	while (T--)
	{
		//Initialize
		scanf("%d%d%d", &n, &m, &p);
		dlx.ini(n * m);
		Rep(i, 1, p + 1)
		{
			int xl, yl, xu, yu; 
			scanf("%d%d%d%d", &xl, &yl, &xu, &yu);
			Rep(x, xl, xu) Rep(y, yl, yu)
				dlx.ins(i, x * m + y + 1);
		}
		//Solve
		dlx.edf(0);
		printf((dlx.ms == INFI)? "-1\n": "%d\n", dlx.ms);
	}
	return 0;
}
