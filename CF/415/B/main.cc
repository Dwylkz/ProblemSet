#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int n, a, b;

int main() {
#ifndef ONLINE_JUDGE 
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d%d%d", &n, &a, &b); ) {
		for (int i = 0, sp = 0; i < n; i++) {
			int xi;
			scanf("%d", &xi);
			if (sp) putchar(' ');
			sp = 1;
			int l = 0, r = xi;
			long long k = 1ll*xi*a/b;
			while (l < r) {
				int m = l+r>>1;
				if (1ll*m*a/b == k) r = m;
				else l = m+1;
			}
			printf("%d", xi-l);
		}
		puts("");
  }
  return 0;
}
