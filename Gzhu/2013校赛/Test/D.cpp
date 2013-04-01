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
	const int MOD = 1e+7;
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
//Main
int main()
{
#if 0
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
#endif
	int f[4];
	char s[4][10];
	while (~scanf("%d.%d.%d.%d\n", f, f + 1, f + 2, f + 3)) {
		scanf("%[^.].%[^.].%[^.].%s", s, s + 1, s + 2, s + 3);
#if 0
		printf("%d.%d.%d.%d\n", f[0], f[1], f[2], f[3]);
		printf("%s#%s#%s#%s\n", s[0], s[1], s[2], s[3]);
#endif
		bool yes = 1;
		for (int i = 0; i < 4; i++) {
			int b = 0;
			for (int j = 0; j < 8; j++) {
				b = b * 2 + s[i][j] - '0';
			}
#if 0
			printf("%d.\n", b);
#endif
			if (f[i] != b) {
				yes = 0;
				break;
			}
		}
		puts(yes? "Yes": "No");
	}
	return 0;
}
