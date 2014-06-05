#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;
#define MAXN (13)
#define MAXSS (531441)
#define MAXS (4151)
#define LLU __int64
#define L(x) (1 << x)
#define R(x) ((1 << x) << 1)
#define LR(x, y) ((1 << x) << (y - 1))
#define GET(x, y) ((x >> y) & 3)

char M[MAXN][MAXN];
int t, n, m, ei, ej;

struct State
{
	LLU s, c;
} ts;
vector<State> S[2];

struct Hash
{
	vector<LLU> hash[MAXS];
	void clr()
	{
	    int i;
		for (i = 0; i < MAXS; i++)
            hash[i].clear();
	}
	void ins(LLU x, LLU add)
	{
		LLU key = x % MAXS;
		int i;
		for (i = 0; i < hash[key].size(); i++)
            if (S[!t][hash[key][i]].s == x)
                break;
        if (i == hash[key].size())
        {
            hash[key].push_back(S[!t].size());
            S[!t].push_back(ts);
        }
        else S[!t][hash[key][i]].c += add;
	}
} H;

LLU find(LLU s, LLU i, bool np)
{
	int b = 1, p = 2, d = 1;
	if (np) swap(p, d);
	while (b)
	{
		if (np) i += 2;
		else i -= 2;
		if (GET(s, i) == p) b++;
		if (GET(s, i) == d) b--;
	}
	return i;
}

LLU SCDP()
{
	LLU l, u, li, ui, b, res = 0;
	int i, j, k;

	t = 0;
	ts.s = 0;
	ts.c = 1;
	S[0].clear();
	S[0].push_back(ts);
	for (i = 0; i < n; i++)
	{
		li = 0; ui = 2;
		for (j = 0; j < m; j++)
		{
			H.clr();
			S[!t].clear();
			for (k = 0; k < S[t].size(); k++)
			{
				ts = S[t][k];
				l = GET(ts.s, li);
				u = GET(ts.s, ui);
				if (!M[i][j])
				{
					if (!l && !u) H.ins(ts.s, ts.c);
				}
				else
				{
					if (!l && !u)
					{
					    if (i + 1 < n && j + 1 < m && M[i + 1][j] && M[i][j + 1]) //## -> ()
                        {
                            ts.s += L(li) + R(ui);
                            H.ins(ts.s, ts.c);
                        }
					}
					else if (!l || !u)
					{
						if (l && !u)
						{
							if (i + 1 < n && M[i + 1][j]) //*# -> *#
							{
								H.ins(ts.s, ts.c);
							}
							if (j + 1 < m && M[i][j + 1]) //*# -> #*
							{
								ts.s += LR(ui, l) - LR(li, l);
								H.ins(ts.s, ts.c);
							}
						}
						else if (!l && u)
						{
							if (j + 1 < m && M[i][j + 1]) //#* -> #*
							{
								H.ins(ts.s, ts.c);
							}
							if (i + 1 < n && M[i + 1][j]) //#* -> *#
							{
								ts.s += LR(li, u) - LR(ui, u);
								H.ins(ts.s, ts.c);
							}
						}
					}
					else if (l && u)
					{
						if (l == 1 && u == 2) // () -> ##
						{
							if (i == ei && j == ej)
								res += ts.c;
						}
						else
						{
							if (l == 1 && u == 1) //(( -> ##
							{
							    b = find(ts.s, ui, true);
								ts.s += L(b) - R(b) - L(li) - L(ui);
							}
							else if (l == 2 && u == 2) //)) -> ##
							{
							    b = find(ts.s, li, false);
								ts.s += R(b) - L(b) - R(li) - R(ui);
							}
							else if (l == 2 && u == 1) //)( -> ##
							{
								ts.s -= R(li) + L(ui);
							}
							H.ins(ts.s, ts.c);
						}
					}
				}
			}//K end.
			t ^= 1;
			li += 2; ui += 2;
		}//J end.
		for (j = 0; j < S[t].size(); j++)
			S[t][j].s <<= 2;
	}//I end.

	return res;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("test.txt", "rt", stdin);
#endif
	int i, j;

	while (~scanf("%d%d", &n, &m))
	{
		for (i = 0; i < n; i++)
			scanf("%s", M[i]);
		for (i = 0; i < n; i++)
			for (j = 0; j < m; j++)
				if (M[i][j] == '.')
				{
					M[i][j] = true;
					ei = i;
					ej = j;
				}
				else M[i][j] = false;
		printf("%I64d\n", SCDP());
		//break;
	}

	return 0;
}

