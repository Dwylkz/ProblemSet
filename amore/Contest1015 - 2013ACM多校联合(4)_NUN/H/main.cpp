#include <cstdio>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 1e5 + 10;
typedef unsigned char UC;
typedef unsigned int UI;
int n, c[maxn];
int main() {
#if 1
	freopen("input.txt", "rt", stdin);
#endif
	while (~scanf("%d", &n)) {
		int sum = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", c + i);
			sum += c[i];
		}
		int res = 0;
		for (int i = 0; i < n; i++) {
			if (~(sum - c[i]) & 1) {
				res++;
			}
		}
		printf("%d\n");
	}
}
