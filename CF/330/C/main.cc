#include <cstdlib>
#include <vector>
#include <map>
#include <cstdio>
#include <cctype>
#include <string.h>
#include <string>
#include <iostream>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < (b); c++)
#define MS(c, a) memset((c), (a), sizeof(c))
const int MAXN = 1e2 + 10;
const int INFI = 0x7fffffff;

//DLX
struct DLX
{
#define DLXR (MAXN * MAXN)
#define DLXC (MAXN + MAXN)
#define DF(c, a, b) for (int c = a[b]; c != b; c = a[c])
	typedef int DS[DLXR * DLXC], DR[DLXR], DC[DLXC];
	DS L, R, U, D, C, RN;
  DR A, TA;
	DC S;
  int CC;
	int id, cr, rh, ms;
	void ini(int n)
	{
    CC = n / 2;
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
		S[j]++; RN[id] = cr; C[id++] = j;
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
		if (!R[0] || R[0] > CC + 1 || L[0] <= CC + 1)
		{
      ms = min(ms, sp);
      memcpy(A, TA, sizeof(TA));
      return 1;
		}
		int x = R[0];
		DF(i, R, 0) if (S[i] < S[x]) x = i;
		DF(i, D, x)
		{
      TA[RN[i]] = 1;
#if 1
      printf("%d choose %d %d\n", sp, 1 + (RN[i] - 1) / 5, 1 + (RN[i] - 1) % 5);
#endif
			rrm(i);
			DF(j, R, i) rrm(j);
			if (rdf(sp + 1)) return 1;
			DF(j, L, i) rrs(j);
			rrs(i);
      TA[RN[i]] = 0;
		}
		return 0;
	}
	int rec()
	{
		ms = hfu();
#if 1
    printf("init = %d\n", ms);
#endif
    MS(A, 0);
    MS(TA, 0);
		while (!rdf(0)) {
#if 1
      printf("fail\n");
#endif
      ms++;
      MS(TA, 0);
    }
		return ms;
	}
} dlx;

int n, f[MAXN + MAXN];
char g[MAXN][MAXN];

int main()
{
#if 1
	freopen("input.txt", "r", stdin);
#endif
  for ( ; ~scanf("%d", &n); ) {
    for (int i = 0; i < n; i++) {
      scanf("%s", g + i);
    }
    MS(f, 0);
    dlx.ini(n + n);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (g[i][j] == '.') {
          dlx.ins(i * n + j, i);
          dlx.ins(i * n + j, n + j);
          f[i] = f[n + j] = 1;
        }
      }
    }
    int flag = 1;
    for (int i = 0; i < n + n; i++) {
      if (!f[i]) {
        flag = 0;
        break;
      }
    }
    if (!flag) {
      puts("-1");
      continue;
    }
#if 1
    printf("%d\n", dlx.rec());
#else
    dlx.rec();
#endif
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (dlx.A[i * n + j + 1]) {
          printf("%d %d\n", i + 1, j + 1);
        }
      }
    }
  }
	return 0;
}
