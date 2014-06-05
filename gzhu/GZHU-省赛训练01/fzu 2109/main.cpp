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
	  maxn = 12,
	  maxm = 10;
const long long inf64 = 0x7fffffffffffffffLL; 
//structure
//type definition
typedef long long LL;
//global variable
enum tag{even, odd};
int L, R, f[maxn][maxm][2];
//access and mutator
void Init() {
	memset(f, 0, sizeof(f));
	for (int i = 0; i < maxm; i++) {
		f[0][i][odd] = f[0][i][even] = 1;
	}
	for (int i = 1; i < maxn; i++) {
		for (int j = 0; j < maxm; j++) {
			for (int k = j; k < maxm; k++) {
				f[i][j][odd] += f[i - 1][k][even];
			}
			for (int k = 0; k <= j; k++) {
				f[i][j][even] += f[i - 1][k][odd];
			}
		}
	}
}
int Clac(int x) {
	vector<int> s;
	for (s.push_back(x % 10), x /= 10; x; x /= 10) {
		s.push_back(x % 10);
	}
	for (int i = 0; i < s.size() / 2; i++) {
		swap(s[i], s[s.size() - i - 1]);
	}
	int res = 1;
	for (int i = 0; i < s[0]; i++) {
		res += f[s.size() - 1][i][odd];
	}
	for (int i = 1; i < s.size(); i++) {
		if (i & 1) {
			for (int j = s[i - 1]; j < s[i]; j++) {
				res += f[s.size() - i - 1][j][even];
			}
			if (s[i] < s[i - 1]) {
				res--;
				break;
			}
		} else {
			for (int j = 0; j < min(s[i - 1] + 1, s[i]); j++) {
				res += f[s.size() - i - 1][j][odd];
			}
			if (i && s[i - 1] < s[i]) {
				res--;
				break;
			}
		}
	}
	return res;
}
//main
int main() {
#if 1
	freopen(input, "r", stdin);
	//freopen(output, "w", stdout);
#endif
	int T;
	Init();
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &L, &R);
		printf("%d\n", Clac(R) - Clac(L - 1));
	}
	return 0;
}
