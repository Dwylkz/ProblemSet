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
	  maxn = 512;
const long long inf64 = 0x7fffffffffffffffL; 
//type definition
typedef int AB[maxn];
typedef int AI[maxn];
typedef char AC[maxn];
typedef long long LL;
//Extern
int n, f[maxn][maxn], vs[maxn][maxn],
	mv[4][2] = {
		0, 1,
		1, 0,
		0, -1,
		-1, 0
	};
char m[maxn][maxn];
struct QS {
	int x, y;
};
int BFS() {
	queue<QS> Q;
	QS u = {0, 0};
	Q.push(u);
	memset(vs, 0, sizeof(vs));
	vs[u.x][u.y] = 1;
	while (!Q.empty()) {
		u = Q.front();
		Q.pop();
		if (u.x == n - 1 && u.y == n - 1) {
			return 1;
		}
		for (int i = 0; i < 4; i++) {
			int x = u.x + mv[i][0], y = u.y + mv[i][1];
			if (0 <= x && x < n
					&& 0 <= y && y < n
					&& m[x][y] - '0' == 0 && !vs[x][y]) {
				vs[x][y] = 1;
				QS v = {x, y};
				Q.push(v);
			}
		}
	}
	return 0;
}
void SPFA() {
	int x = 0, y = 0;
	stack<QS> Q;
	QS u = {x, y};
	Q.push(u);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			f[i][j] = maxn * maxn;
		}
	}
	f[x][y] = 0;
	memset(vs, 0, sizeof(vs));
	vs[x][y] = 1;
	while (!Q.empty()) {
		u = Q.top();
		vs[u.x][u.y] = 0;
		Q.pop();
		for (int i = 0; i < 4; i++) {
			x = u.x + mv[i][0], y = u.y + mv[i][1];
			if (0 <= x && x < n && 0 <= y && y < n) {
				int dt = m[x][y] - '0';
				if (f[x][y] - dt > f[u.x][u.y]) {
					f[x][y] = f[u.x][u.y] + dt;
					if (!vs[x][y]) {
						QS v = {x, y};
						Q.push(v);
						vs[x][y] = 1;
					}
				}
			}
		}
	}
}
//main
int main() {
#if 1
	freopen(input, "r", stdin);
	//freopen(output, "w", stdout);
#endif
	while (~scanf("%d", &n)) {
		for (int i = 0; i < n; i++) {
			scanf("%s", m[i]);
		}
		if (BFS()) {
			puts("0");
			continue;
		}
		SPFA();
#if 0
		puts("f:");
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				printf("%5d", f[i][j]);
			}
			puts("");
		}
#endif
		printf("%d\n", f[n - 1][n - 1]);
	}
	return 0;
}
