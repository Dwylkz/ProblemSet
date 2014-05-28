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
#define MAXN (10)
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
#define DLXR (MAXN * MAXN * MAXN)
#define DLXC (MAXN * MAXN * 4)
#define DF(c, a, b) for (int c = a[b]; c != b; c = a[c])
	typedef int DS[DLXR * DLXC], DR[DLXR], DC[DLXC];
	DS L, R, U, D, O, C;
	DR P;
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
		if (!R[0]) return 1;
		int x = R[0];
		DF(i, R, 0) if (S[i] < S[x]) x = i;
		erm(x);
		DF(i, D, x)
		{
			P[O[i]] = 1;
			DF(j, R, i) erm(C[j]);
			if (edf(sp + 1)) return 1;
			DF(j, L, i) ers(C[j]); //L
			P[O[i]] = 0;
		}
		ers(x);
		return 0;
	}
} dlx;

char B[MAXN * MAXN];

int main()
{
#if 1
	freopen("test.txt", "r", stdin);
#endif
	while (scanf("%s", B), strcmp(B, "end"))
	{
		//Initialize
		dlx.ini(324);
		Rep(p, 0, 81)
		{
			int h = 0, o = B[p] - '0',
				r = p / 9, c = p % 9;
			if (B[p] == '.') o = 9;
			else h = o - 1;
			Rep(i, h, o)
			{
				int u = p * 9 + i;
				dlx.ins(u, r * 9 + i);
				dlx.ins(u, c * 9 + i + 81);
				dlx.ins(u, ((r / 3) * 3 + (c / 3)) * 9 + i + 162);
				dlx.ins(u, p + 243);
			}
		}
		//Solve
		dlx.edf(0);
		Rep(i, 0, 729) if (dlx.P[i + 1])
			printf("%d", i % 9 + 1);
		puts("");
	}
	return 0;
}
