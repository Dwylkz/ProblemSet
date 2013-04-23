//Kimady::S.X.Dwylkz
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
//Namespace
namespace dtd{
	//Constant
	const long long INFLL = ~0uLL>>1;
	const int INFI = ~0u>>1;
	const int MAXN = 22;
	const int MAXM = 22;
	const int MOD = 1e+7;
	//Type Definition
	typedef unsigned int UI;
	typedef long long LL;
	typedef long double LD;
	typedef int AI[MAXN];
	typedef bool AB[MAXN];
	typedef double AD[MAXN];
	typedef LL ALL[MAXN];
	typedef LD ALD[MAXN];
	typedef AI AI2[MAXM];
	typedef AB AB2[MAXM];
	typedef AD AD2[MAXM];
	typedef ALL ALL2[MAXM];
	typedef ALD ALD2[MAXM];
}
using namespace std;
using namespace dtd;
//Macro
#define Bug puts("Here")
//Global
int n;
char m[MAXN][MAXN];
bool b[MAXN][MAXN];
int mv[4][2] = {
	0, 1,
	1, 0,
	0, -1,
	-1, 0
};

struct bfss {
	int x, y, d;
};
int bfs(int &x, int &y, char t)
{
	queue<bfss> Q;
	bfss s = {x, y, 0};
	Q.push(s);
	b[x][y] = 1;
	while (!Q.empty()) {
		s = Q.front();
		Q.pop();
		x = s.x; 
		y = s.y;
		if (m[x][y] == t) {
			return s.d;
		}
		for (int i = 0; i < 4; i++) {
			int tx = x + mv[i][0], ty = y + mv[i][1];
			if (0 <= tx && tx < n && 0 <= ty && ty < n &&
					(m[tx][ty] == '.' || m[tx][ty] == t) &&
					!b[tx][ty]) {
				bfss t = {tx, ty, s.d + 1};
				Q.push(t);
				b[tx][ty] = 1;
			}
		}
	}
	return -1;
}

//Main
int main()
{
#if 0
	freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
#endif
	while (~scanf("%d", &n)) {
		int x, y;
		char k = 'A';
		for (int i = 0; i < n; i++) {
			scanf("%s", m[i]);
			for (int j = 0; j < n; j++) {
				k += ('A' <= m[i][j] && m[i][j] <= 'Z');
				if (m[i][j] == 'A') {
					x = i;
					y = j;
				}
			}
		}
#if 0
		printf("(%d, %d) start; k = %d\n", x, y, k);
#endif
		int res = 0;
		for (char t = 'A'; t < k; t++) {
#if 0
			printf("(%d, %d)\n", x, y);
#endif
			memset(b, 0, sizeof(b));
			int d = bfs(x, y, t);
			if (d < 0) {
				res = -1;
				break;
			}
			m[x][y] = '.';
#if 0
			printf("%c - > %c = %d\n", t - 1, t, d);
#endif
			res += d;
		}
		if (res < 0) {
			puts("Impossible");
		} else {
			printf("%d\n", res);
		}
	}
	return 0;
}
