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
char b[MAXN];
char e[MAXN] = {
	'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']',
	'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'',
	'c', 'v', 'b', 'n', 'm', ',', '.',
	'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', '{', '}',
	'D', 'F', 'G', 'H', 'J', 'K', 'L', ':', '"',
	'C', 'V', 'B', 'N', 'M', '<', '>',
	' '
};
char d[MAXN] = {
	'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p',
	'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l',
	'z', 'x', 'c', 'v', 'b', 'n', 'm',
	'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p',
	'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l',
	'z', 'x', 'c', 'v', 'b', 'n', 'm',
	' '
};
char Decode(char c, int i = 0){
	for (; e[i] != ' '; i++) if (e[i] == c) break;
	return d[i];
}
//Main
int main(){
#if 1
	freopen("test.txt", "r", stdin);
	freopen("test.out", "w", stdout);
#endif
	while (~scanf("%[^\n]\n", b)){
		for (int i = 0, l = strlen(b); i < l; i++)
			b[i] = Decode(b[i]);
		printf("%s\n", b);
	}
	return 0;
}
