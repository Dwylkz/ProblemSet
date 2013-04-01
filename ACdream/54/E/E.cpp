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
//STL-Alias
#define UN(c, a) unique(c, a)
#define MS(c, a) memset(c, a, sizeof c)
#define FLC(c, a ,b) fill(c, c + a, b)
#define LOS(c, a, b) lower_bound(c, a, b)
#define UPS(c, a, b) upper_bound(c, a, b)
//Syntax-Alias
#define Rep(c, a, b) for (int c = (a); c < (b); c++)
#define Nre(c, a, b) for (int c = (a); c > (b); c--)
//B-OP
#define LM(x, y) ((x) << (y))
#define RM(x, y) ((x) >> (y))
#define GB(x, y) (RM(x, y) & 1)
#define SB(x, y) (LM(1, y) | x)
#define SBI(x, a, b) ((LM(1, b) - LM(1, a)) | x)
#define CBI(x, a, b) (~(LM(1, b) - LM(1, a)) & x)
//DEBUG
#define FK puts("Fuck here!")
#define PA(s, c, a, b, p, f){\
	printf(s);\
	Rep(c, a, b) printf(p, (f));\
	puts("");}
//Constant
#define MAXN (22)
//Type-Alias
typedef long long LL;
typedef long double LD;
typedef int AI[MAXN];
typedef double AD[MAXN];
typedef LL ALL[MAXN];
typedef LD ALD[MAXN];

int a, b;
LL C[MAXN][MAXN];

int main()
{
#if 1
	freopen("test.txt", "r", stdin);
#endif
	//Initialize
	MS(C, 0);
	C[0][0] = 1;
	Rep(i, 1, MAXN)
	{
		C[i][0] = 1;
		Rep(j, 1, MAXN)
			C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
	}
	//Solve
	while (scanf("%d%d", &a, &b), a != -1 || b != -1)
	{
		printf("%d+%d", a, b);
		printf(C[a + b][a] == a + b? "=": "!=");
		printf("%d\n", a + b);
	}
#if 0
	freopen("test.out", "w", stdout);
#endif
	return 0;
}
