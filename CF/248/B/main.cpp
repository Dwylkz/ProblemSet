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
//Global
int n;
//Main
int main(){
#if 0
	freopen("test.txt", "r", stdin);
	//freopen("test.out", "w", stdout);
#endif
	/*for (int i = 210, j = 2; i < 100010000; i++)
		if ((int)floor(log(i) / log(10.0)) == j && i % 2 == 0 && i % 3 == 0 && i % 5 == 0 && i % 7 == 0){
			printf(" %d", i);
			if (j++ % 10 == 0) puts("");
		}*/
	while (~scanf("%d", &n)){
		if (n < 3) printf("-1");
		else if (n < 4) printf("210");
		else if (n < 5) printf("1050");
		else if (n < 6) printf("10080");
		else if (n < 7) printf("100170");
		else{
			printf("1000020");
			for (int i = 0; i < n - 7; i++) putchar('0');
		}
		puts("");
	}
	return 0;
}
