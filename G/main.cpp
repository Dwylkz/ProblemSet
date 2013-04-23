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
//Round
struct Round{
	int w, l;
	Round(int _w = 0, int _l = 0){
		w = _w, l = _l;
	}
};
//Player
struct Player{
	int h, p;
	Player(){
		h = p = 0;
	}
	int get(int _p){
		h++, p += _p;
		if (p > 21) return 1;
		if (h == 5) return 2;
		if (p > 15) return 3;
		return 0;
	}
};
//Global
int n, k, r[MAXN];
char a[MAXN];
//Hindu-Suffle
void HS(int p, int q, int i = 0, int j = 0){
	for (i = p; i < q; i++) r[j++] = a[i];
	for (i = 0; i < p; i++) r[j++] = a[i];
	for (i = q; i < n; i++) r[j++] = a[i];
}
//Black-Jack
Round BJ(int s){
	Player P, D;
	int i = s;
	P.get(r[i++]), D.get(r[i++]);
	int jp = P.get(r[i++]), jd = D.get(r[i++]);
	while (!jp){
		jp = P.get(r[i++]);
	}
	if (jp == 1){
		return Round(0, i - s);
	}
	if (jp == 2){
		return Round(1, i - s);
	}
	while (!jd){
		jd = D.get(r[i++]);
	}
	if (jd == 1){
		return Round(1, i - s);
	}
	if (jd == 2){
		return Round(0, i - s);
	}
	if (P.p > D.p){
		return Round(1, i - s);
	}
	return Round(0, i - s);
}
//Main
int main(){
#if 1
	freopen("test.txt", "r", stdin);
	//freopen("test.out", "w", stdout);
#endif
	int Case = 1;
	while (~scanf("%d%d", &n, &k)){
		for (int i = 0; i < n; i++){
			scanf("%1s", a + i);
			if (a[i] == 'A'){
				a[i] = 1;
			}
			else if (isdigit(a[i])){
				a[i] -= '0';
			}
			else{
				a[i] = 10;
			}
		}
#if 0
		printf("Deck:");
		for (int i = 0; i < n; i ++){
			printf(" %d", a[i]);
		}
		puts("");
#endif
		int res = 0;
		for (int p = 0; p < n; p++){
			for (int q = p; q < n; q++){
				int _res = 0;
				HS(p, q + 1);
				for (int i = 0; i <= n - k;){
					Round t = BJ(i);
					_res += t.w, i += t.l;
				}
				res = max(res, _res);
			}
		}
		printf("Case %d: %d\n", Case++, res);
	}
	return 0;
}
