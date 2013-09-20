// BEGIN CUT HERE

// END CUT HERE
#line 5 "TheArithmeticProgression.cpp"
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

class TheArithmeticProgression {
	static const int N = 1e5;
	public:
	double minimumChange(int a, int b, int c) {
    if (a+c == b*2) return 0.;
    if (a+c < b*2) return (2*b-(a+c))/2.;
    return (a+c-2*b)/2.;
	}
};
