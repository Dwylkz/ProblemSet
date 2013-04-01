//Head
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
//Dwylkz
namespace Dwylkz{
	//Type
	typedef unsigned int UI;
	typedef long long LL;
	typedef long double LD;
	//Constant
	const LL INFLL = ~0uLL >> 1;
	const int INFI = ~0u >> 1;
	const int MAXN = 70;
	const int MOD = 1e9 + 7;
	//Array
	typedef int AI[MAXN];
	typedef bool AB[MAXN];
	typedef double AD[MAXN];
	typedef LL ALL[MAXN];
	typedef LD ALD[MAXN];
}
using namespace Dwylkz;
//Macro
#define MS(c, a) memset(c, a, sizeof c)
#define Rep(c, a, b) for (int c = a; c < int(b); c++)
#define Nre(c, a, b) for (int c = a; c > int(b); c--)
#define FK puts("Here")
//Global
int n;
AI len;
//DFS
int lim;
AI vis;
int DFS(int l, int r, int s = 1){
	if (!r) return 1;
	if (!l){
		if (DFS(lim, r)) return 1;
		return 0;
	}
	for (int i = s; i <= n; i++)
		if (!vis[i] && l - len[i] >= 0){
			vis[i] = 1;
			if (DFS(l - len[i], r - len[i], i + 1)) return 1;
			vis[i] = 0;
			if (l == lim) return 0;
			for (; i <= n && len[i] == len[i + 1]; i++);
		}
	return 0;
}
//Main
int main(){
#if 1
	freopen("test.txt", "r", stdin);
	//freopen("test.out", "w", stdout);
#endif
	while (scanf("%d", &n), n){
		int sum = lim = 0;
		for (int i = 1; i <= n; i++){
			scanf("%d", len + i);
			sum += len[i];
		}
		sort(len + 1, len + n + 1, greater<int>());
		for (lim = len[1];; lim++) if (sum % lim == 0){
			memset(vis, 0, sizeof(vis));
			if (DFS(lim, sum)) break;
		}
		printf("%d\n", lim);
	}
	return 0;
}
