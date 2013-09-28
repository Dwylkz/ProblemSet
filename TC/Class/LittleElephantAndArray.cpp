// BEGIN CUT HERE

// END CUT HERE
#line 5 "LittleElephantAndArray.cpp"
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

class LittleElephantAndArray {
	static const int N = 1e2+10;
	static const int mod = 1e9+7;
  typedef long long LL;
	public:
  struct dp_t {
    LL k;
    int c;
    dp_t(LL _k = 0, int _c = 0): k(_k), c(_c) {}
    void plus(int _c) {
      (c += _c) %= mod;
    }
    friend bool operator < (const dp_t &lhs, const dp_t &rhs) {
      return lhs.k < rhs.k;
    }
  };
  typedef vector<dp_t> vd_t;
  vd_t dp[2];
  struct dpInit_t {
    vd_t *f;
    void dfs(LL x, LL o, LL y, int b) {
      if (!o) {
        if (b) f->push_back(dp_t(y, 0));
      } else {
        dfs(x%o, o/10, y*10+x/o, b+1);
        dfs(x%o, o/10, y, b);
      }
    }
    void operator () (LL x, vd_t *_f) {
      f = _f;
      f->clear();
      LL o = 1;
      for (LL t = x; t > 9; t /= 10) o *= 10;
      dfs(x, o, 0, 0);
      sort(f->begin(), f->end());
    }
  } dpInit;
	int getNumber(long long A, int n) {
    n++;
    vector<LL> a(n);
    iota(a.begin(), a.end(), A);
    vd_t *f = dp, *g = dp+1;
    dpInit(0, f);
    (*f)[0].plus(1);
    for (int i = 0; i < n; i++) {
      dpInit(a[i], g);
      for (int j = 0; j < g->size(); j++) {
        int ub = upper_bound(f->begin(), f->end(), (*g)[j])-f->begin();
        if (ub) (*g)[j].plus((*f)[ub-1].c);
        if (j) (*g)[j].plus((*g)[j-1].c);
      }
      swap(f, g);
    }
		return f->back().c;
	}
};
