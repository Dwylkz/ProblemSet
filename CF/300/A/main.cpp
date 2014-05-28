#include <cstdlib>
#include <vector>
#include <map>
#include <cstdio>
#include <cctype>
#include <string.h>
#include <iostream>
using namespace std;
const int maxn = 1e5 + 10;
#define Rep(c, a, b) for (int c = a; c < (b); c++)
int n;
vector<int> positive, negative, zero;
int main()
{
#if 1
	freopen("input.txt", "r", stdin);
#endif
	while (~scanf("%d", &n)) {
		positive.clear();
		negative.clear();
		zero.clear();
		for (int i = 0; i < n; i++) {
			int ai;
			scanf("%d", &ai);
			if (0 < ai) {
				positive.push_back(ai);
			} else if (ai < 0) {
				negative.push_back(ai);
			} else {
				zero.push_back(ai);
			}
		}
		if (!positive.size()) {
			for (int i = 0; i < 2; i++) {
				positive.push_back(negative.back());
				negative.pop_back();
			}
		}
		if (~negative.size() & 1) {
			zero.push_back(negative.back());
			negative.pop_back();
		}
		printf("%d", negative.size());
		for (int i = 0; i < negative.size(); i++) {
			printf(" %d", negative[i]);
		}
		puts("");
		printf("%d", positive.size());
		for (int i = 0; i < positive.size(); i++) {
			printf(" %d", positive[i]);
		}
		puts("");
		printf("%d", zero.size());
		for (int i = 0; i < zero.size(); i++) {
			printf(" %d", zero[i]);
		}
		puts("");
	} 
	return 0;
}
