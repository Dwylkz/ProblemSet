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
namespace Dwylkz{
	//Type
	typedef unsigned int UI;
	typedef long long LL;
	typedef long double LD;
	//Constant
	const LL INFL = ~0ull >> 1;
	const int INFI = ~0u >> 1;
	const int MAXN = 50005;
	const int MOD = 1e9 + 7;
	//Array
	typedef int AI[MAXN];
	typedef bool AB[MAXN];
	typedef double AD[MAXN];
	typedef LL ALL[MAXN];
	typedef LD ALD[MAXN];
}
using namespace Dwylkz;
//STL
#define MS(c, a) memset(c, a, sizeof c)
//Syntax
#define Rep(c, a, b) for (int c = (a); c < (b); c++)
#define Nre(c, a, b) for (int c = (a); c > (b); c--)
//DEBUG
#define DEBUG 0
#define FK puts("Fu*k here!")

AI f, s, drp;
vector<int> id;
int n;

inline void scan(int &x){
	char ch;
	while(ch = getchar())
		if(ch >= '0' && ch <= '9') break;
	x = ch - '0';
	while(ch = getchar()){
		if(!(ch >= '0' && ch <= '9')) break;
		x = x*10 + ch - '0';
	}
}

bool cmp(int p, int q){
	if (f[p] != f[q]) return f[p] > f[q];
	return p < q;
}

int main()
{
#if 1
	freopen("test.txt", "r", stdin);
	freopen("test.out", "w", stdout);
#endif
	int T, Cas = 1;
	//scanf("%d", &T);
	scan(T);
	while (T--)
	{
		MS(drp, 0);
		//scanf("%d", &n);
		scan(n);
		int mx = -1, mi = -1;
		Rep(i, 0, n){
			//scanf("%d%d", f + i, s + i);
			scan(f[i]);scan(s[i]);
			if (f[i] > mx){
				mx = f[i];
				mi = i;
			}
		}
		printf("Case #%d:\n", Cas++);
		drp[mi] = 1;
		printf("%d", mi + 1);
		Rep(t, 0, 501){
		 	mx = -1, mi = -1;
			Rep(i, 0, n) if (!drp[i]){
				f[i] += s[i];
				if (f[i] > mx){
					mx = f[i];
					mi = i;
				}
			}
			if (mi < 0) break;
			printf(" %d", mi + 1);
			drp[mi] = 1;
		}
		id.clear();
#if DEBUG
		printf("\nf:");
		Rep(i, 0, n) if (drp[i]) printf(" %d", i + 1);
		puts("");
#endif
		Rep(i, 0, n) if (!drp[i])
			id.push_back(i);
		sort(id.begin(), id.end(), cmp);
		Rep(i, 0, id.size()) printf(" %d", id[i] + 1);
		puts("");
	}
	return 0;
}
