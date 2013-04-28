#include <cstdio>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 1e5 + 10;
typedef unsigned char UC;
typedef unsigned int UI;
struct HT {
	static const int sz = 13131;
	vector<string> H[sz];
	void Init() {
		for (int i = 0; i < sz; i++) {
			H[i].clear();
		}
	}
	int HF(UC *s) {
		UI key = 0;
		for ( ; *s; s++) {
			key = key * 26 + *s - 'a';
		}
		return key % sz;
	}
	int Hash(string s, bool ios = 0) {
		int k = HF((UC*)s.data());
		for (int i = 0; i < H[k].size(); i++) {
			if (H[k][i] == s) {
				return 1;
			}
		}
		if (ios) {
			H[k].push_back(s);
		}
		return 0;
	}
};
HT H;
int n, m;
char buf[40];
int main() {
#if 1
	freopen("input.txt", "rt", stdin);
#endif
	while (~scanf("%d%d", &n, &m)) {
		H.Init();
		while (n--) {
			scanf("%s", buf);
			H.Hash(buf, 1);
		}
		while (m--) {
			scanf("%s", buf);
			puts(H.Hash(buf, 1)? "NO": "YES");
		}
	}
}
