/*
 Apparently, it's kind of simulation stuff.
 I think It's easy until i find a little trick,
 which gave me 6wa as gifts :(
 The trick is that the driver may join anthor team
 while his current score will add to his current team
 before his team-changing;
 
 Btw, we can use scanf(const char *format, ...) to solve Troublesome
 input problems i.e leading/trailing space, get whole line....
 Of course, u can ignore this thing if u r a master of iostream
 then I will show my respect to you :)

 Conversion specification in format is a powerful tool would help you
 when you manage the FU*King I/O problem above.

 Instance:
 skip all space and discard it: %*[ ]
 get line until cursor encounter a '.': %[^.]
 get line from current cursor and discard it: %*[^\n]

 Last but not less, clear your mind :)
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
//DEBUG
#define FK puts("Fuck here!")
#define PA(s, c, a, b, p, f){\
	printf(s);\
	Rep(c, a, b) printf(p, f);\
	puts("");}
//Constant
#define MAXN (512)
//Type-Alias
typedef long long LL;
typedef long double LD;
typedef int AI[MAXN];
typedef double AD[MAXN];
typedef LL ALL[MAXN];
typedef LD ALD[MAXN];

struct Dri
{
	string ln, fn;
	int sc, tm;
	vector<int> pl;
	void inp()
	{
		sc = tm = 0;
		pl.resize(8);
		Rep(i, 0, 8) pl[i] = 0;
		char buf[MAXN];
		scanf("%s", buf);
		fn = buf;
		scanf("%s", buf);
		ln = buf;
	}
	friend bool operator == (Dri p, Dri q)
	{
		return p.ln == q.ln && p.fn == q.fn;
	}
	friend bool operator < (Dri p, Dri q)
	{
		if (p.sc != q.sc) return p.sc > q.sc;
		if (p.pl != q.pl) return p.pl > q.pl;
		if (p.ln != q.ln) return p.ln < q.ln;
		return p.fn < q.fn;
	}
};
vector<Dri> dri;
int Dfin(Dri td)
{
	Rep(i, 0, dri.size()) if (dri[i] == td) return i;
	dri.push_back(td);
	return dri.size() - 1;
}

struct Tea
{
	string ne;
	int sc;
	void inp()
	{
		sc = 0;
		char buf[MAXN];
		scanf("%*[ ]%[^.]%*[^\n]\n", buf);
		ne = buf;
	}
	friend bool operator == (Tea p, Tea q)
	{
		return p.ne == q.ne;
	}
	friend bool operator < (Tea p, Tea q)
	{
		if (p.sc != q.sc) return p.sc > q.sc;
		return p.ne < q.ne;
	}
};
vector<Tea> tea;
int Tfin(Tea tt)
{
	Rep(i, 0, tea.size()) if (tea[i] == tt) return i;
	tea.push_back(tt);
	return tea.size() - 1;
}

int sea, rk[8] = {10, 8, 6, 5 ,4, 3, 2, 1};
char buf[MAXN];

int main()
{
#if 1
	freopen("test.txt", "r", stdin);
#endif
	int Cas = 1;
	while (scanf("%d\n", &sea), sea) 
	{
		//Initialize
		dri.clear();
		tea.clear();
		while (sea--)
		{
			scanf("%*[^\n]\n%*[^\n]\n");
			Rep(i, 0, 8)
			{
				scanf("%*s");
				Dri td; td.inp();
				int x = Dfin(td);
				dri[x].pl[i]++;
				dri[x].sc += rk[i];
				Tea tt; tt.inp();
				dri[x].tm = Tfin(tt);
				tea[dri[x].tm].sc += rk[i];
			}
			scanf("%*[^\n]\n");
		}
		//Solve
		sort(dri.begin(), dri.end());
		sort(tea.begin(), tea.end());
		printf("Season %d:\nDrivers Standing:\n", Cas++);
		Rep(i, 0, dri.size())
		{
			dri[i].fn += ' ' + dri[i].ln;
			printf("%-25s %d\n", dri[i].fn.c_str(), dri[i].sc);
		}
		puts("");
		printf("Teams Standing:\n");
		Rep(i, 0, tea.size())
			printf("%-25s %d\n", tea[i].ne.c_str(), tea[i].sc);
		puts("");
	}
	return 0;
}
