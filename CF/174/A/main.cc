#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef vector<int> VI;

int n;

int main() {
#ifndef ONLINE_JUDGE 
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d", &n); ) {
    VI as(1), ds(n+1);
    long long sum = 0;
    while (n--) {
      int t, a;
      scanf("%d", &t);
      if (t == 1) {
        int x;
        scanf("%d%d", &a, &x);
        sum += x*a;
        ds[a-1] += x;
      } else if (t == 2) {
        scanf("%d", &a);
        ds[as.size()] = 0;
        as.push_back(a);
        sum += a;
      } else if (t == 3 && as.size() > 1) {
        sum -= as.back()+ds[as.size()-1];
        as.pop_back();
        ds[as.size()-1] += ds[as.size()];
      }
      printf("%f\n", 1.*sum/as.size());
    }
  }
  return 0;
}
