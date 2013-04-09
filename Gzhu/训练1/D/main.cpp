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
	  maxn = 1e6 + 10;
const long long inf64 = 0x7fffffffffffffffLL; 
//structure
//type definition
typedef long long LL;
//global variable
int n, a, b, k;
//access and mutator
int p[maxn];
void Sieve() {
	p[0] = p[1] = 0;
	fill(p + 2, p + maxn, 1);
	for (int i = 4; i < maxn; i += 2) {
		p[i] = 0;
	}
	for (int i = 3; i < maxn; i += 2) {
		if (p[i]) {
			for (int j = i + i; j < maxn; j += i) {
				p[j] = 0;
			}
		}
	}
	for (int i = 1; i < maxn; i++) {
		p[i] += p[i - 1];
	}
#if 0
	for (int i = 0; i < 10; i++) {
		printf("%5d", p[i]);
	}
	puts("");
#endif
}
//main
int main() {
#if 1
	freopen(input, "r", stdin);
	//freopen(output, "w", stdout);
#endif
	Sieve();
	while (~scanf("%d%d%d", &a, &b, &k)) {
		int res = -1, l = 1, r = b - a + 1;
		while (l <= r) {
			int m = l + r >> 1;
			bool ac = 1;
			for (int x = a; x <= b - m + 1; x++) {
				if (p[x + m - 1] - p[x - 1] < k) {
					ac = 0;
					break;
				}
			}
			if (ac) {
				res = m;
				r = m - 1;
			} else {
				l = m + 1;
			}
		}
		printf("%d\n", res);
	}
	return 0;
}
