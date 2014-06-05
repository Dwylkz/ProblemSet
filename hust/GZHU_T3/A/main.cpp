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
	const int MAXN = 1000005;
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
#define FK puts("Fu*k here!")
//Const
const int MAXM = 1005;

//PG
AB pg;
vector<int> pri;
void PG_ini(){
	MS(pg, 0); pri.clear();
	for (int i = 2; i < MAXN; i += 2) if (!pg[i]){
		pri.push_back(i);
		for (int j = i + i; j < MAXN; j += i) pg[j] = 1;
		if (i < 3) i--;
	}
#if 0
	printf("prime = %d:\n", pri.size());
	Rep(i, 1, pri.size() + 1){
		printf(" %4d", pri[i - 1]);
		if (i % 10 == 0) puts("");
	}
#endif
}
//DP
LL C[MAXM][MAXM];
void C_ini(){
    C[0][0] = 1;
    Rep(i, 1, MAXM){
        C[i][0] = 1;
        Rep(j, 1, i + 1) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
    }
#if 0
	puts("C:");
	Rep(i, 0, 405){
		Rep(j, 0, i + 1) printf(" %lld", C[i][j]);
		puts("");
	}
#endif
}

int n, ph;
AI pi, pn;
LL S[MAXM][MAXM], dp[MAXM];

void S_ini(){
	MS(S, 0);
	S[0][0] = 1;
	Rep(n, 1, MAXM){
		S[n][0] = 1;
		Rep(k, 1, MAXM)
			S[n][k] = (S[n][k - 1] + S[n - 1][k - 1] + k * S[n - 1][k] % MOD) % MOD;
	}	
#if 1
	puts("S:");
	Rep(n, 1, 401){
		Rep(k, 1, 21) printf(" %lld", S[n][k]);
		puts("");
	}
#endif
}

int main()
{
#if 1
	freopen("test.txt", "r", stdin);
	freopen("test.out", "w", stdout);
#endif
	C_ini();
	PG_ini();
	S_ini();
	while (~scanf("%d", &n))
	{
		MS(pi, 0); MS(pn, ph = -1);
		Rep(i, 0, n){
			int bi;
			scanf("%d", &bi);
			Rep(i, 0, pri.size()){
				int p = pri[i];
				for (; bi % p == 0; bi /= p){
					if (!pi[p]){
						pn[p] = ph;
						ph = p;
					}
					pi[p]++;
				}
				if (bi < 2) break;
			} 
		}
		MS(dp, 0);
		dp[1] = 1;
		Rep(i, 2, n + 1){
			LL mul = 1, sub = 0;
			for (int p = ph; p != -1; p = pn[p])
				mul = (mul * S[pi[p]][i]) % MOD;
			Rep(j, 1, i) sub = (sub + dp[j] * C[i][j] % MOD);
			dp[i] = (mul - sub + MOD) % MOD;
		}
		printf("%lld\n", dp[n]);
#if 1
		for (int p = ph; p != -1; p = pn[p])
			printf("%3d: %3d\n", p, pi[p]);
#endif
	}
	return 0;
}
