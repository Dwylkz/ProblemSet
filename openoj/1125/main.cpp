#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <string.h>
#include <iostream>
using namespace std;
const int MAXN = 10e5 + 10;

struct UFS {
	int p[MAXN], d[MAXN];
	void ini() {
		for (int i = 0; i < MAXN; i++) {
			p[i] = i;
			d[i] = 0;
		}
	}
	int fin(int x) {
		int f = p[x];
		if (p[x] != x) {
			f = fin(p[x]);
		}
		if (d[x] == d[p[x]]) {
			d[x] ^= 1;
		}
		return p[x] = f;
	}
	bool uni(int x, int y) {
		if (fin(x) == fin(y)) {
			return 1;
		}
		p[x] = y;
		return 0;
	}
};

int N, M;
UFS ufs;

int main()
{
#if 1
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	while (~scanf("%d%d", &N, &M)) {
		ufs.ini();
		while (M--) {
			char op[2];
			int a, b;

			scanf("%1s%d%d", op, &a, &b);
			if (op[0] == 'D') {
				ufs.uni(a, b);
			}
			else {
#if 1
				printf("%d, %d = %d, %d\n", a, b, ufs.fin(a), ufs.fin(b));
#endif
				if (ufs.fin(a) == ufs.fin(b)) {
					if (ufs.d[a] ^ ufs.d[b]) {
						puts("In the same gang.");
					}
					else {
						puts("In different gangs.");
					}
				}
				else {
					puts("Not sure yet.");
				}
			}
		}
	}
	return 0;
}
