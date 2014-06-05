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
	typedef char AC[MAXN];
	typedef int AI[MAXN];
	typedef bool AB[MAXN];
	typedef double AD[MAXN];
	typedef LL ALL[MAXN];
	typedef LD ALD[MAXN];
}
using namespace Dwylkz;
#define MS(c, a) memset(c, a, sizeof c)
#define Rep(c, a, b) for (int c = a; c < int(b); c++)
#define Nre(c, a, b) for (int c = a; c > int(b); c--)
#define FK puts("Here")
//Global
int  x[3][3];
//Main
int main(){
#if 0
	freopen("test.txt", "r", stdin);
	//freopen("test.out", "w", stdout);
#endif
	Rep(i, 0, 3) Rep(j, 0, 3) {
		scanf("%d", x[i]+j);
	}
	x[2][2] = (x[0][1]+x[0][2]+x[1][0]+x[1][2]-x[2][0]-x[2][1])/2;
	x[1][1] = x[0][1]+x[0][2]-x[2][2];
	x[0][0] = x[2][0]+x[2][1]+x[2][2]-x[0][1]-x[0][2];
	Rep(i, 0, 3) {
		Rep(j, 0, 2) {
			printf("%d ", x[i][j]);
		}
		printf("%d\n", x[i][2]);
	}
	return 0;
}
