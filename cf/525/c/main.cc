#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

const int E = 4;

typedef long long LL;
typedef pair<int, int> PII;
typedef map<int, int> MII;

struct S {
  int k, a, b;
  S(int k, int a, int b): k(k), a(a), b(b) {}
  int Sum()
  {
    return a+b;
  }
  void Sub()
  {
    int d = 2, e = min(d, b);
    b -= e;
    d -= e;
    a -= d;
  }
  friend bool operator < (const S& lhs, const S& rhs)
  {
    return lhs.k > rhs.k;
  }
};

int n;

int main()
{
  scanf("%d", &n);
  MII m;
  for (int i = 0; i < n; i++) {
    int li;
    scanf("%d", &li);
    m[li]++;
  }
  LL ret = 0;
  vector<S> vs;
  for (auto& mi: m) {
    int cnt = mi.second/E;
    ret += 1ll*mi.first*mi.first*cnt;
    mi.second %= E;
    if (mi.second > 0) vs.push_back(S(mi.first, mi.second, 0));
  }
  reverse(vs.begin(), vs.end());
  set<S> ss;
  ss.insert(vs[0]);
  for (int i = 1; i < vs.size(); i++) {
    while (ss.size() && ss.begin()->Sum() == 0) ss.erase(ss.begin());
    if (ss.size() > 0) {
      if (vs[i].a > 1) {
        if (ss.size()) {
          ret += 1ll*vs[i].k*ss.begin()->k;
          ss.erase(ss.begin());
          vs[i].a -= 2;
        }
      }
      if (vs[i].a == 1) {
        if (vs[i-1].Sum() > 1) {
          ss.insert(vs[i-1]);
          vs[i-1].Sub();
        }
        if (vs[i-1].a > 0 && vs[i-1].k == vs[i].k+1) vs[i].b++;
      }
    }
  }
  cout << ret << endl;
  return 0;
}
