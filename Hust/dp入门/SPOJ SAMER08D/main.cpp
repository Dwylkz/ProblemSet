#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
const int MAXN = 1005;
//Global
int k, dp[MAXN][MAXN];
char a[MAXN] = {'$'}, b[MAXN] = {'$'};
//Main
int main(){
#if 1
	freopen("test.txt", "r", stdin);
	freopen("test.out", "w", stdout);
#endif
	memset(dp, 0, sizeof dp);
	while (~scanf("%d", &k), k){
		scanf("%s%s", a + 1, b + 1);
		int la = strlen(a), lb = strlen(b);
		for (int i = 1; i < la; i++)
			for (int j = 1; j < lb; j++){
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				for (int l = 0;  i - l > 0 && j - l > 0 && a[i - l] == b[j - l];)
					if (++l >= k) dp[i][j] = max(dp[i][j], dp[i - l][j - l] + l);
			}
#if 0
		for (int i = 1; i < la; i++){
			for (int j = 1; j < lb; j++)
				printf(" %4d", dp[i][j]);
			puts("");
		}
#endif
		printf("%d\n", dp[la - 1][lb - 1]);
	}
	return 0;
}
