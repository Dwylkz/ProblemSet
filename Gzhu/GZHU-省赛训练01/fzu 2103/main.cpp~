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
	  maxn = 60;
const long long inf64 = 0x7fffffffffffffffLL; 
//structure
//type definition
typedef long long LL;
//global variable
int N, k, r, R[maxn];
double p[maxn], C[maxn][maxn];
//access and mutator
void Init() {
	memset(C, 0, sizeof(C));
	for (int i = C[0][0] = 1; i < maxn; i++) {
		C[i][0] =  1.0;
		for (int j = 1; j < maxn; j++) {
			C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
		}
	}
}
//main
int main() {
#if 1
	freopen(input, "r", stdin);
	//freopen(output, "w", stdout);
#endif
	Init();
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d", &N, &k, &r);
		for (int i = 1; i <= N; i++) {
			scanf("%lf", p + i);
		}
		for (int i = 1; i <= r; i++) {
			scanf("%d", R + i);
		}
		sort(R + 1, R + r + 1);
		double Sp = 0.0;
		for (int i = 1; i <= R[1]; i++) {
			Sp += p[i];
		}
		int rm = r;
		double res = C[k][k - r] * pow(Sp, 1.0 * k - r);
		for (int i = 1; i <= r; i++) {
			int cnt = 1;
			for (i++; i <= r && R[i] == R[i - 1]; i++) {
				cnt++;
			}
			i--;
			res *= C[rm][cnt] * pow(p[R[i]], 1.0 * cnt);
			rm -= cnt;
		}
		printf("%.6f\n", res);
	}
	return 0;
}
