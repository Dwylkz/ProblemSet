//coder: SXDwylkz
//heads
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cctype>
#include <algorithm>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <cstring>
#include <cmath>
//namespaces
using namespace std;
//constants
const char input[] = "input.in",
	  output[] = "output.out";
const int inf32 = 0x7fffffff,
	  maxn = 1e5 + 10;
const long long inf64 = 0x7fffffffffffffffLL; 
const int mod = 1e9 + 9;
//structure
//type definition
typedef long long LL;
//global variable
int n, m;
LL p[maxn];
//access and mutator
//main
int main() {
#if 1
	freopen(input, "r", stdin);
	//freopen(output, "w", stdout);
#endif
	p[0] = 1;
	for (int i = 1; i < maxn; i++) {
		p[i] = (p[i - 1] * 2) % mod;
	}
#if 0
	for (int i = 0; i < 10; i++) {
		printf("%lld", p[i]);
	}
	puts("");
#endif
	while (~scanf("%d%d", &n, &m)) {
		LL res = 1;
		for (int i = 0; i < m; i++) {
			res = (res * p[n - 1]) % mod;
#if 0
			printf("%lld\n", res);
#endif
		}
		printf("%lld\n", res);
	}
	return 0;
}
