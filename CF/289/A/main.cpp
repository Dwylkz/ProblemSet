#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <string.h>
#include <iostream>
using namespace std;
const int MAXN = 10e5 + 10;
struct Seg {
	int l, r;
	friend bool operator < (Seg p, Seg q) {
		return p.l < q.l;
	}
};
Seg s[MAXN];
int n, k;
int main()
{
	while (~scanf("%d%d", &n, &k)) {
		int res = 0x7fffffff;
		for (int i = 0; i < n; i++) {
			scanf("%d", &s[i].l, &s[i].r);
		}
	}
	return 0;
}
