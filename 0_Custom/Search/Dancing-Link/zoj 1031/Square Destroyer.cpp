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
#define MAXN (6)
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
#define DLXR (2 * MAXN * (MAXN + 1))
#define DLXC (MAXN * (MAXN + 1) * (2 * MAXN + 1)/ 6)
#define DF(c, a, b) for (int c = a[b]; c != b; c = a[c])
	typedef int DS[DLXR * DLXC], DR[DLXR], DC[DLXC];
	DS L, R, U, D, C;
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
		S[j]++; C[id++] = j;
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
		DC H = {0};
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

int n, k, con[DLXR][DLXC], col[DLXC];

int main()
{
#if 1
	freopen("test.txt", "r", stdin);
#endif
	int T;
	scanf("%d", &T);
	while (T--)
	{
		//Initialize
		scanf("%d%d", &n, &k);
		MS(con, 0);
		MS(col, 0);
		int id = 0;
		Rep(l, 1, n + 1) Rep(i, 0, n - l + 1) Rep(j, 0, n - l + 1)
		{
			int r = i * (2 * n + 1) + j, c = r + n;
			Rep(d, 0, l)
			{
				int lr = r + d, lc = c + d * (2 * n + 1),
					rr = lr + l * (2 * n + 1), rc = lc + l;
				con[lr][id] = con[lc][id] = con[rr][id] = con[rc][id] = 1;
			}
			id++;
		}
		int row = 2 * n * (n + 1);
		while (k--)
		{
			int d;
			scanf("%d", &d);
			d--;
			Rep(j, 0, id) if (con[d][j])
			{	
				col[j] = 1;
				Rep(i, 0, row) con[i][j] = 0;
			}
		}
		int rk = 0;
		Rep(i, 0, id) if (!col[i]) col[i] = rk++;
		dlx.ini(rk);
		Rep(i, 0, row) Rep(j, 0, id) if (con[i][j])	dlx.ins(i, col[j]);
		//Solve
		printf("%d\n", dlx.rec());
	}
	return 0;
}
