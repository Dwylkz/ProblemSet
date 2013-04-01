#if 1 //Header
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
#if 1 //Macro
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
#define INFI (0x7fffffff)
#define MOD ()
#define MAXN (550)
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
#define DLXR (MAXN << 1)
#define DLXC (MAXN)
#define DF(c, a, b) for (int c = a[b]; c != b; c = a[c])
	typedef int DS[DLXR * DLXC], DR[DLXR], DC[DLXC];
	DS L, R, U, D, O, C;
	DR P, B;
	DC S;
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
		MS(P, 0);
		MS(B, 0);
		ms = INFI;
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
	void rrm(int c)
	{
		DF(i, D, c) L[R[i]] = L[i], R[L[i]] = R[i];
	}
	void rrs(int c)
	{
		DF(i, D, c) L[R[i]] = i, R[L[i]] = i;
	}
	bool rdf(int sp)
	{
		if (!R[0]) return 1;
		int x = R[0];
		DF(i, R, 0) if (S[i] < S[x]) x = i;
		DF(i, D, x) if (!B[O[i]])
		{
			if (O[i] & 1) B[O[i] + 1] = 1;
			else B[O[i] - 1] = 1;
			P[O[i]] = 1;
			rrm(i);
			DF(j, R, i) rrm(j);
			if (rdf(sp + 1)) return 1;
			DF(j, L, i) rrs(j);
			rrs(i);
			P[O[i]] = 0;
			if (O[i] & 1) B[O[i] + 1] = 0;
			else B[O[i] - 1] = 0;
		}
		return 0;
	}
} dlx;

int N, M;
AB swh[MAXN << 1];

int main()
{
#if 1
	freopen("test.txt", "r", stdin);
#endif
	while (~scanf("%d%d", &N, &M))
	{
		//Initialize
		MS(swh, 0);
		Rep(i, 0, N)
		{
			int K;
			scanf("%d", &K);
			while (K--)
			{
				int s;
				char buf[10];
				scanf("%d%s", &s, buf);
				s--;
				if (!strcmp(buf, "ON")) swh[s << 1][i] = 1;
				else swh[s << 1 | 1][i] = 1;
			}
		}
		dlx.ini(N);
		Rep(i, 0, M * 2) Rep(j, 0, N)
			if (swh[i][j]) dlx.ins(i, j);
		//Solve
		if (!dlx.rdf(0)) puts("-1");
		else
		{
			bool beg = 0;
			Rep(i, 0, M)
			{
				if (beg) putchar(' ');
				else beg = 1;
				printf(dlx.P[(i << 1) + 1]? "ON": "OFF");
			}
			puts("");
		}
	}
	return 0;
}
