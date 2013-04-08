//coder: SXDwylkz
//heads
#include <cmath>
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
//namespaces
using namespace std;
//constants
const char input[] = "input.in",
	  output[] = "output.out";
const int inf32 = 0x7fffffff,
	  maxn = 1e5 + 10;
const long long inf64 = 0x7fffffffffffffffLL; 
//structure
struct Word {
	int t, v;
	Word(int _t = 0, int _v = 0) {
		t = _t;
		v = _v;
	}
};
//type definition
typedef long long LL;
//global variable
int s[4];
Word ele[8] = {
		 Word(1, 0),
		 Word(1, 1),
		 Word(1, 2),
		 Word(1, 3)
	 };
vector<int> r;
//access and mutator
int vis[4];
Word equ[7];
void DFS(int l = 0, int cnt = 0) {
	if (7 - l < 4 - cnt) return ;
	if (l == 7) {
#if 0
		for (int i = 0; i < 7; i++) {
			if (equ[i].t == 0) {
				printf("(%d)", equ[i].v);
			} else {
				switch (equ[i].v) {
					case 0:
						putchar('+');
						break;
					case 1:
						putchar('-');
						break;
					case 2:
						putchar('*');
						break;
					case 3:
						putchar('/');
						break;
				}
			}
		}
		puts("");
#endif
		vector<int> num, ops;
		for (int i = 0; i < 7; i++) {
			if (equ[i].t) {
				ops.push_back(equ[i].v);
			} else {
				num.push_back(equ[i].v);
			}
			if (ops.size() && num.size() > 1) {
				int tmp;
				switch (num.back()) {
					case 0:
						tmp = num[num.size() - 2] + num.back();
						break;
					case 1:
						tmp = num[num.size() - 2] - num.back();
						break;
					case 2:
						tmp = num[num.size() - 2] * num.back();
						break;
					case 3:
						if (num[num.size() - 2] % num.back() != 0) {
							return ;
						}
						tmp = num[num.size() - 2] / num.back();
						break;
				}
				ops.pop_back();
				num.pop_back();
				num.pop_back();
				num.push_back(tmp);
			}
		}
		if (!ops.size() && num.size() == 1) {
			r.push_back(num.back());
		}
	} else {
		for (int i = 0; i < 8; i++) {
			if (!ele[i].t) {
				int id = i % 4;
				if (!vis[id]) {
					vis[id] = 1;
					equ[l] = ele[i];
					DFS(l + 1, cnt + 1);
					vis[id] = 0;
				}
			} else {
				equ[l] = ele[i];
				DFS(l + 1);
			}
		}
	}
}
//main
int main() {
#if 1
	freopen(input, "r", stdin);
	//freopen(output, "w", stdout);
#endif
	int Case = 1;
	while (scanf("%d%d%d%d", s, s + 1, s + 2, s + 3)) {
		if (!s[0] && !s[1] && !s[2] && !s[3]) {
			break;
		}
		for (int i = 0; i < 4; i++) {
			ele[4 + i] = Word(0, s[i]);
		}
		r.clear();
		memset(vis, 0, sizeof(vis));
		DFS();
		sort(r.begin(), r.end());
#if 1
		printf("r: ");
		for (int i = 0; i < r.size(); i++) {
			printf("%4d", r[i]);
		}
		puts("");
#endif
	}
	return 0;
}
