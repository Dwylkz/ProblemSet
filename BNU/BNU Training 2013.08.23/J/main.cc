#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <deque>
using namespace std;
typedef long long LL;

LL n, h;

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%lld%lld", &n, &h); ) {
    deque<LL> ans;
    LL m = h+1;
    if (m*m <= n) {
      ans.push_back(m*m);
      if (m*m+m <= n) {
        ans.push_front(m*m+m);
        for (int i = 1; (m+i)*(m+i)+m <= n; i++)
          ans.push_front((m+i)*(m+i)+m);
      }
      if (m*m+m+m <= n) {
        ans.push_back(m*m+m+m);
        for (int i = 1; (m+i)*(m+i)+m+i+m <= n; i++)
          ans.push_back((m+i)*(m+i)+m+i+m);
      }
    }
    for (int i = 0; i < ans.size(); i++)
      printf("%lld%c", ans[i], i < ans.size()-1? ' ': '\n');
  }
  return 0;
}
