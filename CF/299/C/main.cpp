#include <cstdlib>
#include <vector>
#include <cstdio>
#include <cctype>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 2e5 + 10;
const int mod = 1e9 + 7;
typedef long long LL;
struct DA {
	int t[maxn];
	void Init() {
		t[0] = 1;
	}
	void Push(int x) {
		t[t[0]++] = x;
	}
	void Build() {
		sort(t + 1, t + t[0]);
		t[0] = unique(t + 1, t + t[0]) - t;
	}
	int Size() {
		return t[0] - 1;
	}
	int operator [] (int x) {
		return t[x + 1];
	}
	int Ask(int x) {
		int l = 1, r = t[0] - 1;
		while (l < r) {
			int m = l + r >> 1;
			if (x <= t[m]) {
				r = m;
			} else {
				l = m + 1;
			}
		}
		return l - 1;
	}
};
DA da;
int n, m, k, N[maxn], M[maxn], cn[maxn], cm[maxn],
	r[maxn], rn[maxn], rm[maxn];
int main()
{
#if 1
	freopen("input.txt", "r", stdin);
#endif
	while (~scanf("%d%d%d", &n, &m, &k)) {
		da.Init();
		for (int i = 0; i < n; i++) {
			scanf("%d", N + i);
			da.Push(N[i]);
		}
		for (int i = 0; i < m; i++) {
			scanf("%d", M + i);
			da.Push(M[i]);
		}
		da.Build();
		memset(cn, 0, sizeof(cn));
		memset(cm, 0, sizeof(cm));
		for (int i = 0; i < n; i++) {
			cn[da.Ask(N[i])]++;
		}
		for (int i = 0; i < m; i++) {
			cm[da.Ask(M[i])]++;
		}
#if 0 
		printf("N: ");
		for (int i = 0; i < da.t[0] - 1; i++) {
			printf("%5d", cn[i]);
		}
		puts("");
		printf("M: ");
		for (int i = 0; i < da.t[0] - 1; i++) {
			printf("%5d", cm[i]);
		}
		puts("");
#endif
		memset(rn, 0, sizeof(rn));
		memset(rm, 0, sizeof(rm));
		int rank = 0;
		for (int i = 0; i < da.Size(); i++) {
			if (cn[i]) { 
				rank++;
			}
			r[i] = rank;
		}
		for (int i = 0; i < da.Size(); i++) {
			rn[r[i]] += cn[i];
		}
		for (int i = 0; i < da.Size(); i++) {
			rm[r[i]] += cm[i];
		}
#if 0
		printf("N: ");
		for (int i = 0; i < da.t[0] - 1; i++) {
			printf("%5d", rn[i]);
		}
		puts("");
		printf("M: ");
		for (int i = 0; i < da.t[0] - 1; i++) {
			printf("%5d", rm[i]);
		}
		puts("");
#endif
		int cmp = 0;
		for (int i = da.Size() - 1; 0 <= i; i--) {
			if (rn[i] > rm[i]) {
				cmp = 1;
				break;
			} else if (rn[i] < rm[i]) {
				cmp = 0;
				break;
			}
		}
		puts(cmp == 1? "YES": "NO");
	}
	return 0;
}
