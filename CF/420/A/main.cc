#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <set>
using namespace std;

namespace dwylkz {

struct RangeIter: iterator<random_access_iterator_tag, int> {
	int i_;
	RangeIter(int i): i_(i) {}
	RangeIter& operator++() {++i_; return *this;}
	int& operator*() {return i_;}
	bool operator!=(RangeIter range_iter) {return i_ != range_iter.i_;}
};
struct Range: initializer_list<int> {
	typedef initializer_list<int>::iterator RangeIter;
	int h_, o_;
	Range(int h, int o): h_(h), o_(o) {}
	RangeIter begin() {return RangeIter(h_);}
	RangeIter end() {return RangeIter(o_);}
};

}
using namespace dwylkz;

typedef vector<int> VI;

struct Log {
	string op;
	int id;
	static Log FromIo() {
		Log ret;
		cin >> ret.op >> ret.id;
		return ret;
	}
};

int n, m;

int main() {
#ifndef ONLINE_JUDGE 
  freopen("input.in", "r", stdin);
#endif
	cin.sync_with_stdio(0);
  for ( ; ~scanf("%d%d", &n, &m); ) {
		set<int> hs(Range(1, n+1));
		for (auto h: hs)
			cout << h << endl;
		vector<Log> logs;
		for (int i = 0; i < m; i++)
			logs.push_back(Log::FromIo());
  }
  return 0;
}
