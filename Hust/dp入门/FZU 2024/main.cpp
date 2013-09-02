#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
const int MAXN = 1005;
//Global
struct LCS{
	int l, p;
	LCS(int _l = 0, int _p = -1){
		l = _l, p = _p;
	}
	friend bool operator < (LCS p, LCS q){
		return p.l < q.l;
	}
};
LCS dp[MAXN][MAXN];
int k;
char a[MAXN] = {'$'}, b[MAXN] = {'$'};
int ES(){
	typedef pair<int, int> Same;
}
//Main
int main(){
#if 1
	freopen("test.txt", "r", stdin);
	//freopen("test.out", "w", stdout);
#endif
	for (int i = 0; i < MAXN; i++) dp[i][0] = LCS(0, -1);
	for (int i = 0; i < MAXN; i++) dp[0][i] = LCS(0, -1);
	int T, Case = 1;
	scanf("%d", &T);
	while (T--){
		scanf("%s%s", a + 1, b + 1);
		int la = strlen(a), lb = strlen(b);
		for (int i = 1; i < la; i++)
			for (int j = 1; j < lb; j++){
				dp[i][j] = max(LCS(dp[i - 1][j].l, 2), LCS(dp[i][j - 1].l, 0));
				if (a[i] == b[j])
					dp[i][j] = max(dp[i][j], LCS(dp[i - 1][j - 1].l + 1, 1));
			}
		printf("Case %d: LCS=%d EditStep=%d\n",
				Case++, dp[la - 1][lb - 1].l, ES());
	}
	return 0;
}
