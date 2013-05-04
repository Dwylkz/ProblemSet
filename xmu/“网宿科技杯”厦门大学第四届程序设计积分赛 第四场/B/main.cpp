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
	  maxn = 1024;
const long long inf64 = 0x7fffffffffffffffLL; 
//type definition
typedef int AB[maxn];
typedef int AI[maxn];
typedef char AC[maxn];
typedef long long LL;
//Extern
int n, m, sg[maxn][maxn];
//main
int main() {
#if 1
	freopen(input, "r", stdin);
	//freopen(output, "w", stdout);
#endif
	for (int i = 1; i < maxn; i++) {
		sg[i][1] = sg[1][i] = 1;
	}
	sg[1][1] = 0;
	for (int i = 2; i < maxn; i++) {
		for (int j = 2; j < maxn; j++) {
			if (i == j) {
				sg[i][j] = 1;
			} else {
				sg[i][j] = ~sg[i - 1][j - 1];
			}
		}
	}
#if 1
	puts("sg:");
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			printf("%6d", sg[i][j]);
		}
		puts("");
	}
#endif
	while (~scanf("%d%d", &n, &m)) {
		puts(sg[n][m]? "Alice": "Bob");
	}
	return 0;
}
