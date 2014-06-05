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
int n, d;
AI a;
ALL s, s2;
//Main
int main(){
#if 1
	freopen("test.txt", "r", stdin);
	//freopen("test.out", "w", stdout);
#endif
	s[0] = s2[0] = 0;
	Rep(i, 1, MAXN){
		s[i] = s[i - 1] + i;
		s2[i] = s2[i - 1] + 1LL * i * i;
		if (s[i] < s[i - 1] || s2[i] < s2[i - 1]) puts("fuck");
	}
	while (~scanf("%d%d", &n, &d)){
		n++;
		Rep(i, 1, n) scanf("%d", a + i);
		LL res = 0, l = 1, r = 1;
		while (r < n){
			while (r < n && a[r] <= a[l] + d) r++;
			r--;
			LL h = 1, o = h+r-l;
			res += (h+o)*(s[o-1]-s[h])-(s2[o-1]-s2[h])-h*o*(o-1-h);
			l++, r++;
		}
		printf("%lld\n", res);
	}
	return 0;
}
