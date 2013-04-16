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
	  maxn = 5e4 + 10;
const long long inf64 = 0x7fffffffffffffffLL; 
//structure
//type definition
typedef long long LL;
//global variable
//access and mutator
char a[maxn], b[maxn];
//main
int main() {
#if 1
	freopen(input, "r", stdin);
	//freopen(output, "w", stdout);
#endif
	int T;
	while (~scanf("%d", &T)) {
		for (int Case = 1; Case <= T; Case++) {
			scanf("%s%s", a, b);
			int la = strlen(a), lb = strlen(b), res = lb;
			for (int i = 0; i <= la - lb; i++) {
				int diff = 0;
				for (int j = 0; j < lb; j++) {
					diff += (a[i + j] != b[j]);
					if (res <= diff) {
						break;
					}
				}
				if (diff < res) {
					res = diff;
				}
			}
			printf("Case #%d: %d\n", Case, res);
		}
	}
	return 0;
}
