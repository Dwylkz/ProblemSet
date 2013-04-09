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
	  maxn = 1010;
const long long inf64 = 0x7fffffffffffffffLL; 
//structure
//type definition
typedef long long LL;
//global variable
int n, q;
char s[maxn];
//access and mutator
void Delete(char *t, int x, int &r) {
	for (int i = x; i < r; i++) {
		t[i] = t[i + 1];
	}
	r--;
}
void Run(int l, int r) {
	char t[maxn];
	int cp = 0, dp = 1, cnt[10], tl = 0;
	for (int i = l; i < r; i++) {
		t[tl++] = s[i];
	}
	t[tl] = 0;
	memset(cnt, 0, sizeof(cnt));
	while (0 <= cp && cp < tl) {
#if 0
		printf("%c: %s\n", t[cp], t);
#endif
		if (isdigit(t[cp])) {
			cnt[t[cp] - '0']++;
			cp += dp;
			if (t[cp - dp] == '0') {
				Delete(t, cp - dp, tl);
				if (dp == 1) {
					cp--;
				}
			} else {
				t[cp - dp]--;
			}
		} else if (t[cp] == '<') {
			dp = -1;
			if (!isdigit(t[--cp])) {
				Delete(t, cp - dp, tl);
			}
		} else if (t[cp] == '>') {
			dp = 1;
			if (!isdigit(t[++cp])) {
				Delete(t, cp - dp, tl);
				cp--;
			}
		}
	}
	for (int i = 0; i < 10; i++) {
		if (i) {
			putchar(' ');
		}
		printf("%d", cnt[i]);
	}
	puts("");
}
//main
int main() {
#if 1
	freopen(input, "r", stdin);
	//freopen(output, "w", stdout);
#endif
	while (~scanf("%d%d", &n, &q)) {
		scanf("%s", s);
		while (q--) {
			int l, r;
			scanf("%d%d", &l, &r);
			Run(l - 1, r);
		}
	}
	return 0;
}
