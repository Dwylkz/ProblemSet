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
//structure
//type definition
typedef long long LL;
//global variable
int n, k;
//access and mutator
//main
int main() {
#if 1
	freopen(input, "r", stdin);
	//freopen(output, "w", stdout);
#endif
	while (~scanf("%d%d", &n, &k)) {
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			char b[101];
			scanf("%s", b);
			int lucky = 0;
			for (int j = 0, l = strlen(b); j < l; j++) {
				if (b[j] == '4' || b[j] == '7') {
					lucky++;
				}
			}
			if (lucky <= k) {
				cnt++;
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}
