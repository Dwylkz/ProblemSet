#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cctype>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;
//STL
#define MS(c, a) memset(c, a, sizeof c)
//Syntax
#define Rep(c, a, b) for (int c = (a); c < (b); c++)
#define Nre(c, a, b) for (int c = (a); c > (b); c--)
//DEBUG
#define FK puts("Fu*k here!")
//Type
typedef unsigned int UI;
typedef long long LL;
typedef long double LD;
//Constant
const LL INFL = ~0ull >> 1;
const int INFI = ~0u >> 1;
const int MAXN = 505;
const int MOD = 1000000007;
//Array
typedef int AI[MAXN];
typedef bool AB[MAXN];
typedef double AD[MAXN];
typedef LL ALL[MAXN];
typedef LD ALD[MAXN];

int n, m, ct;
char B[MAXN][MAXN], F[MAXN][MAXN];

void F_ini(){
	LL sm = 0;
	MS(F, 0);
	F[0][0] = F[0][1] = F[1][0] = '.';
	F[1][1] = '*';
	for (int sz = 2; sz < MAXN; sz <<= 1){
		sm += 1LL * (500 - sz) * (500 - sz);
		printf("sm = %lld\n", sm);
	}
}

int main()
{
#if 1
	freopen("test.txt", "r", stdin);
	freopen("test.out", "w", stdout);
#endif
	F_ini();
	while (~scanf("%d%d", &n, &m)){
		Rep(i, 0, n) scanf("%s", B[i]);
		printf("%d\n", ct);
	}
	return 0;
}
