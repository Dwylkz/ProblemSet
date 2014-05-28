#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> VI;
typedef long long LL;
const int N = 1e5+10;

struct Oper {
  int t, x, y;
  void input() {
    cin >> t >> x;
    if (t > 1) cin >> y;
  }
};

Oper os[N];
int m, n;
LL qs[N];

int main() {
#ifndef ONLINE_JUDGE 
  freopen("input.in", "r", stdin);
#endif
  cin.sync_with_stdio(0);
  for ( ; cin >> m; ) {
    for (int i = 0; i < m; i++) os[i].input();
    cin >> n;
    for (int i = 0; i < n; i++) cin >> qs[i];
    LL c = 0;
    VI s;
    int sp = 0, j = 0;;
    for (int i = 0; i < m; i++)
      if (os[i].t < 2) {
        while (j < n && qs[j] == c+1) {
          if (sp) putchar(' ');
          sp = 1;
          printf("%d", os[i].x);
          j++;
        }
        if (s.size() < N) s.push_back(os[i].x);
        c++;
      } else {
        while (j < n && qs[j] <= c+os[i].x*os[i].y) {
          if (sp) putchar(' ');
          sp = 1;
          printf("%d", s[(qs[j]-c-1)%os[i].x]);
          j++;
        }
        for (int j = 0; s.size() < N && j < os[i].x*os[i].y; j++)
          s.push_back(s[j%os[i].x]);
        c += os[i].x*os[i].y;
      }
    puts("");
  }
  return 0;
}
