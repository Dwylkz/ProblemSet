#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>
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
const LL INFL = ~0ull >> 1;
const int INFI = ~0u >> 1;
const int MAXN = 400005;
const int MOD = 1 - 'a';
//Array
typedef int AI[MAXN];
typedef bool AB[MAXN];
typedef double AD[MAXN];
typedef LL ALL[MAXN];
typedef LD ALD[MAXN];

struct SA{
    AI ws, wa, wb, wv, sa, wd, rank, height;
    void ini(int *r, int l, int m){
        da(r, l, m); calHeight(r, l - 1);
    }
    int cmp(int *r, int a, int b, int l){
        return r[a] == r[b] && r[a + l] == r[b + l];
    }
    void da(int *r, int n, int m){
		int i, j, p, *x = wa, *y = wb, *t;
		for (i = 0; i < m; i++) wd[i] = 0;
		for (i = 0; i < n; i++) wd[x[i] = r[i]]++;
		for (i = 1; i < m; i++) wd[i] += wd[i - 1];
		for (i = n - 1; i >= 0; i--) sa[--wd[x[i]]] = i;
		for (j = 1, p = 1; p < n; j <<= 1, m = p){
			for (p = 0, i = n - j; i < n; i++) y[p++] = i;
			for (i = 0; i < n; i++) if (sa[i] >= j) y[p++] = sa[i] - j;
			for (i = 0; i < n; i++) wv[i] = x[y[i]];
			for (i = 0; i < m; i++) wd[i] = 0;
			for (i = 0; i < n; i++) wd[wv[i]]++;
			for (i = 1; i < m; i++) wd[i] += wd[i - 1];
			for (i = n - 1; i >= 0; i--) sa[--wd[wv[i]]] = y[i];
			for (t = x, x = y, y = t, p = 1, x[sa[0]] = 0, i = 1; i < n; i++)
				x[sa[i]] = cmp(y, sa[i - 1], sa[i], j)? p - 1: p++;
		}
    }
    void calHeight(int *r, int n){
        int i, j, k = 0;
        for (i = 1; i <= n; i++) rank[sa[i]] = i;
        for (i = 0; i < n; height[rank[i++]] = k)
            for (k? k--: 0, j = sa[rank[i] - 1]; r[i + k] == r[j + k]; k++);
    }
} zkl;
struct MNS{
	AI s;
	int top;
	void ini(){
		top = 0;
	}
	void pus(int x){
		for (; top && s[top - 1] >= x; top--);
		s[top++] =  x;
	}
	int pop(){
		return s[top - 1];
	}
} mns;

char buf[MAXN];
AI str, mx;
int n, len, la, lb, gap;
LL ct;

void solve()
{
	int tm = 0;
	MS(mx, 0);
	mns.ini();
	Rep(i, 1, len)
	{
		mns.pus(zkl.height[i]);
		if (!mns.pop()) tm = 0;
		if (zkl.sa[i - 1] >= la) tm = max(tm, mns.pop());
		if (zkl.sa[i] < la) mx[zkl.sa[i]] = min(tm, mns.pop());
	}
	mns.ini();
	tm = 0;
	Nre(i, len - 2, -1)
	{
		mns.pus(zkl.height[i + 1]);
		if (!mns.pop()) tm = 0;
		if (zkl.sa[i + 1] >= la) tm = max(tm, mns.pop());
		if (zkl.sa[i] < la) mx[zkl.sa[i]] = max(mx[zkl.sa[i]], min(tm, mns.pop()));
	}
	int pi = -1;
	ct = 0;
	mns.ini();
	Rep(i, 0, len)
	{
		mns.pus(zkl.height[i]);
		int id = zkl.sa[i];
		if (id < la)
		{
			int td = la - id - mx[id];
			if (pi != -1) ct += td - max(0, mns.pop() - mx[pi]);
			else ct += td;
			pi = id;
		}
	}
#if 0
	printf("mx:");
	Rep(i, 0, la) printf(" %3d", mx[i]);
	puts("");
#endif
}

int main()
{
#if 1
	freopen("test.txt", "r", stdin);
	freopen("test.out", "w", stdout);
#endif
	int T, Cas = 1;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		scanf("%s", buf);
		la = lb = strlen(buf);
		len = 0; gap = 'z' + 1;
		Rep(i, 0, lb) str[len++] = buf[i];
		str[len++] = gap++;
		while (n--)
		{
			scanf("%s", buf);
			lb = strlen(buf);
			Rep(i, 0, lb) str[len++] = buf[i];
			str[len++] = gap;
		}
		str[len++] = 0;
		zkl.ini(str, len, ++gap);
		solve();
		printf("Case %d: %lld\n", Cas++, ct);
#if 0
		Rep(i, 0, len)
		{
			printf(" %4d %4d : ", zkl.sa[i], zkl.height[i]);
			Rep(j, zkl.sa[i], len)
				printf("%c", str[j]);
			puts("");
		}
#endif
	}
	return 0;
}
