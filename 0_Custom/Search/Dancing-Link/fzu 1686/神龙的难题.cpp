//HeadFile
#if 1
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
#endif
//Macro
#if 1
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
#define MOD()
#define MAXN (250)
#define INFI (0x7fffffff)
//Type-Alias
typedef long long LL;
typedef long double LD;
typedef int AI[MAXN];
typedef bool AB[MAXN];
typedef double AD[MAXN];
typedef LL ALL[MAXN];
typedef LD ALD[MAXN];
#endif

//DLX
struct DLX
{
#define DF(c, a, b) for (int c = a[b]; c != b; c = a[c])
	typedef int DI[MAXN * MAXN];
	DI L, R, U, D, O, C;
	AI S;
	AB H, P;
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
			cr = i;
		}
		L[id] = L[rh]; R[id] = rh;
		R[L[rh]] = id; L[rh] = id;
		U[id] = U[j]; D[id] = j;
		D[U[j]] = id; U[j] = id;
		S[j]++; O[id] = i; C[id++] = j;
	}
	void rrm(int c)
	{
		DF(i, D, c) L[R[i]] = L[i], R[L[i]] = R[i];
	}
	void rrs(int c)
	{
		DF(i, D, c) L[R[i]] = i, R[L[i]] = i;
	}
	int hfu()
	{
		int h = 0;
		MS(H, 0);
		DF(c, R, 0) if (!H[c])
		{
			H[c] = 1;
			h++;
			DF(i, D, c) DF(j, R, i) H[C[j]] = 1;
		}
		return h;
	}
	bool rdf(int sp)
	{
		if (sp + hfu() >= ms) return 0;
		if (!R[0])
		{
			ms = min(ms, sp);
			return 1;
		}
		int x = R[0];
		DF(i, R, 0) if (S[i] < S[x]) x = i;
		DF(i, D, x)
		{
			rrm(i);
			DF(j, R, i) rrm(j);
			if (rdf(sp + 1)) return 1;
			DF(j, L, i) rrs(j);
			rrs(i);
		}
		return 0;
	}
	int rec()
	{
		ms = hfu();
		while (!rdf(0)) ms++;
		return ms;
	}
} dlx;

int n, m, n1, m1,
	dt[4][2] = {{1, 1}, {1, -1}, {-1, -1}, {-1, 1}};
AI K[MAXN];

int main()
{
#if 1
	freopen("test.txt", "r", stdin);
#endif
	while (~scanf("%d%d", &n, &m))
	{
		//Initialize
		int id = 0;
		Rep(i, 0, n) Rep(j, 0, m)
		{
			scanf("%d", K[i] + j);
			if (K[i][j]) K[i][j] = ++id;
		}			
		scanf("%d%d", &n1, &m1);
		dlx.ini(id);
		id = 0;
		Rep(i, 0, n - n1 + 1) Rep(j, 0, m - m1 + 1)
		{
			id++;
			Rep(r, i, i + n1) Rep(c, j, j + m1)
				if (K[r][c]) dlx.ins(id, K[r][c]);
		}
		//Solve
		printf("%d\n", dlx.rec());
	}
	return 0;
}
