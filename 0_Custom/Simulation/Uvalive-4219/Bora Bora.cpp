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
using namespace std;
#define Rep(c, a, b) for (int c = (a); c < (b); c++)
#define Nre(c, a, b) for (int c = (a); c > (b); c--)
#define MAXN (20)

struct Card
{
	int r;
	char s[3];
	Card inp()
	{
		scanf("%d%s", &r, s);
		return *this;
	}
	friend bool operator == (Card p, Card q)
	{
		return p.r == q.r || p.s[0] == q.s[0];
	}
	friend bool operator < (Card p, Card q)
	{
		if (p.r != q.r) return p.r > q.r;
		return p.s[0] > q.s[0];
	}
};

int P, M, N;

int main()
{
#if 1
	freopen("test.txt", "rt", stdin);
#endif

	while (scanf("%d%d%d", &P, &M, &N), P || M || N)
	{
		vector<Card> HC[MAXN];
		queue<Card> DC;
		Card tc, cc;
		int cp = 0, np = 0, cd = 1, ps = 0, dr = 1, uu = 1; 

		Rep(i, 0, P * M) HC[i / M].push_back(tc.inp());
		cc = tc.inp();
		Rep(i, P * M + 1, N) DC.push(tc.inp());
		for (int rd = 0; ; rd++)
		{
			ps = 1, dr = 0;
			if (uu)
			{
				if (cc.r == 12) cd *= -1;
				if (cc.r == 7) ps = 2, dr = 2;
				if (cc.r == 1) ps = 2, dr = 1;
				if (cc.r == 11) ps = 2;
				uu = 0;
			}
			np = (cp + bool(rd) * cd + P) % P;
			while (dr--) HC[np].push_back(DC.front()), DC.pop();
			if (!rd) ps--;
			cp = (cp + ps * cd + P) % P;
			sort(HC[cp].begin(), HC[cp].end());
			dr = 1;
			Rep(i, 0, HC[cp].size()) if (HC[cp][i] == cc)
			{
				cc = HC[cp][i];
				HC[cp].erase(HC[cp].begin() + i);
				dr = 0;
				uu = 1;
				break;
			}
			if (!HC[cp].size()) break;
			if (dr)
			{
				tc = DC.front(), DC.pop();
				if (tc == cc) cc = tc, uu = 1;
				else HC[cp].push_back(tc);
			}
		}
		printf("%d\n", cp + 1);
	}
	return 0;
}
