/*
   As it's only 9^9 status at most(in fact, it's not that much),
   We can calculate all the status,
   which can be reached from initial status 123456789 and
   the number of steps not larger than 9, in advance.
*/
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
#define FK puts("Fu*k here!")
#define PA(s, c, a, b, p, f){\
	printf(s);\
	Rep(c, a, b) printf(p, (f));\
	puts("");}
//Constant
#define MOD (1000000000LL)
#define MAXN (1 << 16)
//Type-Alias
typedef long long LL;
typedef long double LD;
typedef int AI[MAXN];
typedef double AD[MAXN];
typedef LL ALL[MAXN];
typedef LD ALD[MAXN];

//H[s] as Minimum steps to state s 
map<LL, int> H; 
//Four kinds of rotate
int mr[4][4] = {{0, 1, 4, 3}, {1, 2, 5, 4}, {3, 4, 7, 6}, {4, 5, 8, 7}}; 
//Encode
int EC(int b[3][3])
{
	int s = 0;
	Rep(i, 0, 3) Rep(j, 0, 3)
		s = s * 10 + b[i][j];
	return s;
}
//Decode
void DC(int s, int b[3][3])
{
	Nre(i, 2, -1) Nre(j, 2, -1)
	{
		b[i][j] = s % 10;
		s /= 10;
	}
}
//Rotate function, d indicate direction
int rot(LL s, int *m, int d)
{
	int cp = 0, x = m[cp] / 3, y = m[cp] % 3, b[3][3];
	DC(s, b);
	int t = b[x][y];
	Rep(j, 1, 4)
	{
		int np = (cp + d + 4) % 4, tx = m[np] / 3, ty = m[np] % 3;
		b[x][y] = b[tx][ty];
		cp = np;
		x = tx;
		y = ty;
	}
	b[x][y] = t;
	return EC(b);
}
//Pretreatment 
void H_ini()
{
	H.clear();
	queue<LL> Q;
	LL u = 123456789;
	H[u] = 1;
	Q.push(u);
	while (!Q.empty())
	{
		u = Q.front(); Q.pop();
		if (H[u] > 8) continue;
		Rep(i, 0, 4) Rep(j, -1, 2)
		{
			LL v = rot(u, mr[i], j);
			if (!H[v])
			{
				H[v] = H[u] + 1;
				Q.push(v);
			}
			j++;
		}
	}
}

LL s;

int main()
{
#if 1
	freopen("test.txt", "r", stdin);
#endif
	//Initialize
	int Cas = 1;
	H_ini();
	//Solve
	while (scanf("%lld", &s), s)
	{
		printf("%d. ", Cas++);
		LL p = s / MOD;
		s %= MOD;
		if (H[s] && H[s] - 1 <= p) printf("%d\n", H[s] - 1);
		else puts("-1");
	}
	return 0;
}
