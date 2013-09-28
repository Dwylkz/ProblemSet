// BEGIN CUT HERE

// END CUT HERE
#line 5 "LittleElephantAndPermutationDiv2.cpp"
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
#include <numeric>
#include <functional>
using namespace std;

class LittleElephantAndPermutationDiv2 {
	static const int N = 1e5;
	public:
  typedef long long LL;
	long long getNumber(int N, int K) {
		int n = N, k = K, p[12];
    LL rv = 0, fac = 1;
    for (int i = 0; i < n; i++) {
      p[i] = i+1;
      fac *= i+1;
    }
    for ( ; ; ) {
      int sm = 0;
      for (int i = 0; i < n; i++) sm += max(i+1, p[i]);
      if (sm >= k) rv++;
      if (!next_permutation(p, p+n)) break;
    }
    return rv*fac;
	}
};
