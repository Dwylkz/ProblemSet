//Kimady::S.X.Dwylkz
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>
//Namespace
namespace dtd{
	//Constant
	const long long INFLL = ~0uLL>>1;
	const int INFI = ~0u>>1;
	const int MAXN = 100;
	const int MAXM = 100;
	const int MOD = 1e4+7;
	//Type Definition
	typedef unsigned int UI;
	typedef long long LL;
	typedef long double LD;
	typedef int AI[MAXN];
	typedef bool AB[MAXN];
	typedef double AD[MAXN];
	typedef LL ALL[MAXN];
	typedef LD ALD[MAXN];
	typedef AI AI2[MAXM];
	typedef AB AB2[MAXM];
	typedef AD AD2[MAXM];
	typedef ALL ALL2[MAXM];
	typedef ALD ALD2[MAXM];
}
using namespace std;
using namespace dtd;
//Macro
#define Bug puts("Here")

//Global
int n;

void mul(int a[4][4], int b[4][4], int c[4][4])
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			c[i][j] = 0;
			for (int k = 0; k < 4; k++) {
				c[i][j] += a[i][k] * b[k][j] % MOD;
				c[i][j] %= MOD;
			}
		}
	}
}

int qmod(int R[2][4][4], int p)
{
	int X[2][4][4] = {
		1, 0, 0, 0,
		0, 1, 1, 0,
		0, 0, 0, 1,
		1, 2, 1, 1
	};
	int rx = 0, rr = 0;
	while (p) {
		if (p & 1) {
			mul(X[rx], R[rr], R[rr ^ 1]);
			rr ^= 1;
		}
		mul(X[rx], X[rx], X[rx ^ 1]);
		rx ^= 1;
		p >>= 1;
	}
	return rr;
}

//Main
int main()
{
#if 0
	freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
#endif
	while (~scanf("%d", &n)) {
		if (n == 1) {
			puts("1");
		} else if (n == 2) {
			puts("2");
		} else {
			int A[2][4][4] = {
				2, 0, 0, 0,
				0, 0, 0, 0,
				1, 0, 0, 0,
				2, 0, 0, 0
			};
			int X[2][4][4] = {
				1, 0, 0, 0,
				0, 1, 0, 0,
				0, 0, 1, 0,
				0, 0, 0, 1
			};
			int rx = qmod(X, n - 2);
			mul(X[rx], A[0], A[1]);
			printf("%d\n", A[1][3][0]);
		}
	}
	return 0;
}
