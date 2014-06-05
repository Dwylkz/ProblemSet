#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
typedef vector<int> VI;
typedef set<int> SI;
const int INF = 1e9;

int n, k;

int main() {
#ifndef ONLINE_JUDGE 
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d%d", &n, &k); ) {
		VI res;
		if (n == 1) {
			if (k) puts("-1");
			else puts("1");
			continue;
		}
		int m = k/(n/2), r = k%(n/2);
		bool yes = 1;
		if (!m) yes = 0;
		else {
			SI h;
			int j = 0;
			for (int i = 0; ; i++) {
				int a = (1+i*2)*(m+r);
				int b = (1+i*2+1)*(m+r);
				if (!h.count(a) && !h.count(b)) {
					res.push_back(a);
					res.push_back(b);
					h.insert(a);
					h.insert(b);
					if (a > INF || b > INF) yes = 0;
					j++;
					break;
				}
			}
			for (int i = 0; j < n/2; i++) {
				int a = (1+i*2)*m;
				int b = (1+i*2+1)*m;
				if (!h.count(a) && !h.count(b)) {
					res.push_back(a);
					res.push_back(b);
					h.insert(a);
					h.insert(b);
					if (a > INF || b > INF) yes = 0;
					j++;
				}
			}
			if (n&1) {
				int idx = 1;
				while (h.count(idx)) idx++;
				res.push_back(idx);
				if (idx > INF) yes = 0;
			}
		}
		if (yes) {
			for (int i = 0; i < n; i++)
				printf("%d%c", res[i], i < n-1? ' ': '\n');
		} else puts("-1");
  }
  return 0;
}
