// BEGIN CUT HERE

// END CUT HERE
#line 5 "AstronomicalRecords.cpp"
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;

class AstronomicalRecords {
  static const int N = 50+10;
  typedef long long LL;
	public:
  int gcd(int a, int b) {
    return b? gcd(b, a%b): a;
  }
  int n, m, a[N], b[N], dp[N][N];
  void init(vector<int> &s, int *t) {
    int g = 0;
    for (int i = 0; i < s.size(); i++) g = gcd(g, s[i]);
    for (int i = 0; i < s.size(); i++) t[i] = s[i]/g;
  }
  int go(int fa, int fb) {
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++)
        if (1ll*a[i-1]*fa == 1ll*b[j-1]*fb) dp[i][j] = dp[i-1][j-1]+1;
        else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    return dp[n][m];
  }
	int minimalPlanets(vector <int> A, vector <int> B) {
    n = A.size(), m = B.size();
    init(A, a), init(B, b);
    int result = n+m;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        result = min(result, n+m-go(b[j], a[i]));
    return result;
	}
};
