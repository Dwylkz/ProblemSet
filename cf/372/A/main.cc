#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 5e5+10;

int n, s[N];

int main() {
#ifndef ONLINE_JUDGE 
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d", &n); ) {
    for (int i = 0; i < n; i++) scanf("%d", s+i);
    sort(s, s+n);
    int result = n, r = n/2;
    for (int i = 0; i < n/2; i++) {
      while (r < n && s[i]*2 > s[r]) r++;
      if (r == n) break;
      result--;
      r++;
    }
    printf("%d\n", result);
  }
  return 0;
}
