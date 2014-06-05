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
enum wdl{lose, drawn, win};
int n, ca, cb, g[11][11][11];
//access and mutator
void GInit() {
	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < 11; j++) {
			g[0][i][j] = drawn;
			if (i == j) {
				g[1][i][j] = drawn;
			} else if (i < j) {
				g[1][i][j] = lose;
			} else {
				g[1][i][j] = win;
			}
		}
	}
	for (int n = 2; n < 11; n++) {
		for (int i = 0; i < 11; i++) {
			for (int j = 0; j < 11; j++) {
				if (!i && !j) {
					g[n][i][j] = drawn;
				} else if (i && !j) {
					g[n][i][j] = win;
				} else if (!i && j) {
					g[n][i][j] = lose;
				} else if (i == j) {
					g[n][i][j] = drawn;
				} else if (n * (i + 1) <= j) {
					g[n][i][j] = lose;
				} else if (n * j <= i){
					g[n][i][j] = win;
				} else {
					int sta[3];
					memset(sta, 0, sizeof(sta));
					for (int k = 0; k < i; k++) {
						sta[g[n][k][j]]++;
					}
					for (int k = 0; k < j; k++) {
						sta[g[n][i][k]]++;
					}
					if (!sta[drawn] && !sta[lose]) {
						g[n][i][j] = lose;
					} else if (!sta[lose]) {
						g[n][i][j] = drawn;
					} else {
						g[n][i][j] = win;
					}
				}
			}
		}
	}
#if 1
	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < 11; j++) {
			printf(" %2d", g[4][i][j] - 1);
		}
		puts("");
	}
#endif
}
//main
int main() {
#if 1
	freopen(input, "r", stdin);
	//freopen(output, "w", stdout);
#endif
	int T;
	GInit();
	while (~scanf("%d", &T)) {
		for (int Case = 1; Case <= T; Case++) {
			scanf("%d%d%d", &n, &ca, &cb);
			printf("Case #%d: %d\n", Case, g[n][ca][cb] - 1);
		}
	}
	return 0;
}
