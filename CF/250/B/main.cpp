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
int n;
AC ip, b;
//Main
int main(){
#if 1
	freopen("test.txt", "r", stdin);
	//freopen("test.out", "w", stdout);
#endif
	while (~scanf("%d", &n)){
		scanf("%s", ip);
		int c = 0, li = strlen(ip);
		ip[li] = ':';
		Rep(i, 0, li) c += (ip[i] == ':');
		Rep(i, 0, li){
			int lb = 0;
			while (ip[i] != ':') b[lb++] = ip[i++];
			b[lb] = 0;
			if (!lb){
				if (!i) i++, printf("0000:");
				printf("0000");
				Rep(j, c, 7) printf(":0000");
				if (i == li - 1) printf(":0000");
			}
			else{
				Rep(j, lb, 4) printf("0");
				printf("%s", b);
			}
			if (i + 1 < li) printf(":");
		}
		puts("");
	}
	return 0;
}
