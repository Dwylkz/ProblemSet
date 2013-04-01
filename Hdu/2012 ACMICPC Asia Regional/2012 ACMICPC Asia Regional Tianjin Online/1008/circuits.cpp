/*
 Damn it! I should deal with this SCDP instead of Problem 1003,
 And I make a big mistake, I should read all the problem first!

 Errrr...........

 According to the statement, we can only have K-loop.
 That means we need ceil(log2(12 * 12 / 4)) = 6 byte to keep the loop number,
 and 6 + 2 * (12 + 1) byte in total.

 For example

 0 = 00 = .
 1 = 01 = (
 2 = 10 = )

 1010001001000000000000000000000000000000
 |loop||         Bracket                |

 indicate we have 3 loop and ()...........

 Besides, the nesting, I think when there is a bracket-pair nested in at less one
 bracket-pair, we can discard this state.

 ..(..()..)..
      **

 Unfortunately, It was wrong,
 because brackets have the same direction can be merged.

 .((.()..)).. =======> .().()...... or ....()..()..
     **                    **              **

 This could happand unless there exist odd number of bracket-pair.
 The reason is one merger can only merger 2 brackets in on side.
 If we have odd number of bracket-pair, then at least one bracket can't be merged.
 In this condition, the nesting exists and we can drop it precisely.
 Btw, it's not nesscesory to check brackets in both side,
 as the bracket-pair is symmetrical.

 At last, we must make state discrete.
 Because, intuitively, it will be at most 36 * 3^13 = 57395628 state,
 but, actually, it only has about 356800 state at most.
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
//STL
#define MS(c, a) memset(c, a, sizeof c)
//Syntax
#define Rep(c, a, b) for (int c = (a); c < (b); c++)
#define Nre(c, a, b) for (int c = (a); c > (b); c--)
//DEBUG
#define FK puts("Fu*k here!")
//Type
typedef unsigned int UI;
typedef long long LL;
typedef long double LD;
//Constant
const LL INFL = 0x7fffffffffffffffLL;
const int INFI = 0x7fffffff;
const int MAXN = 16;
const int MOD = 1000000007;
//Array
typedef int AI[MAXN];
typedef bool AB[MAXN];
typedef double AD[MAXN];
typedef LL ALL[MAXN];
typedef LD ALD[MAXN];

//Hash_Table
const int MAXS = 131313;
struct HS{
	LL k;
	int id, next;
};
struct HT{
	vector<HS> H;
	int L[MAXS];
	void ini(){
		H.clear(); MS(L, -1);
	}
	int cai(LL k, int id){
		int x = k % MAXS;
		for (int i = L[x]; i != -1; i = H[i].next)
			if (H[i].k == k) return H[i].id;
		HS th = {k, id, L[x]};
		L[x] = H.size(); H.push_back(th);
		return id;
	}
};
//BOP
const LL BITW = 2;
const LL BMOD = 3;
inline LL LM(LL x, LL y){
	return x << y; 
}
inline LL RM(LL x, LL y){
	return x >> y;
}
inline LL GB(LL x, LL y){
	return RM(x, y) & BMOD;
}
//Rolling_State_Stack
inline LL K(LL x){
	return x & 63;
}
struct SS{
	LL s;
	int c;
	SS(LL _s = 0, int _c = 0): s(_s), c(_c){}
};
struct RSS{
	HT H;
	int t;
	vector<SS> S[2];
	void ini(){
		H.ini(); S[t = 0].clear(); S[1].clear();
	}
	void rot(){
		t ^= 1; H.ini(); S[!t].clear();
	}
	void ins(LL s, LL c){
		int i = H.cai(s, S[!t].size());
		if (i < S[!t].size()) S[!t][i].c = (S[!t][i].c + c) % MOD;
		else S[!t].push_back(SS(s, c));
	}
	SS top(){
		return S[t][S[t].size() - 1];
	}
	void pop(){
		S[t].pop_back();
	}
	void mov(int d){
		Rep(i, 0, S[t].size()){
			LL k = K(S[t][i].s), s = (S[t][i].s - k) << d;
			S[t][i].s = s | k;
		}
	}
	int siz(){
		return S[t].size();
	}
	LL que(int k){
		Rep(i, 0, S[t].size())
			if (K(S[t][i].s) == k)
				return S[t][i].c;
		return 0;
	}
} H;

int n, m, k;
char M[MAXN][MAXN];

//Plug_DP
int fin(LL x, int i, bool lr)
{
	int tp, b = 1, p = 1, d = 2;
	if (lr) swap(p, d);
	while (b)
	{
		if (lr) i -= 2;
		else i += 2;
		tp = GB(x, i);
		if (tp == p) b++;
		if (tp == d) b--;
	}
	return i;
}
//Count right bracket
bool odd(LL s, LL h)
{
	int cb = 0;
	for (s >>= h; s; s >>= BITW)
	{
		int b = s & BMOD; 
		if (b == 1) cb--;
		if (b == 2) cb++;
	}
	return cb & 1;
}
bool jud(int x, int y)
{
	return 0 <= x && x < n && 0 <= y && y < m && M[x][y] == '.';
}
int PDP()
{
	H.ini(); H.ins(0, 1); H.rot(); 
	Rep(i, 0, n)
	{
		int li = 6, ui = li + BITW;
		Rep(j, 0, m)
		{
			while (H.siz())
			{
				SS ts = H.top(); H.pop();
				if (M[i][j] != '.')
				{
					H.ins(ts.s, ts.c);
					continue;
				}
				int l = GB(ts.s, li), u = GB(ts.s, ui),
					bd = jud(i + 1, j), br = jud(i, j + 1);
				ts.s -= LM(l, li) | LM(u, ui);
				if (!l && !u)
				{
					if (bd && br) H.ins(ts.s | LM(1, li) | LM(2, ui) , ts.c);
				}
				else if (!l || !u)
				{
					if (bd) H.ins(ts.s | LM(l | u, li), ts.c);
					if (br) H.ins(ts.s | LM(l | u, ui), ts.c);
				}
				else if (l && u)
				{
					if (l == 1 && u == 1)
						H.ins(ts.s - LM(1, fin(ts.s, ui, 0)), ts.c);
					if (l == 2 && u == 2)
						H.ins(ts.s + LM(1, fin(ts.s, li, 1)), ts.c);
					if (l == 2 && u == 1) H.ins(ts.s, ts.c);
					if (l == 1 && u == 2)
					{
						if (K(ts.s) < k && !odd(ts.s, ui + BITW))
							H.ins(ts.s + 1, ts.c);
					}
				}
			}
			H.rot(); li += BITW; ui += BITW;
		}
		H.mov(BITW);
	}
	return H.que(k);
}

int main()
{
#if 1
	freopen("test.txt", "r", stdin);
	freopen("test.out", "w", stdout);
#endif
	int T;
	scanf("%d", &T);
	while (T--)
	{
		//Initialize
		scanf("%d%d%d", &n, &m, &k);
		Rep(i, 0, n) scanf("%s", M[i]);
		//Solve
		printf("%d\n", PDP());
	}
	return 0;
}
