#include <cstdio>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
const int maxn = 4e5 + 10;
typedef unsigned char UC;
typedef long long LL;
typedef unsigned int UI;
typedef pair<int, int> PI;
int n, m, ab[2][maxn];
vector<int> s;
int Sum(int t, int h) {
	for (int i = h; i < n; i++) {
		s.push_back(ab[t][0] + ab[t ^ 1][i]);
	}
	return 1;
}
int main() {
#if 1
	freopen("input.txt", "rt", stdin);
#endif
	while (~scanf("%d%d", &n, &m)) {
		for (int i = 0; i < n; i++) {
			scanf("%d", ab[0] + i);
		}
		for (int i = 0; i < n; i++) {
			scanf("%d", ab[1] + i);
		}
		sort(ab[0], ab[0] + n);
		sort(ab[1], ab[1] + n);
		s.clear();
		Sum(1, Sum(0, 0));
		sort(s.begin(), s.end());
		for (int i = 0; i < m; i++) {
			printf("%d\n", s[i]);
		}
	}
}
