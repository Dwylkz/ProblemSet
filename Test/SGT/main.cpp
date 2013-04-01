//Head
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
using namespace std;
//Dwylkz
namespace Dwylkz{
	//Type
	typedef unsigned int UI;
	typedef long long LL;
	typedef long double LD;
	//Constant
	const LL INFLL = ~0uLL >> 1;
	const int INFI = ~0u >> 1;
	const int MAXN = 1e7;
	const int MOD = 1e9 + 7;
	//Array
	typedef int AI[MAXN];
	typedef bool AB[MAXN];
	typedef double AD[MAXN];
	typedef LL ALL[MAXN];
	typedef LD ALD[MAXN];
}
using namespace Dwylkz;
//Macro
#define MS(c, a) memset(c, a, sizeof c)
#define Rep(c, a, b) for (int c = a; c < int(b); c++)
#define Nre(c, a, b) for (int c = a; c > int(b); c--)
#define FK puts("Here")
//SGT
const int SGTN = 1 << 19, J = 1 << 17;
int sm[SGTN];
void Init(){
	memset(sm, 0, sizeof sm);
}
void Draw(int k, int l, int r){
	for (l += J, r += J + 2; l ^ r ^ 1; l >>= 1, r >>= 1){
		if (~l & 1) sm[l ^ 1] += k, sm[(l ^ 1) << 1] -=k, sm[(l ^ 1) << 1 + 1] -= k;
		if (r & 1) sm[r ^ 1] += k, sm[(r ^ 1) << 1] -=k, sm[(r ^ 1) << 1 | 1] -= k;
	}
}
int Ask(int l, int r, int n = 1, int res = 0){
	for (l += J, r += J + 2; l ^ r ^ 1; l >>= 1, r >>= 1, n <<= 1){
		if (~l & 1) res += sm[l ^ 1] * n;
		if (r & 1) res += sm[r ^ 1] * n;
	}
	for (; r; r >>= 1, n <<= 1) res += sm[r] * n;
	return res;
}
//Global
//Main
int main(){
#if 1
	freopen("test.txt", "r", stdin);
	//freopen("test.out", "w", stdout);
#endif
	Init();
	char op[2];
	int l, r, k;
	while (~scanf("%s%d%d", op, &l, &r)){
		if (op[0] == 'C'){
			scanf("%d", &k);
			Draw(k, l, r);
		}
		else printf("%d\n", Ask(l, r));
	}
	return 0;
}
