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
namespace Dwylkz{
	//Type
	typedef unsigned int UI;
	typedef long long LL;
	typedef long double LD;
	//Constant
	const LL INFL = ~0ull >> 1;
	const int INFI = ~0u >> 1;
	const int MAXN = 1e7;
	const int MOD = 364875103;
	//Array
	typedef int AI[MAXN];
	typedef bool AB[MAXN];
	typedef double AD[MAXN];
	typedef LL ALL[MAXN];
	typedef LD ALD[MAXN];
}
using namespace Dwylkz;
//STL
#define MS(c, a) memset(c, a, sizeof c)
//Syntax
#define Rep(c, a, b) for (int c = (a); c < (b); c++)
#define Nre(c, a, b) for (int c = (a); c > (b); c--)
//DEBUG
#define FK puts("Fu*k here!")

//C(n, m)
LL GCD(LL a, LL b){
    return b? GCD(b, a % b): a;
}
LL C(LL n, LL m){
	LL tn, tp, i, j, d;
	vector<LL> div;
	if (n - m < m) m = n - m;
	for (i = 1; i <= m; i++)
	Rep(i, 1, m + 1) div.push_back(n - i + 1);
	Rep(i, 1, m + 1){
		tp = i;
		for (j = 0; tp > 1 && j < m; j++){
			d = GCD(tp, div[j]);
			div[j] /= d;
			tp /= d;
		}
	}
	for (tn = 1, i = 0; i < m; i++) tn = (tn * div[i]) % MOD;
	return tn;
}

int n, m, k, K[16];

int main()
{
#if 1
	freopen("test.txt", "r", stdin);
	freopen("test.out", "w", stdout);
#endif
	int T, Cas = 1;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d%d", &n, &m, &k);
		Rep(i, 0, k) scanf("%d", K + i);
		K[k++] = m;
		LL res = 1;
		Rep(i, 1, k) res = (res * C(n + (K[i] - K[i - 1] - 1), n - 1)) % MOD;
		printf("Case #%d: %lld\n", Cas++, res);
	}
	return 0;
}
