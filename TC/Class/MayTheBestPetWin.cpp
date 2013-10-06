#include <cstdio>
#include <bitset>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <map>
#include <string>
#include <vector>
using namespace std;
typedef long long ll_t;
#define _be begin()
#define _en end()
#define _i(t) t::iterator
typedef vector<int> vi_t;
typedef vector<string> vs_t;
typedef map<int, int> mii_t;
typedef pair<int, int> pii_t;
#define _fi first
#define _se second
const int N = 5e5+10;

class MayTheBestPetWin {
  public:
    typedef vector<int> vi_t;
    int dp[N];
    int go(vi_t &a, vi_t &b) {
      int sum = 0;
      memset(dp, 0, sizeof(dp));
      for (int i = 0; i < a.size(); i++) sum += a[i];
      dp[sum] = 1;
      int result = sum;
      for (int i = 0; i < a.size(); i++)
        for (int j = 0; j < N; j++)
          if (dp[j]) {
            int v = j-a[i]-b[i];
            result = min(result, abs(v));
            if (v >= 0) dp[v] = 1;
          }
      return result;
    }
    int calc(vector <int> A, vector <int> B) {
      return max(go(A, B), go(B, A));
    }
};
