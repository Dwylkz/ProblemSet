#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

int main() {
#if 0
  freopen("input.in", "r", stdin);
  freopen("output.out", "w", stdout);
#endif
	int T;
	scanf("%d", &T);
  for (int cas = 1; cas <= T; cas++) {
		printf("Case #%d:", cas);
		int r, c[4][4], h[17] = {0};
		scanf("%d", &r);
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				scanf("%d", c[i]+j);
		for (int i = 0; i < 4; i++)
			h[c[r-1][i]]++;
		scanf("%d", &r);
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				scanf("%d", c[i]+j);
		int ret = 0, cnt = 0;
		for (int i = 0; i < 4; i++)
			if (h[c[r-1][i]]) {
				cnt++;
				ret = c[r-1][i]; 
			}
		if (!cnt) puts(" Volunteer cheated!");
		else if (cnt > 1) puts(" Bad magician!");
		else printf(" %d\n", ret);
  }
  return 0;
}
