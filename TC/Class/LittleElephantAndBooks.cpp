// BEGIN CUT HERE

// END CUT HERE
#line 5 "LittleElephantAndBooks.cpp"
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

class LittleElephantAndBooks {
	static const int N = 1e5;
	public:
  typedef vector<int> vi_t;
	int getNumber(vector <int> pages, int number) {
    vi_t &p = pages;
    int n = number;
    sort(p.begin(), p.end());
    int mn = 0;
    for (int i = 0; i < n-1; i++) mn += p[i];
    return mn+p[n];
	}
};
