#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <stack>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const int MAXN = 3*10e6+10;
typedef long long LL;
#define Rep(c, a, b) for (int c = (a); c < (b); c++)

int n;
bool h[MAXN];
vector<int> a;

int main()
{
#if 0
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	int n;
	while (~scanf("%d", &n)) {
		LL cnt = 0;
		memset(h, 0, sizeof(h));
		a.clear();
		for (int i = 0; i < n; i++) {
			int ai;
			scanf("%d", &ai);
			if (ai < 1) {
				cnt += 1 - ai;
				ai = 1;
			}
			else if (n < ai) {
				cnt += ai - n;
				ai = n;
			}
			if (!h[ai]) {
				a.push_back(ai);
			}
			else {
				h[ai] = 1;
			}
		}
		sort(a.begin(), a.end());
		for (int i = n; 0 < i; i--) {
			if (!h[i]) {
				cnt += abs(a[a.size() - 1] - i);
				a.pop_back();
			}
		}
		printf("%I64d\n", cnt);
	}
	return 0;
}
