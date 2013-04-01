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
	const double EPS = 1e-8;
	const LL INFLL = ~0uLL >> 1;
	const int INFI = ~0u >> 1;
	const int MAXN = 1e5 + 5;
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
char buf[MAXN];
//Main
int main(){
#if 0
	freopen("test.txt", "r", stdin);
	//freopen("test.out", "w", stdout);
#endif
	while (~scanf("%s", buf)) {
		int l = strlen(buf), p = -1;
		Rep(i, 0, l) {
			if (buf[i] == '0') {
				p = i;
				break;
			}
		} 
		if (l > 1 && p == -1) p = l - 1;
		Rep(i, 0, l) {
			if (i != p) putchar(buf[i]);
		}
		puts("");
	}
	return 0;
}
