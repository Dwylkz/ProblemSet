#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
const int N = 1e5+10;
typedef vector<int> VI;
typedef map<int, int> MII;

int n, a[N];

int main() {
#ifndef ONLINE_JUDGE 
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d", &n); ) {
    for (int i = 0; i < n; i++) scanf("%d", a+i);
    sort(a, a+n);
    MII m;
    for (int i = 1; i < n; i++)
      m[a[i]-a[i-1]]++;
    if (n == 1) {
      puts("-1");
    } else {
      VI b;
      if (n == 2) {
        int d = m.begin()->first;
        b.push_back(a[0]-d);
        if (d) {
          if (~d&1) b.push_back(a[0]+d/2);
          b.push_back(a[n-1]+d);
        }
      } else {
        if (m.size() > 2) {
        } else if (m.size() == 1) {
          int d = m.begin()->first;
          b.push_back(a[0]-d);
          if (d) b.push_back(a[n-1]+d);
        } else {
          int d1 = m.begin()->first, d2 = (++m.begin())->first;
          if (m[d2] == 1 && d2 == d1*2) {
            for (int i = 1; i < n; i++)
              if (a[i]-a[i-1] == d2) {
                b.push_back(a[i]-d1);
                break;
              }
          }
        }
      }
      printf("%d\n", b.size());
      for (int i = 0; i < b.size(); i++)
        printf("%d%c", b[i], i < b.size()-1? ' ': '\n');
    }
  }
  return 0;
}
