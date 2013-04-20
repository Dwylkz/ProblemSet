#include <cstdlib>
#include <vector>
#include <cstdio>
#include <cctype>
#include <cmath>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1e5 + 10;
struct Vec {
	int x, y;
	Vec(int _x = 0, int _y = 0) {
		x = _x;
		y = _y;
	}
	friend Vec operator - (Vec p, Vec q) {
		return Vec(p.x - q.x, p.y - q.y);
	}
	int Xmod() {
		return abs(x);
	}
	int Ymod() {
		return abs(y);
	}
	int Mod() {
		return abs(x) + abs(y);
	}
	void mov(char d) {
		if (d == 'E') {
			x++;
		} else if (d == 'S') {
			y--;
		} else if (d == 'W') {
			x--;
		} else {
			y++;
		}
	}	
} _Vec;
int t;
Vec s, e;
char d[maxn];
int main()
{
#if 1
	freopen("input.txt", "r", stdin);
#endif
	while (~scanf("%d%d%d%d%d%s", &t, &s.x, &s.y, &e.x, &e.y, d)) {
		int res = -1;
		for (int i = 0; i < t; i++) {
			Vec ts = s;
			ts.mov(d[i]);
			if ((ts - e).Xmod() < (s - e).Xmod() ||
					(ts - e).Ymod() < (s - e).Ymod())
			{
				s = ts;
			}
			if (!(s - e).Mod()) {
				res = 1 + i;
				break;
			}
		}
		printf("%d\n", res);
	}
	return 0;
}
