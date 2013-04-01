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
	const int MAXN = 505;
	const int MOD = 1e9 + 7;
	//Array
	typedef int AI[MAXN];
	typedef bool AB[MAXN];
	typedef double AD[MAXN];
	typedef LL ALL[MAXN];
	typedef LD ALD[MAXN];
	typedef vector<int> VI;
}
using namespace Dwylkz;
//Macro
#define MS(c, a) memset(c, a, sizeof c)
#define Rep(c, a, b) for (int c = a; c < int(b); c++)
#define Nre(c, a, b) for (int c = a; c > int(b); c--)
#define FK puts("Here")
//Global
int n, k;
vector<VI> r;
map<int, bool> H;
map<LL, bool> Ha;
AI a;
//Add
void DFS(VI t = VI(0), int i = 0, int s = 0){
	if (!H[s]){
		H[s] = 1;
		r.push_back(t);
	}
	int hk = s * 8000000005LL + i;
	if (Ha[hk]) return ;
	Ha[hk] = 1;
	if (k < r.size()) return ;
	if (i == n) return ;
	DFS(t, i + 1, s);
	t.push_back(a[i]);
	DFS(t, i + 1, s + a[i]);
}
//Main
int main(){
#if 0
	freopen("test.txt", "r", stdin);
	//freopen("test.out", "w", stdout);
#endif
	while (~scanf("%d%d", &n, &k)){
		for(int i = 0; i < n; i++) scanf("%d", a + i);
		r.clear();
		H.clear();
		Ha.clear();
		DFS();
		for (int i = 1; i <= k; i++){
			printf("%d", r[i].size());
			for (int j = 0; j < r[i].size(); j++)
				printf(" %d", r[i][j]);
			puts("");
		}
	}
	return 0;
}
