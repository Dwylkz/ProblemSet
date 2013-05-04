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
	  maxn = 1e5 + 10;
const long long inf64 = 0x7fffffffffffffffLL; 
//type definition
typedef int AB[maxn];
typedef int AI[maxn];
typedef char AC[maxn];
typedef long long LL;
//Extern
struct Arg {
	int t, v;
	Arg(int _t =  0, int _v = 0) {
		t = _t;
		v = _v;
	}
};
Arg bol[12];
int n, t, yes,
	pri[4] = {0, 0, 1, 1},
	opc[4] = {'+', '-', '*', '/'},
	car[6], ope[5];
int calc() {
	stack<int> S;
	int j = 0;
	for (int i = 0; i < 2 * n - 1; i++) {
		if (~i & 1) {
			bol[j++] = Arg(0, car[i >> 1]);
		} else {
			for ( ; !S.empty() && pri[ope[i >> 1]] <= pri[S.top()]; ) {
				bol[j++] = Arg(1, S.top());
				S.pop();
			}
			S.push(ope[i >> 1]);
		}
	}
	for ( ; !S.empty(); S.pop()) {
		bol[j++] = Arg(1, S.top());
	}
#if 0
	puts("bolan: ");
	for (int i = 0; i < j; i++) {
		if (!bol[i].t) {
			printf("%d", bol[i].v);
		} else {
			printf("%c", opc[bol[i].v]);
		}
	}
	puts("");
#endif
	statck<int> I; 
	for (int i = 0; i < j; i++) {
	}
	return 0;
}
int dfs(int i = 0) {
	if (i == n - 1) {
		return yes = (calc() == t);
	}
	for (int j = 0; j < 4; j++) {
		ope[i] = j;
		if (dfs(i + 1)) {
			return 1;
		}
	}
	return 0;
}
//main
int main() {
#if 1
	freopen(input, "r", stdin);
	//freopen(output, "w", stdout);
#endif
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &t);
		for (int i = 0; i < n; i++) {
			scanf("%d", car + i);
		}
		yes = 0;
		do {
			if (dfs()) {
				break;
			}
		} while (next_permutation(car, car + n));
		puts(yes? "YES": "NO");
	}
	return 0;
}
