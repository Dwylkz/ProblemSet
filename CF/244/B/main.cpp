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
map<LL, bool> H;
int n;
vector<int> T;
//DFS
void DFS(int x, int y, LL t = 0, int l = 0, LL _t = 0){
	if (l > 9) return ;
	H[_t = t * 10 + x] = 1;
	DFS(x, y, _t, l + 1);
	H[_t = t * 10 + y] = 1;
	DFS(x, y, _t, l + 1);
}
//Main
int main(){
#if 0
	freopen("test.txt", "r", stdin);
#endif
	H.clear();
	for (int x = 0; x < 10; x++)
		for (int y = x + 1; y < 10; y++) 
			DFS(x, y);
	T.clear();
	for (map<LL, bool>::iterator i = H.begin(); i != H.end(); i++)
		T.push_back(i->first);
	while (~scanf("%d", &n)){
		int l = 0, r = T.size() - 1, res = -1;
		while (l <= r){
			int m = l + r >> 1;
			if (T[m] <= n){
				l = m + 1;
				res = m;
			}
			else r = m - 1;
		}
		printf("%d\n", res);
	}
	return 0;
}
