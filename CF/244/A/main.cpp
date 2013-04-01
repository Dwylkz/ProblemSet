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
	const int MAXN = 1e7;
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
int n, k;
AI o;
vector<int> c[MAXN];
//Main
int main(){
#if 0
	freopen("test.txt", "r", stdin);
#endif
	while (~scanf("%d%d", &n, &k)){
		memset(o, 0, sizeof o);
		for (int i = 0, a; i < k; i++){
			c[i].clear();
			scanf("%d", &a);
			o[a - 1] = 1;
			c[i].push_back(a);
		}
		for (int i = 0, j = 0; i < n * k; i++){
			if (o[i]) continue;
			o[i] = 1;
			if (c[j].size() >= n) j++;
			c[j].push_back(i + 1);
		}
		for (int i = 0; i < k; i++){
			printf("%d", c[i][0]);
			for (int j = 1; j < n; j++)
				printf(" %d", c[i][j]);
			puts("");
		}
	}
	return 0;
}
