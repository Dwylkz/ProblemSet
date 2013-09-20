// BEGIN CUT HERE

// END CUT HERE
#line 5 "ConvertibleStrings.cpp"
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
typedef pair<int, int> pii_t;
typedef map<string, int> mvi_t;
typedef map<pii_t, int> mpi_t;
#define _i(t) t::iterator


class ConvertibleStrings {
  static const int N = 1e5;
 public:
  int leastRemovals(string A, string B) {
    string &a = A, &b = B;
    int n = A.length(), p[9] = {0, 1, 2, 3, 4, 5, 6, 7, 8}, rv = n;
    for ( ; ; ) {
      int t = 0;
      for (int i = 0; i  n; i++)
        if (b[i]-'A' != p[a[i]-'A']) t++;
      rv = min(rv, t);
      if (!next_permutation(p, p+9) || !rv) break;
    }
    return rv;
  }
};
