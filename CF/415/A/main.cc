#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e2+10;

int n, m, as[N];

int main() {
#ifndef ONLINE_JUDGE 
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d%d", &n, &m); ) {
		fill(as, as+n, 0);
		for (int i = 0; i < m; i++) {
			int bi;
			scanf("%d", &bi);
			for_each(as+bi-1, as+n, [&](int &x){if (!x) x = bi;});
		}
		for (int i = 0; i < n; i++)
			printf("%d%c", as[i], i < n-1? ' ': '\n');
  }
  return 0;
}
