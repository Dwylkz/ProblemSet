#line 74 "GearsDiv2.cpp"
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;
typedef vector<int> vi_t;
typedef vector<vi_t> vvi_t;

class GearsDiv2 {
  public:
    int f[55][2];
    int dp(string s) {
      // f[i][j] indicates the optimize answser when 
      // we keep(j:1) i-th gear or not(j:0).
      int n = s.length();
      memset(f, 0, sizeof(f));
      f[0][0] = 1;
      for (int i = 1; i < n; i++) {
        f[i][1] = s[i] == s[i-1]? f[i-1][0]: min(f[i-1][0], f[i-1][1]);
        f[i][0] = min(f[i-1][0], f[i-1][1])+1;
      }
      return min(f[n-1][0], f[n-1][1]);
    }
    int getmin(string Directions) {
      string s = Directions;
      int n = s.length();
      if (s[0] != s[n-1]) return dp(s);
      return 1+min(dp(s.substr(0, n-1)), dp(s.substr(1, n-1)));
    }
};


// Powered by FileEdit
