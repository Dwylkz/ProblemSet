/*
	Definition:
		1. st[i, j] as we have found i categories and j subsystems.
		2. ev[i, j] as the expected move from st[i, j] to st[n, s].

	According to the statement of the problem,
	we can get ev[i, j] from ev[i, j], ev[i + 1, j], ev[i, j + 1], ev[i + 1, j + 1].
		ev[i + 1, j] indicate that we will get a new category from next bug,
		ev[i, j + 1] indicate that we will get a new subsystem from next bug,
		ev[i + 1, j + 1] means that we will get both from next bug;
		ev[i, j] as we will get nothing new.

	As the odds to get any of categories or any of subsystem will not decrease,
	and each of 4 moves above has many status itself.
	Instance:
		"(ev[i + 1, j] + 1) * (n - i) * j / n * s" as
		the expected value sum of (n - i) * j possible cases which
		takes us ev[i + 1, j] + 1 expected steps
		from st[i, j] to st[n, s] with
		1 / n probability of getting one of n - i new categories and
		1 / s probability of getting one of j old subsystems.

	Hence, we have
		*. ev[i, j] = (ev[i + 1, j] + 1) * (n - i) * j / n * s
					+ (ev[i, j + 1] + 1) * n * (s - j) / n * s
					+ (ev[i + 1, j + 1] + 1) * (n - i) * (s - j) / n * s
					+ (ev[i, j] + 1) * i * j / n * s;
	Move the last part to the leftside to eliminate the self-loop
	and merge constant parts. It will take two steps to calculate ev[i, j].
		1. ev[i, j] = ev[i + 1, j] * (n - i) * j
					+ ev[i, j + 1] * n * (s - j)
					+ ev[i + 1, j + 1] * (n - i) * (s - j)
					+ n * s;
		2. ev[i, j] /= n * s - i * j;
	The reason i did this is to prevent the precision losing.

	Obviously, ev[n, s] = 0.
	Hence, We can solve the problem by iteration;
 */
//Header
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
//Macro
//STL-Alias
#define UN(c, a) unique(c, a)
#define MS(c, a) memset(c, a, sizeof c)
#define FLC(c, a ,b) fill(c, c + a, b)
#define LOS(c, a, b) lower_bound(c, a, b)
#define UPS(c, a, b) upper_bound(c, a, b)
//Syntax-Alias
#define Rep(c, a, b) for (int c = (a); c < (b); c++)
#define Nre(c, a, b) for (int c = (a); c > (b); c--)
//DEBUG
#define FK puts("Fu*k here!")
#define PA(s, c, a, b, p, f){\
	printf(s);\
	Rep(c, a, b) printf(p, (f));\
	puts("");}
//Constant
#define INFI (0x7fffffff)
#define MOD ()
#define MAXN (1010)
//Type-Alias
typedef long long LL;
typedef long double LD;
typedef int AI[MAXN];
typedef bool AB[MAXN];
typedef double AD[MAXN];
typedef LL ALL[MAXN];
typedef LD ALD[MAXN];

int n, s;
LD ev[MAXN][MAXN];

int main()
{
#if 1
	freopen("test.txt", "r", stdin);
#endif
	while (~scanf("%d%d", &n, &s))
	{
		//Initialize
		//Solve
		LD ns = n * s;
		ev[n][s] = 0;
		Nre(i, n - 1, -1)
			ev[i][s] = ((ev[i + 1][s] * (n - i) * s) + ns) / (ns - i * s);
		Nre(j, s - 1, -1)
			ev[n][j] = ((ev[n][j + 1] * n * (s - j)) + ns) / (ns - n * j);
		Nre(i, n - 1, -1) Nre(j, s - 1, -1)
		{
			ev[i][j] = ev[i + 1][j] * (n - i) * j + ev[i][j + 1] * i * (s - j);
			ev[i][j] += ev[i + 1][j + 1] * (n - i) * (s - j) + ns;
			ev[i][j] /= ns - i * j;
		}
		printf("%.4Lf\n", ev[0][0]);
	}
	return 0;
}
