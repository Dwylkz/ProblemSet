#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

string s;
int n[3], p[3];
long long r;

struct ingredient_t {
  int n, m, p;
};

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  cin.sync_with_stdio(0);
  for ( ; cin >> s; ) {
    cin >> n[0] >> n[1] >> n[2];
    cin >> p[0] >> p[1] >> p[2];
    cin >> r;
    int m[3] = {0};
    for (char c: s) m[c == 'B'? 0: c == 'S'? 1: 2]++;
    vector<ingredient_t> is;
    for (int i = 0; i < 3; i++)
      if (m[i]) is.push_back((ingredient_t){n[i], m[i], p[i]});
    long long result = 0;
    for ( ; ; ) {
      int is_empty = 1;
      for (int i = 0; i < is.size(); i++)
        if (is[i].n) is_empty = 0;
      if (is_empty) break;
      for (int i = 0; i < is.size(); i++)
        if (is[i].n < is[i].m) {
          r -= (is[i].m-is[i].n)*is[i].p;
          is[i].n = is[i].m;
        }
      if (r < 0) break;
      int delta = -1;
      for (int i = 0; i < is.size(); i++)
        if (!~delta || delta > is[i].n/is[i].m)
          delta = is[i].n/is[i].m;
      result += delta;
      for (int i = 0; i < is.size(); i++)
        is[i].n -= delta*is[i].m;
    }
    int cost = 0;
    for (int i = 0; i < 3; i++) cost += m[i]*p[i];
    if (r > 0) result += r/cost;
    cout << result << endl;
  }
  return 0;
}
