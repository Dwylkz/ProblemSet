#line 90 "FlippingBitsDiv2.cpp"
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
#define DX(x) 	((int)x.size())
#define WJ 	push_back
#define WC	pop_back
#define DD(x)	x::iterator
#define KS(x)	x.begin()
#define JS(x)	x.end()

class FlippingBitsDiv2 {
	static const int N = 3e3+10;
  static const int inf = 0x7f7f7f7f;
	public:
  int w[N], c[N], f[N][2], g[N][2];
  void dp(int h[][2], int n) {
    for (int i = 0; i < n; i++) {
      int h0, h1;
      if (!i) {
        h0 = h1 = 0;
      } else {
        h0 = h[i-1][0];
        h1 = h[i-1][1];
      }
      h[i][0] = min(h1+c[i]+1, h0+w[i]);
      h[i][1] = min(h0+w[i]+1, h1+c[i]);
    }
#if 1
    puts(__func__);
    for (int i = 0; i < n; i++)
      printf(" %2d", h[i][0]);
    puts("");
    for (int i = 0; i < n; i++)
      printf(" %2d", h[i][1]);
    puts("");
#endif
  }
	int getmin(vector <string> S, int M) {
		string s = "";
    for (int i = 0; i < S.size(); i++) s += S[i];
    int n = s.length()/M;
    for (int i = 0; i < n; i++) {
      w[i] = 0;
      for (int j = i*M, k = j+M; j < k; j++) w[i] += s[j] == '1';
      c[i] = M-w[i];
    }
    dp(f, n);
    reverse(w, w+n);
    reverse(c, c+n);
    dp(g, n);
    int ans = inf;
    ans = min(f[n-1][1], g[n-1][1]);
    for (int i = 0; i < n-1; i++)
      ans = min(ans, min((f[i][1]+g[n-i-2][1]), f[i][0]+g[n-i-2][0]+1));
    return ans;
	}
};
